#include "SparseMatrix.h"

template <typename T>
SparseMatrix<T>::SparseMatrix(int rows, int columns)
    : matrix_row { rows }
    , matrix_column { columns }
{
}
template <typename T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix<T>& other)
{
    head = new Node { *other.head };
    Node* _head { head };
    Node* __head { other.head };
    while ((__head = __head->next)) {
        _head->next = new Node { *__head };
        _head = _head->next;
    }
    matrix_row = other.matrix_row;
    matrix_column = other.matrix_column;
}
template <typename T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T>&& other) noexcept
{
    matrix_row = other.matrix_row;
    matrix_column = other.matrix_column;
    head = other.head;
    other.head = nullptr;
}
template <typename T>
SparseMatrix<T>::~SparseMatrix()
{
    while (head) {
        Node* next { head->next };
        delete head;
        head = next;
    }
}