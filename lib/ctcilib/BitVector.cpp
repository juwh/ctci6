//
// Created by William Ju on 10/10/17.
//

#include <iostream>

const int DATA_SIZE = 32;

class BitVector {
private:
    int length;
    int* vector;

public:
    BitVector(int length) {
        this.length = length;
        if (length % DATA_SIZE == 0) {
            vector = new int[length / DATA_SIZE];
        } else {
            vector = new int[length / DATA_SIZE + 1];
        }
    }

    int length() {
        return length;
    }

    bool get(int i) {
        int b = vector[i / DATA_SIZE];
        int bit_index = i % DATA_SIZE;

        if (((b >> bit_index) & 1) == 1) {
            return true;
        } else {
            return false;
        }
    }

    void print() {
        for (int k : vector) {
            for (int i = 0; i < DATA_SIZE; i++) {
                if ((k >> i & 1) == 1) {
                    std::cout << 1;
                } else {
                    std::cout << 0;
                }
            }
            std::cout << std::endl;
        }
    }

    void set(int i, bool flag) {
        if (i >= 0 && i < length) {
            int mask = ~(1 << i);
            int b = vector[i / DATA_SIZE] & mask;
            if (flag) {
                vector[i / DATA_SIZE] = b | (1 << i);
            } else {
                vector[i / DATA_SIZE] = b;
            }
        }
    }
};