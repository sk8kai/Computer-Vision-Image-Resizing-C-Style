// Project UID af1f95f547e44c8ea88730dfb185559d
#include <iostream>
#include <cassert>
#include "Matrix.h"
using namespace std;

// REQUIRES: mat points to a Matrix
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *mat
// EFFECTS:  Initializes *mat as a Matrix with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Matrix_init(Matrix* mat, int width, int height) {
    (mat -> width) = width;
    (mat -> height) = height;
    // do i need to initialize the data?
    // mat -> data[height * width];
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: os
// EFFECTS:  First, prints the width and height for the Matrix to os:
//             WIDTH [space] HEIGHT [newline]
//           Then prints the rows of the Matrix to os with one row per line.
//           Each element is followed by a space and each row is followed
//           by a newline. This means there will be an "extra" space at
//           the end of each line.
void Matrix_print(const Matrix* mat, std::ostream& os) {
    os << mat->width << " " << mat->height << endl;
        int startIndex = 0;
        for (int rowCount = 0; rowCount < mat->height; rowCount++) {
            for(int i = 0; i < mat->width; i++) {
                os << mat->data[startIndex + i] << " ";
            }
            os << endl;
            startIndex = rowCount * mat->width;
        }
}

// REQUIRES: mat points to an valid Matrix
// EFFECTS:  Returns the width of the Matrix.
int Matrix_width(const Matrix* mat) {
    int width = mat -> width;
    return width;
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the height of the Matrix.
int Matrix_height(const Matrix* mat) {
    int height = mat -> height;
    return height;
}

// REQUIRES: mat points to a valid Matrix
//           ptr points to an element in the Matrix
// EFFECTS:  Returns the row of the element pointed to by ptr.
int Matrix_row(const Matrix* mat, const int* ptr) {
    int row = Matrix_height(mat);
    int col = Matrix_width(mat);
    int rowFind = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (ptr == Matrix_at(mat, i, j)) {
                return rowFind;
            }
        }
        rowFind++;
    }
    
    return rowFind;
}

// REQUIRES: mat points to a valid Matrix
//           ptr point to an element in the Matrix
// EFFECTS:  Returns the column of the element pointed to by ptr.
int Matrix_column(const Matrix* mat, const int* ptr) {
    int row = Matrix_height(mat);
    int col = Matrix_width(mat);
    int colFind = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (ptr == Matrix_at(mat, i, j)) {
                return colFind;
            }
            else {
                colFind++;
            }
        }
        colFind = 0;
    }
    
    return colFind;
}


// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// MODIFIES: (The returned pointer may be used to modify an
//            element in the Matrix.)
// EFFECTS:  Returns a pointer to the element in the Matrix
//           at the given row and column.
int* Matrix_at(Matrix* mat, int row, int column) {
    int location = (row * mat->width) + column;
    int *ptr = &(mat->data[location]);
    return ptr;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column && column < Matrix_width(mat)
//
// EFFECTS:  Returns a pointer-to-const to the element in
//           the Matrix at the given row and column.
const int* Matrix_at(const Matrix* mat, int row, int column) {
    int location = (row * mat->width) + column;
    int const *ptr = &(mat->data[location]);
    return ptr;
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element of the Matrix to the given value.
void Matrix_fill(Matrix* mat, int value) {
    int row = Matrix_height(mat);
    int col = Matrix_width(mat);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            *Matrix_at(mat, i, j) = value;
        }
    }
}

// REQUIRES: mat points to a valid Matrix
// MODIFIES: *mat
// EFFECTS:  Sets each element on the border of the Matrix to
//           the given value. These are all elements in the first/last
//           row or the first/last column.
void Matrix_fill_border(Matrix* mat, int value) {
    int col = mat -> width;
    int row = mat -> height;
    for (int i = 0; i < row; i++) {
        *Matrix_at (mat, i, 0) = value;
        *Matrix_at (mat, i, col - 1) = value;
    }
    
    for (int i = 0; i < col; i++) {
        *Matrix_at (mat, 0, i) = value;
        *Matrix_at (mat, row - 1, i) = value;
    }
}

// REQUIRES: mat points to a valid Matrix
// EFFECTS:  Returns the value of the maximum element in the Matrix
int Matrix_max(const Matrix* mat) {
    int currentMax = mat->data[0];
    int row = Matrix_height(mat);
    int col = Matrix_width(mat);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (*Matrix_at(mat, i, j) > currentMax) {
                currentMax = *Matrix_at(mat, i, j);
            }
        }
    }
    return currentMax;
}



// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the column of the element with the minimal value
//           in a particular region. The region is defined as elements
//           in the given row and between column_start (inclusive) and
//           column_end (exclusive).
//           If multiple elements are minimal, returns the column of
//           the leftmost one.
int Matrix_column_of_min_value_in_row(const Matrix* mat, int row,
                                      int column_start, int column_end) {
    int smallest = *Matrix_at(mat, row, column_start);
    int colSmallest = column_start;
    for (int j = column_start; j < column_end; j++) {
        if (smallest > *Matrix_at(mat, row, j)) {
            smallest = *Matrix_at(mat, row, j);
            colSmallest = j;
        }
    }
    return colSmallest;
}

// REQUIRES: mat points to a valid Matrix
//           0 <= row && row < Matrix_height(mat)
//           0 <= column_start && column_end <= Matrix_width(mat)
//           column_start < column_end
// EFFECTS:  Returns the minimal value in a particular region. The region
//           is defined as elements in the given row and between
//           column_start (inclusive) and column_end (exclusive).
int Matrix_min_value_in_row(const Matrix* mat, int row,
                            int column_start, int column_end) {
    int startRowIndex = mat->width * row;
       int startIndex = startRowIndex + column_start;
       int endIndex = startRowIndex + column_end;
       int min = mat->data[startIndex];
       for (int i = startIndex; i < endIndex; i++) {
           if (mat->data[i] < min) {
               min = mat->data[i];
           }
       }
       return min;
}
