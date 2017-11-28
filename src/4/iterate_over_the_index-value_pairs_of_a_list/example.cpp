/// example.cpp
///
/// Example of iterating over lines of a file with an extra lineno attribute

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

    std::tuple<std::size_t, std::string&> operator*() {
        return std::tuple<std::size_t, std::string&>(m_lineno, m_line);
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
        } else {
            m_done = true;
        }
    }

protected:
    std::ifstream& m_fs;
    bool m_done;
    std::string m_line;
    std::size_t m_lineno = 0;
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

std::vector<std::string> split(const std::string& str, char delim = ' ') {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        result.emplace_back(std::move(token));
    }
    return result;
}

void parse_data(const char* path) {
    std::ifstream file(path);
    for (auto[lineno, line] : enumerate(file)) {
        fmt::print("{} {}\n", lineno, line);
        auto fields = split(line);
        try {
            std::stoi(fields[1]);
        } catch (std::invalid_argument& e) {
            fmt::print("Line {}: Parse error: {}\n", lineno, e.what());
        }
    }
}

int main(int argc, char* argv[]) {
    parse_data(argv[1]);
    return 0;
}
