All of the test cases that I have made apply to different situations for each function. 
Below I will describe what each test case is testing for each function. 

Tests for Sparse Matrix: 
1. Test a 3x6 sparse matrix, test that it returns 4 and is sparse 
2. Test an all zero matrix, test that it returns 0
3. Test when only one non zero element 
4. Test a matrix that is not sparse 
5. Test a 2x4 matrix with one non zero per row
6. Test an all zero 2x2 matrix
7. Test a matrix with negative values, make sure that the non zero values count those as well 
8. Test a 2x2 matrix with non zero values 
9. Test a 3x3 matrix with exactly one more nonzero than the maximum dimension 
10. Test a 3x3 matrix with nonzeros down the anti-diagonal 

Tests for Hadamard Product: 
1. Compute two matrices with exact same dimensions 
2. Test two incompatible matrices with A being large enough to hold the overlap 
3. Test two incompatible matrix with A not being large enough to hold the overlap 
4. Compatible matrices with an oversized A 
5. Test two compatible matrices with A being too small to return full new matrix 
6. Compute 2x2 matrices where one is all zeros 
7. Test 1x1 matrices 
8. Test compatible matrices with negative values
9. Test two compatible rectangular matrices with exact fit 
10. Test incompatible matrices wtih only one row being left as zeros

Tests for Matrix Multiplication: 
1. Test two identical 3x3 matrix with A being an exact fit 
2. Test incompatible matrices where A is large enough to fit the overlap
3. Test incompatible matrices where A is too small to fit the overlap 
4. Test compatible matrices where A is oversized 
5. Test compatible matrices where A is undersized 
6. Test 2x2 compatible matrices where A is an exact fit 
7. Test 1x1 matrices 
8. Test compatible matrices with negative numbers 
9. Test two compatible rectangular matrices 
10. Test compatible matrices with only one row being left as zeros

Tests for Diagonal Sum: 
1. Test a 3x3 matrix with DS being the exact fit 
2. Test a 3x3 matrix with an oversized DS 
3. Test a 3x3 matrix with an undersized DS
4. Test a 3x3 matrix with columns of DS being undersized but not rows
5. Test a 4x4 matrix with oversized DS 
6. Test a 1x1 matrix 
7. Test a 4x4 with an undersized DS
8. Test a matrix with negative values 
9. Test an all zero matrix 
10. Test a larger, 6x6 matrix 
