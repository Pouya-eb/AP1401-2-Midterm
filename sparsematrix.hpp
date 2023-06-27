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
template <typename T>
SparseMatrix<T>& SparseMatrix<T>::operator=(const SparseMatrix<T>& other)
{
    SparseMatrix<T> copy { other };
    std::swap(head, copy.head);
    return *this;
}
template <typename T>
SparseMatrix<T> SparseMatrix<T>::operator=(SparseMatrix<T>&& other) noexcept
{
    matrix_row = other.matrix_row;
    matrix_column = other.matrix_column;
    head = other.head;
    other.head = nullptr;
    return *this;
}
template <typename T>
void SparseMatrix<T>::insert(int row, int column, T value)
{
    Node* copy { head };

    if (head == nullptr) {
        Node* node { new Node { row, column, value } };
        node->next = head;
        head = node;
    } else {
        while (copy != nullptr) {
            if (copy->position_row == row && copy->position_column == column)
                copy->value = value;
            else {
                Node* node { new Node { row, column, value } };
                node->next = head;
                head = node;
            }
            copy = copy->next;
        }
    }
}
template <typename T>
SparseMatrix<T> SparseMatrix<T>::add(const SparseMatrix<T>& other) const
{
    if (matrix_row != other.matrix_row || matrix_column != other.matrix_column) {
        std::logic_error e { "Dimentions are not compatitable" };
        throw e;
    }
    SparseMatrix copy { *this };
    Node* current_other { other.head };
    std::map<std::pair<int, int>, T> elements_others;
    while (current_other != nullptr) {
        elements_others[{ current_other->position_row, current_other->position_column }] = current_other->value;
        current_other = current_other->next;
    }
    Node* current { copy.head };
    std::map<std::pair<int, int>, T> elements;
    while (current != nullptr) {
        elements[{ current->position_row, current->position_column }] = current->value;
        current = current->next;
    }

    for (auto& [pos, value] : elements) {
        T& temp { value };
        if (elements_others.contains(pos)) {
            temp += elements_others[pos];
            copy.insert(pos.first, pos.second, temp);
        } else
            copy.insert(pos.first, pos.second, temp);
    }
    return copy;
}
template <typename T>
void SparseMatrix<T>::display() const
{
    Node* current { head };
    std::map<std::pair<int, int>, T> elements;
    while (current != nullptr) {
        elements[{ current->position_row, current->position_column }] = current->value;
        current = current->next;
    }
    for (int i {}; i < matrix_row; i++) {
        for (int j {}; j < matrix_column; j++) {
            if (elements[{ i, j }])
                std::cout << elements[{ i, j }] << " ";
            else
                std::cout << 0 << " ";
        }
        std::cout << std::endl;
    }
}
