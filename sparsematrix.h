#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>

template <typename T>
class SparseMatrix {
public:
    SparseMatrix(int, int);
    SparseMatrix(const SparseMatrix<T>&);
    SparseMatrix(SparseMatrix<T>&&) noexcept;
    ~SparseMatrix();

    SparseMatrix& operator=(const SparseMatrix<T>&);
    SparseMatrix operator=(SparseMatrix<T>&&) noexcept;

    void insert(int, int, T);
    SparseMatrix<T> add(const SparseMatrix<T>&) const;
    void display() const;

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