// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.

TEST(edge_test_max) {
    Matrix* mat = new Matrix;
    const int width = 3;
    const int height = 5;
    const int max_value = 99;
    Matrix_init(mat, width, height);
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            *Matrix_at(mat, row, col) = row * width + col;
        }
    }
    *Matrix_at(mat, 4, 2) = max_value;
    ASSERT_EQUAL(Matrix_max(mat), max_value);
    delete mat;
}
/*
TEST(test_print_basic) {
    Matrix* mat = new Matrix;
    const int width = 4;
    const int height = 4;
    Matrix_fill(mat, 1);
    //ASSERT_EQUAL(Matrix_print(???), ???);
    
}
 */

TEST (width_small) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 7);
    ASSERT_EQUAL(Matrix_width(mat), 3);
    delete mat;
}

TEST (height_small) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 3, 7);
    ASSERT_EQUAL(Matrix_height(mat), 7);
    delete mat;
}

TEST(row_small) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 4, 6);
    int* equal = Matrix_at(mat, 2, 2);
    ASSERT_EQUAL(Matrix_row(mat, equal), 2);
    delete mat;
}

TEST(col_small) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 4, 6);
    int* equal = Matrix_at(mat, 1, 3);    //you had 1,4 here originally, you have to remember
    ASSERT_EQUAL(Matrix_column(mat, equal), 3);  // its actually 0-3 cuz its indexed in the arr
    delete mat;
    
}

TEST(at_small) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 7, 7);
    Matrix_fill(mat, 4);
    ASSERT_EQUAL(*Matrix_at(mat, 2, 2), 4);
    delete mat;
    
}

TEST(print_small) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 1, 1);

    *Matrix_at(mat, 0, 0) = 42;
    ostringstream expected;
    expected << "1 1\n"
             << "42 \n";
    ostringstream actual;
    Matrix_print(mat, actual);
    ASSERT_EQUAL(expected.str(), actual.str());

    delete mat;
}

TEST(fill_small) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 10, 10);
    Matrix_fill(mat, 7);
    ASSERT_EQUAL(*Matrix_at(mat, 4, 4), *Matrix_at(mat, 1, 3));
    delete mat;
}

TEST(fill_border_small) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 7, 8);
    Matrix_fill_border(mat, 7);
    ASSERT_EQUAL(*Matrix_at(mat, 3, 6), 7);
    delete mat;
}

TEST(max_small) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 5, 5);
    Matrix_fill(mat, 1);
    //int test_data = *Matrix_at(mat, 1, 1);
    *Matrix_at(mat, 4, 3) = 2;
   // int test_data2 =  *Matrix_at(mat, 4, 3);
   // int max = Matrix_max(mat);
    ASSERT_EQUAL(Matrix_max(mat), 2);
    delete mat;
}

TEST(col_min_row) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 3);
    Matrix_fill(mat, 2);
    //backwards??
    *Matrix_at(mat, 0, 0) = 1;
    *Matrix_at(mat, 1, 0) = 7;
    //test sample to make sure _at is working
    //int test = *Matrix_at(mat, 0, 1);
    *Matrix_at(mat, 2, 0) = 0;
    Matrix_column_of_min_value_in_row(mat, 0, 0, 2);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 2), 0);
    delete mat;
}

TEST(min_in_row) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 3);
    Matrix_fill(mat, 4);
    *Matrix_at(mat, 0, 0) = 1;
    *Matrix_at(mat, 0, 1) = 7;
    //test sample to make sure _at is working
    //int test = *Matrix_at(mat, 0, 1);
    *Matrix_at(mat, 0, 2) = 0;
    Matrix_min_value_in_row(mat, 0, 0, 2);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 3), 0);   //originally you had 2 here, doesnt work because the last column parameter is exclusive
    delete mat;
}

TEST(fill_border_entire) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 7, 8);
    Matrix_fill_border(mat, 7);
    
    for (int i = 0; i < Matrix_width(mat); i++) {
        for (int j = 0; j < Matrix_width(mat); j++) {
            ASSERT_EQUAL(*Matrix_at(mat, 0, i), *Matrix_at(mat, 0, j));
        }
    }
    
    for (int i = 0; i < Matrix_width(mat); i++) {
        for (int j = 0; j < Matrix_width(mat); j++) {
            ASSERT_EQUAL(*Matrix_at(mat, Matrix_height(mat) - 1, i),
                         *Matrix_at(mat, Matrix_height(mat) - 1, j));
        }
    }
    
    for (int i = 0; i < Matrix_height(mat); i++) {
        for (int j = 0; j < Matrix_height(mat); j++) {
            ASSERT_EQUAL(*Matrix_at(mat, i, 0),
                         *Matrix_at(mat, i, 0));
        }
    }
    
    for (int i = 0; i < Matrix_height(mat); i++) {
        for (int j = 0; j < Matrix_height(mat); j++) {
            ASSERT_EQUAL(*Matrix_at(mat, i, Matrix_width(mat) - 1),
                         *Matrix_at(mat, j, Matrix_width(mat) - 1));
        }
    }
    delete mat;
}

TEST(fill_large) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 100, 100);
    Matrix_fill(mat, 21);
    ASSERT_EQUAL(*Matrix_at(mat, 4, 23), *Matrix_at(mat, 72, 84));
    delete mat;
}

TEST(max_large) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 55, 87);
    Matrix_fill(mat, 2);
    //int test_data = *Matrix_at(mat, 1, 1);
    *Matrix_at(mat, 21, 4) = 9;
   // int test_data2 =  *Matrix_at(mat, 4, 3);
   // int max = Matrix_max(mat);
    ASSERT_EQUAL(Matrix_max(mat), 9);
    delete mat;
}
    
TEST(at_large) {
    Matrix* mat = new Matrix;
    Matrix_init(mat, 87, 97);
    Matrix_fill(mat, 8);
    ASSERT_EQUAL(*Matrix_at(mat, 6, 7), 8);
    delete mat;
    
}

TEST(min_value_in_row_with_col) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 4, 4);
    *Matrix_at(mat, 0, 0) = 1;
    *Matrix_at(mat, 0, 1) = 2;
    *Matrix_at(mat, 0, 2) = 3;
    *Matrix_at(mat, 0, 3) = 0;
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, 3), 1);
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 0, 0, 3), 0);
    delete mat;
    
}

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
