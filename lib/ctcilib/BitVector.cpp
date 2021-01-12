#include "BitVector.h"

const size_t DATA_SIZE = 32;

class BitVector {
private:
    size_t length;
    std::vector< size_t > vector;

public:
    BitVector(size_t length) {
        this->length = length;
        if (length % DATA_SIZE == 0) {
            vector = std::vector< size_t >(length / DATA_SIZE);
        } else {
            vector = std::vector< size_t >(length / DATA_SIZE + 1);
        }
    }

    size_t length() {
        return length;
    }

    bool get(size_t i) {
        size_t b = vector[i / DATA_SIZE];
        size_t bit_index = i % DATA_SIZE;

        if (((b >> bit_index) & 1) == 1) {
            return true;
        } else {
            return false;
        }
    }

    void print() {
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

    void set(size_t i, bool flag) {
        if (i >= 0 && i < length) {
            size_t mask = ~(1 << i);
            size_t b = vector[i / DATA_SIZE] & mask;
            if (flag) {
                vector[i / DATA_SIZE] = b | (1 << i);
            } else {
                vector[i / DATA_SIZE] = b;
            }
        }
    }
};