#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>

template <typename T>
class SparseMatrix {
public:
private:
    class Node {
    public:
        int position_row {};
        int position_column {};
        T value {};
        Node* next {};

        Node(int _row, int _column, T _value)
            : position_row { _row }
            , position_column { _column }
            , value { _value }
            , next { nullptr }
        {
        }
    };
};

#include "sparsematrix.hpp"

#endif