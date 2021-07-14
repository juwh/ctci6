#include "BitVector.h"
using namespace ctcilib;

const size_t kDataSize = 32;

BitVector::BitVector(size_t length) : length_{length} {
    if (length % kDataSize == 0) {
        vector_ = std::vector< size_t >(length / kDataSize);
    } else {
        vector_ = std::vector< size_t >(length / kDataSize + 1);
    }
}

size_t BitVector::length() const {
    return length_;
}

bool BitVector::get(size_t i) const {
    size_t b {vector_[i / kDataSize]};
    size_t bit_index {i % kDataSize};

    return ((b >> bit_index) & 1) == 1;
}

void BitVector::print() const {
    for (size_t k : vector_) {
        for (size_t i = 0; i < kDataSize; i++) {
            if ((k >> i & 1) == 1) {
                std::cout << 1;
            } else {
                std::cout << 0;
            }
        }
        std::cout << std::endl;
    }
}

void BitVector::set(size_t i, bool flag) {
    if (i >= 0 && i < length_) {
        size_t mask {~((size_t)1 << i)};
        size_t b = vector_[i / kDataSize] & mask;
        if (flag) {
            vector_[i / kDataSize] = b | (1 << i);
        } else {
            vector_[i / kDataSize] = b;
        }
    }
}