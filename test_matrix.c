//Matthew Ferine ID: 116961912

#include <criterion/criterion.h>
#include "matrix.h"

/*Test(SparseMatrix, simple_sparse)
{
    int D[2] = {3,3};

    int M[3][3] = {
        {1,0,0},
        {0,2,0},
        {0,0,3}
    };

    int S[3][3];

    int result = SparseMatrix(D,M,S);

    cr_assert_eq(result,3);
}
*/
Test(SparseMatrix, test_case_1){
    int D[2] = {3,6};
    int M[3][6] = {
        {0,0,1,0,0,2},
        {0,0,3,0,0,4},
        {0,0,0,0,0,0}
    };
    int S[3][6];
    int result = SparseMatrix(D,M,S);
    cr_assert_eq(result,4);
} 
Test(SparseMatrix, test_case_2)
{
    int D[2] = {3, 3};
    int M[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int S[3][3];
    int result = SparseMatrix(D, M, S);
    cr_assert_eq(result, 0);
}
Test(SparseMatrix, test_case_3)
{
    int D[2] = {3, 3};
    int M[3][3] = {
        {0, 0, 0},
        {0, 9, 0},
        {0, 0, 0}
    };
    int S[3][3];
    int result = SparseMatrix(D, M, S);
    cr_assert_eq(result, 1);
}
Test(SparseMatrix, test_case_4)
{
    int D[2] = {3, 3};
    int M[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int S[3][3];
    int result = SparseMatrix(D, M, S);
    cr_assert_eq(result, -1);
}
Test(SparseMatrix, test_case_5)
{
    int D[2] = {2, 4};
    int M[2][4] = {
        {1, 0, 0, 0},
        {0, 0, 2, 0}
    };
    int S[3][4];
    int result = SparseMatrix(D, M, S);
    cr_assert_eq(result, 2);
}
Test(SparseMatrix, test_case_6)
{
    int D[2] = {2, 2};
    int M[2][2] = {
        {0, 0},
        {0, 0}
    };
    int S[2][2];
    int result = SparseMatrix(D, M, S);
    cr_assert_eq(result, 0);
}
Test(SparseMatrix, test_case_7)
{
    int D[2] = {3, 3};
    int M[3][3] = {
        {-1,  0, 0},
        { 0, -2, 0},
        { 0,  0, 0}
    };
    int S[3][3];
    int result = SparseMatrix(D, M, S);
    cr_assert_eq(result, 2);
}
Test(SparseMatrix, test_case_8)
{
    int D[2] = {2, 2};
    int M[2][2] = {
        {0, 1},
        {0, 1}
    };
    int S[2][2];
    int result = SparseMatrix(D, M, S);
    cr_assert_eq(result, 2);
}
Test(SparseMatrix, test_case_9)
{
    int D[2] = {3, 3};
    int M[3][3] = {
        { 1,  0, 0},
        { 0,  2, 0},
        { 0,  3, 4}
    };
    int S[3][3];
    int result = SparseMatrix(D, M, S);
    cr_assert_eq(result, -1);
}
Test(SparseMatrix, test_case_10)
{
    int D[2] = {3, 3};
    int M[3][3] = {
        {0, 0, 9},
        {0, 3, 0},
        {5, 0, 0}
    };
    int S[3][3];
    int result = SparseMatrix(D, M, S);
    cr_assert_eq(result, 3);
}
/*Test(HadamardProduct, compatible)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {2,2},
        {2,2}
    };

    int A[2][2];

    int r = HadamardProduct(D,M,N,A);

    cr_assert_eq(r,1);
}
*/
Test(HadamardProduct, test_case_1)
{
    int D[6] = {3,3, 3,3, 3,3};
    int M[3][3] = {{9,8,7}, {6,5,4}, {3,2,1}};
    int N[3][3] = {{2,2,2},{2,2,2},{2,2,2}};
    int A[3][3];
    int r = HadamardProduct(D, M, N, A);
    cr_assert_eq(r, 1);
}

Test(HadamardProduct, test_case_2)
{
    int D[6] = {2,2, 3,3, 2,2};
    int M[2][2] = {{1,3},{5,7}};
    int N[3][3] = {{1,0,1},{3,1,0},{5,0,1}};
    int A[2][2];
    int r = HadamardProduct(D, M, N, A);
    cr_assert_eq(r, -1);
}
Test(HadamardProduct, test_case_3)
{
    int D[6] = {3,3, 2,2, 1,1};
    int M[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int N[2][2] = {{10,2},{5,1}};
    int A[1][1];
    int r = HadamardProduct(D, M, N, A);
    cr_assert_eq(r, -2);
}

Test(HadamardProduct, test_case_4)
{
    int D[6] = {2,2, 2,2, 3,3};
    int M[2][2] = {{1,2},{3,4}};
    int N[2][2] = {{2,2},{2,2}};
    int A[3][3];
    int r = HadamardProduct(D, M, N, A);
    cr_assert_eq(r, 2);
}

Test(HadamardProduct, test_case_5)
{
    int D[6] = {3,3, 3,3, 2,2};
    int M[3][3] = {{1,0,0},{3,0,0},{2,0,0}};
    int N[3][3] = {{1,0,0},{2,2,0},{4,0,1}};
    int A[2][2];
    int r = HadamardProduct(D, M, N, A);
    cr_assert_eq(r, -3);
}

Test(HadamardProduct, test_case_6)
{
    int D[6] = {2,2, 2,2, 2,2};
    int M[2][2] = {{0,0},{0,0}};
    int N[2][2] = {{5,6},{7,8}};
    int A[2][2];
    int r = HadamardProduct(D, M, N, A);
    cr_assert_eq(r, 1);
}

Test(HadamardProduct, test_case_7)
{
    int D[6] = {1,1, 1,1, 1,1};
    int M[1][1] = {{7}};
    int N[1][1] = {{3}};
    int A[1][1];
    int r = HadamardProduct(D, M, N, A);
    cr_assert_eq(r, 1);
}
Test(HadamardProduct, test_case_8)
{
    int D[6] = {2,2, 2,2, 2,2};
    int M[2][2] = {{-1, 2},{-3, 4}};
    int N[2][2] = {{ -2, 3},{ 2, -2}};
    int A[2][2];
    int r = HadamardProduct(D, M, N, A);
    cr_assert_eq(r, 1);

}
Test(HadamardProduct, test_case_9)
{
    int D[6] = {2,3, 2,3, 2,3};
    int M[2][3] = {{1,2,3},{4,5,6}};
    int N[2][3] = {{3,3,3},{5,0,5}};
    int A[2][3];
    int r = HadamardProduct(D, M, N, A);
    cr_assert_eq(r, 1);
}
Test(HadamardProduct, test_case_10)
{
    int D[6] = {3,3, 3,2, 3,3};
    int M[3][3] = {{1,2},{3,4}};
    int N[3][2] = {{1,1},{1,1}};
    int A[3][3];
    int r = HadamardProduct(D, M, N, A);
    cr_assert_eq(r, -1);
}

/*Test(Multiplication, simple_case)
{
    int D[6] = {2,2,2,2,2,2};

    int M[2][2] = {
        {1,2},
        {3,4}
    };

    int N[2][2] = {
        {5,6},
        {7,8}
    };

    int A[2][2];

    int r = Multiplication(D,M,N,A);

    cr_assert_eq(r,1);
}
*/
Test(Multiplication, test_case_1)
{
    int D[6] = {3,3, 3,3, 3,3};
    int M[3][3] = {{9,8,7},{6,5,4}, {3,2,1}};
    int N[3][3] = {{2,2,2},{2,2,2},{2,2,2}};
    int A[3][3];
    int r = Multiplication(D, M, N, A);

    cr_assert_eq(r, 1);
}
Test(Multiplication, test_case_2)
{
    int D[6] = {2,2, 3,3, 4,4};
    int M[2][2] = {{1,3},{5,7}};
    int N[3][3] = {{1,0,1},{3,1,0},{5,0,1}};
    int A[4][4];
    int r = Multiplication(D, M, N, A);
    cr_assert_eq(r, -1);
}
Test(Multiplication, test_case_3)
{
    int D[6] = {3,3, 2,2, 1,1};
    int M[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int N[2][2] = {{10,2},{5,1}};
    int A[1][1];
    int r = Multiplication(D, M, N, A);
    cr_assert_eq(r, -2);
}
Test(Multiplication, test_case_4)
{
    int D[6] = {2,2, 2,2, 3,3};
    int M[2][2] = {{1,2},{3,4}};
    int N[2][2] = {{2,2},{2,2}};
    int A[3][3];
    int r = Multiplication(D, M, N, A);
    cr_assert_eq(r, 2);
}
Test(Multiplication, test_case_5)
{
    int D[6] = {3,3, 3,3, 2,2};
    int M[3][3] = {{1,0,0},{3,0,0},{2,0,0}};
    int N[3][3] = {{1,0,0},{2,2,0},{4,0,1}};
    int A[2][2];
    int r = Multiplication(D, M, N, A);
    cr_assert_eq(r, -3);
}
Test(Multiplication, test_case_6)
{
    int D[6] = {2,2, 2,2, 2,2};
    int M[2][2] = {{0,0},{0,0}};
    int N[2][2] = {{5,6},{7,8}};
    int A[2][2];
    int r = Multiplication(D, M, N, A);
    cr_assert_eq(r, 1);
}
Test(Multiplication, test_case_7)
{
    int D[6] = {1,1, 1,1, 1,1};
    int M[1][1] = {{7}};
    int N[1][1] = {{3}};
    int A[1][1];
    int r = Multiplication(D, M, N, A);
    cr_assert_eq(r, 1);
}
Test(Multiplication, test_case_8)
{
    int D[6] = {2,2, 2,2, 2,2};
    int M[2][2] = {{-1, 2},{-3, 4}};
    int N[2][2] = {{ -2, 3},{ 2, -2}};
    int A[2][2];
    int r = Multiplication(D, M, N, A);
    cr_assert_eq(r, 1);

}
Test(Multiplication, test_case_9)
{
    int D[6] = {2,3, 2,3, 2,3};
    int M[2][3] = {{1,2,3},{4,5,6}};
    int N[2][3] = {{3,3,3},{5,0,5}};
    int A[2][3];
    int r = Multiplication(D, M, N, A);
    cr_assert_eq(r, -1);
}

Test(Multiplication, test_case_10)
{
    int D[6] = {3,3, 3,2, 3,3};
    int M[3][3] = {{1,2},{3,4}};
    int N[3][2] = {{1,1},{1,1}};
    int A[3][3];
    int r = Multiplication(D, M, N, A);
    cr_assert_eq(r, 2);
}


/* Test(DiagonalSum, square_matrix)
{
    int D[4] = {3,3,5,3};

    int A[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int DS[5][3];

    int r = DiagonalSum(D,A,DS);

    cr_assert_eq(r,1);
}
*/
Test(DiagonalSum, test_case_1)
{
    int D[4] = {3,3,5,3};
    int A[3][3] = {
        {9,8,7},
        {6,5,4},
        {3,2,1}
    };
    int DS[5][3];
    int r = DiagonalSum(D, A, DS);
    cr_assert_eq(r, 1);
}
Test(DiagonalSum, test_case_2)
{
    int D[4] = {3,3,7,5};
    int A[3][3] = {
        {9,8,7},
        {6,5,4},
        {3,2,1}
    };
    int DS[7][5];
    int r = DiagonalSum(D, A, DS);
    cr_assert_eq(r, 2);
}
Test(DiagonalSum, test_case_3)
{
    int D[4] = {3,3,3,2};
    int A[3][3] = {
        {9,8,7},
        {6,5,4},
        {3,2,1}
    };
    int DS[3][2];
    int r = DiagonalSum(D, A, DS);
    cr_assert_eq(r, -1);
}
Test(DiagonalSum, test_case_4)
{
    int D[4] = {3,3,5,1};
    int A[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int DS[5][1];
    int r = DiagonalSum(D, A, DS);
    cr_assert_eq(r, -1);
}
Test(DiagonalSum, test_case_5)
{
    int D[4] = {4,4,8,6};
    int A[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int DS[8][6];
    int r = DiagonalSum(D, A, DS);
    cr_assert_eq(r, 2);
}
Test(DiagonalSum, test_case_6)
{
    int D[4] = {1,1,3,2};
    int A[1][1] = {{7}};
    int DS[3][2];
    int r = DiagonalSum(D, A, DS);
    cr_assert_eq(r, 1);
 
}
Test(DiagonalSum, test_case_7)
{
    int D[4] = {4,4,5,3};
    int A[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int DS[5][3];
    int r = DiagonalSum(D, A, DS);
    cr_assert_eq(r, -1);
}
Test(DiagonalSum, test_case_8)
{
    int D[4] = {3,3,5,3};
    int A[3][3] = {
        {-1, 0, -4},
        { 0,-2, 0},
        { -5, 0,-3}
    };
    int DS[5][3];
    int r = DiagonalSum(D, A, DS);
    cr_assert_eq(r, 1);
}
Test(DiagonalSum, test_case_9)
{
    int D[4] = {3,3,5,3};
    int A[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    int DS[5][3];
    int r = DiagonalSum(D, A, DS);
    cr_assert_eq(r, 1);

}
Test(DiagonalSum, test_case_10)
{
    int D[4] = {6,6,8,6};

    int A[6][6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24},
        {25,26,27,28,29,30},
        {31,32,33,34,35,36}
    };

    int DS[8][6];

    int r = DiagonalSum(D, A, DS);

    cr_assert_eq(r, 1);
}