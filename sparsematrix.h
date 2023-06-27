#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>

template <typename T>
class SparseMatrix {
public:
    SparseMatrix(int, int);

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
    Node* head {};
    int matrix_row {};
    int matrix_column {};
};

#include "sparsematrix.hpp"

#endif