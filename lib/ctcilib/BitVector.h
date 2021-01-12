#ifndef BITVECTOR_H_
#define BITVECTOR_H_

#include <iostream>
#include <vector>

class BitVector {
private:
    size_t length;
    std::vector< size_t > vector;
public:
    BitVector(size_t length);
    size_t length();
    bool get(size_t i);
    void print();
    void set(size_t i, bool flag);
};

#endif // BIT_VECTOR_H_