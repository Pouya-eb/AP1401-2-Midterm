#include "SparseMatrix.h"

template <typename T>
SparseMatrix<T>::SparseMatrix(int rows, int columns)
    : matrix_row { rows }
    , matrix_column { columns }
{
}