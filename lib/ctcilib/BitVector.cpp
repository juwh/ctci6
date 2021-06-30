#include "BitVector.h"
using namespace ctcilib;

const size_t DATA_SIZE = 32;

BitVector::BitVector(size_t length) : m_length{length} {
    if (length % DATA_SIZE == 0) {
        vector = std::vector< size_t >(length / DATA_SIZE);
    } else {
        vector = std::vector< size_t >(length / DATA_SIZE + 1);
    }
}

size_t BitVector::length() const {
    return m_length;
}

bool BitVector::get(size_t i) const {
    size_t b {vector[i / DATA_SIZE]};
    size_t bit_index {i % DATA_SIZE};

    return ((b >> bit_index) & 1) == 1;
}

void BitVector::print() const {
    for (size_t k : vector) {
        for (size_t i = 0; i < DATA_SIZE; i++) {
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
    if (i >= 0 && i < m_length) {
        size_t mask {~(1 << i)};
        size_t b = vector[i / DATA_SIZE] & mask;
        if (flag) {
            vector[i / DATA_SIZE] = b | (1 << i);
        } else {
            vector[i / DATA_SIZE] = b;
        }
    }
}