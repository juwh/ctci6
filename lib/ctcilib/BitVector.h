#ifndef BITVECTOR_H_
#define BITVECTOR_H_

#include <iostream>
#include <vector>

namespace ctcilib {
    class BitVector {
    private:
        size_t length_{};
        std::vector< size_t > vector_;
    public:
        BitVector(size_t length);
        size_t length() const;
        bool get(size_t i) const;
        void print() const;
        void set(size_t i, bool flag);
    };
}
#endif // BIT_VECTOR_H_