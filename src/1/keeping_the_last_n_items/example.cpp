/// example.cpp
///

#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>

#include <fmt/format.h>
#include <range/v3/all.hpp>

// A simple implementation of Fstream iterator keeping line and lineno.
class FstreamIterator : public std::iterator<std::forward_iterator_tag, std::string, ptrdiff_t,
                                             std::string*, std::string&> {
public:
    FstreamIterator(std::ifstream& fs, std::size_t maxlen = 3, bool done = false)
        : m_fs(fs)
        , m_maxlen(maxlen)
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
        return get_done() == other.get_done();
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

    decltype(auto) operator*() {
        return std::tuple<std::string&, std::deque<std::string>&>{m_line, m_preflines};
    }
    std::size_t get_lineno() const {
        return m_lineno;
    }
    std::size_t get_done() const {
        return m_done;
    }
    void read() {
        if (m_done) {
            return;
        }
        if (std::getline(m_fs, m_line)) {
            ++m_lineno;
            m_preflines.emplace_back(m_line);
            if (m_preflines.size() > m_maxlen) {
                m_preflines.pop_front();
            }
        } else {
            m_done = true;
        }
    }
    const std::deque<std::string>& preflines() const {
        return m_preflines;
    }

protected:
    std::ifstream& m_fs;
    std::size_t m_maxlen = 3;
    bool m_done;
    std::string m_line;
    std::size_t m_lineno = 0;
    std::deque<std::string> m_preflines;
};

class File {
public:
    File(std::ifstream& fs, std::size_t maxlen)
        : m_fs(fs)
        , m_maxlen(maxlen) {
    }
    FstreamIterator begin() {
        return FstreamIterator(m_fs, m_maxlen);
    }
    FstreamIterator end() {
        return FstreamIterator(m_fs, m_maxlen, true);
    }

private:
    std::ifstream& m_fs;
    std::size_t m_maxlen;
};

File search(std::ifstream& ifs, std::deque<std::string>& preflines, const std::string& pattern,
            std::size_t history = 3) {
    return File{ifs, history};
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::deque<std::string> prevlines;
    std::string pattern = "python";

    auto rv = search(file, prevlines, pattern, 5);
    for (auto tpl : rv) {
        auto & [ line, plines ] = tpl;
        if (line.find(pattern) == std::string::npos)
            continue;
        for (auto& pline : plines)
            fmt::print("{}\n", pline);
        fmt::print("--------------------\n");
    }

    return 0;
}
