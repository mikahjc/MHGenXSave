// memstream implementation by tuttlem
// http://tuttlem.github.io/2014/08/18/getting-istream-to-work-off-a-byte-array.html

#include <istream>

class membuf : public std::basic_streambuf<char> {
public:
  membuf(const uint8_t *p, size_t l) {
    setg((char*)p, (char*)p, (char*)p + l);
  }
};

class memstream : public std::istream {
public:
  memstream(const uint8_t *p, size_t l) :
    std::istream(&_buffer),
    _buffer(p, l) {
    rdbuf(&_buffer);
  }

private:
  membuf _buffer;
};