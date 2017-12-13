/// example.cpp
///
/// Example of a generator with extra state that can be
/// accessed.   Simply define as a class!

#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include <fmt/format.h>

// A simple implementation of Fstream iterator keeping line and lineno.
class FstreamIterator : public std::iterator<std::forward_iterator_tag, std::string, ptrdiff_t,
                                             std::string*, std::string&> {
public:
    FstreamIterator(std::ifstream& fs, bool done = false)
        : m_fs(fs)
        , m_done(done) {
        ++(*this);
    }
    ~FstreamIterator() {
    }

    FstreamIterator(const FstreamIterator& iterator) = default;
    FstreamIterator& operator=(const FstreamIterator& iterator) = default;

    operator bool() const {
        return !m_done;
    }

    bool operator==(const FstreamIterator& other) const {
        return this->get_done() == other.get_done() || this->get_lineno() == other.get_lineno();
    }
    bool operator!=(const FstreamIterator& other) const {
        return !(*this == other);
    }

    FstreamIterator& operator+=(const ptrdiff_t& movement) {
        for (std::size_t n = 0; !m_done || n < movement; ++n) {
            read();
        }
        return (*this);
    }
    FstreamIterator& operator++() {
        read();
        return (*this);
    }

    std::string& operator*() {
        return m_line;
    }

    std::size_t get_done() const {
        return m_done;
    }
    std::size_t get_lineno() const {
        return m_lineno;
    }
    void read() {
        if (m_done) {
            return;
        }
        if (std::getline(m_fs, m_line)) {
            ++m_lineno;
            m_history.emplace_back(m_lineno, m_line);
            if (m_history.size() > m_maxlen) {
                m_history.pop_front();
            }
        } else {
            m_done = true;
        }
    }
    const std::deque<std::tuple<std::size_t, std::string>>& history() const {
        return m_history;
    }

protected:
    std::ifstream& m_fs;
    bool m_done;
    std::string m_line;
    std::size_t m_lineno = 0;
    std::size_t m_maxlen = 3;
    std::deque<std::tuple<std::size_t, std::string>> m_history;
};

class File {
public:
    File(std::ifstream& fs)
        : m_fs(fs) {
    }
    FstreamIterator begin() {
        return FstreamIterator(m_fs);
    }
    FstreamIterator end() {
        return FstreamIterator(m_fs, true);
    }

private:
    std::ifstream& m_fs;
};

File enumerate(std::ifstream& fs) {
    return File(fs);
}

int main(int argc, char* argv[]) {
    std::ifstream ifs(argv[1]);
    File file(ifs);
    for (auto it = file.begin(); it != file.end(); ++it) {
        if ((*it).find("python") != std::string::npos) {
            for (auto & [ lineno, line ] : it.history()) {
                fmt::print("{}:{}\n", lineno, line);
            }
        }
    }
    return 0;
}
