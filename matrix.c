
/*
 * Homework 5 – Pointer Operations
 * CSE 220 – Spring 2026
 * Matthew Ferine ID: 116961912
 */

#include "matrix.h"
#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int min(int a, int b){
    if(a < b){
      return a; 
    }
    return b;
}

/*----------------------------------------------------
  1. Sparse Matrix
----------------------------------------------------*/
int SparseMatrix(int D[2], int M[D[0]][D[1]],
                 int S[3][(D[1] > D[0] ? D[1] : D[0])])
{

    int rows = D[0];
    int cols = D[1];
    int m = max(rows, cols);

    for(int i = 0; i < 3; i++){ //As long as our index is less than the maximum dimension of our matrix
      for(int j = 0; j < m; j++){
        S[i][j] = 0;
      } //Set up sparse matrix by populating it with zeros                                
        //This handles leftover columns and keeps them as 0 because the code will never populate them and leave them as 0
    }
    int nonZeroCount = 0;
    for(int j = 0; j < rows; j++){ //Loop through rows
      for(int k = 0; k < cols; k++){  //Loop through columns 
        if(M[j][k] != 0){ //If in the initial matrix the current value is not 0 
          S[0][nonZeroCount] = j; //Populate rows of S
          S[1][nonZeroCount] = k; //Populate columns of S 
          S[2][nonZeroCount] = M[j][k]; //Populate values of S
          nonZeroCount++; //increment amount of non zeros
          if(nonZeroCount > m){ //If matrix is not sparse, return -1
          return -1; 
         } 
        }
      }
    }
   

    return nonZeroCount; //Return the amount of nonzero values
}


/*----------------------------------------------------
  2. Hadamard Product
----------------------------------------------------*/
int HadamardProduct(const int D[6],
                    const int M[D[0]][D[1]],
                    const int N[D[2]][D[3]],
                    int A[D[4]][D[5]])
{

    int mRows = D[0];
    int mCols = D[1];

    int nRows = D[2];
    int nCols = D[3];

    int aRows = D[4];
    int aCols = D[5];
    int minRows = min(D[0],D[2]);
    int minCols = min(D[1],D[3]); //Use the minimum function I wrote to determine minimum rows and columns
    int newMatrixRows = min(minRows, aRows); 
    int newMatrixCols = min(minCols, aCols);  //Use minimum function I wrote to determine if the dimensions of A or the minimum dimensions of M and N are greater by returning the lesser

    for(int a = 0; a < aRows; a++){
      for(int b = 0; b < aCols; b++){
        A[a][b] = 0;  //Populate all of A with zeros to handle leftover parts of the A matrix and set up the Matrix
      }
    }
    for(int i = 0; i < newMatrixRows; i++){
      for(int j = 0; j < newMatrixCols; j++){
        A[i][j] = M[i][j] * N[i][j];  //Use new matrix dimensions to find hadamard product as these dimensions hold either what A needs to hold or can hold
      }
    }
    if(mRows == nRows && mCols == nCols){ //If the dimensions of M and N are compatible
      if(aRows == minRows && aCols == minCols){
        return 1; //If A has the exact dimensions of M and N, return 1
      }
      else if(aRows >= minRows && aCols >= minCols){
        return 2; //If A is oversized, but dimensions are compatible, return 2
      }
      return -3; //otherwise return -3
    } else { //If dimensions of M and N are not compatible
      if(aRows >= minRows && aCols >= minCols){
        return -1; //If A has enough space to hold the result of the multiplication, return -1
      }
      return -2; //Otherwise return -2
    }
    
}


/*----------------------------------------------------
  3. Matrix Multiplication
----------------------------------------------------*/
int Multiplication(const int D[6],
                   const int M[D[0]][D[1]],
                   const int N[D[2]][D[3]],
                   int A[D[4]][D[5]])
{

    int mRows = D[0];
    int mCols = D[1];

    int nRows = D[2];
    int nCols = D[3];

    int aRows = D[4];
    int aCols = D[5];
    
    int newMatrixRows = min(mRows, aRows); 
    int newMatrixCols = min(nCols, aCols);  //Use minimum function I wrote to determine if the dimensions set of A are greater or what the outer dimensions say A should be is greater by returning the lesser
    int smallInnerDimension = min(mCols, nRows); //Finds smallest of inner dimensions 
    for(int a = 0; a < aRows; a++){
      for(int b = 0; b < aCols; b++){
        A[a][b] = 0;  //Populate all of A with zeros to handle leftover parts of the A matrix and set up the Matrix
      }
    }
    for(int i = 0; i < newMatrixRows; i++){
      for(int j = 0; j < newMatrixCols; j++){
        for(int k = 0; k < smallInnerDimension; k++){
          A[i][j] += M[i][k] * N[k][j];  //Use new matrix dimensions to find result of matrix multiplication these dimensions hold either what A needs to hold or can hold
        }
      }
    } 
    if(mCols == nRows){ //If the dimensions of M and N are compatible
      if(aRows == mRows && aCols == nCols){
        return 1; //If A has exact dimensions of M and N, return 1
      }
      else if(aRows >= mRows && aCols >= nCols){
        return 2; //If A is oversized, but dimensions are compatible, return 2
      }
      return -3; //otherwise return -3
    } else { //If dimensions of M and N are not compatible
      if(aRows >= mRows && aCols >= nCols){
        return -1; //If A has enough space to hold the result of the multiplication, return -1
      }
      return -2; //Otherwise return -2
    }
    
}


/*----------------------------------------------------
  4. Diagonal Sum
----------------------------------------------------*/
int DiagonalSum(const int D[4],
                const int A[D[0]][D[1]],
                int DS[D[2]][D[3]])
{

    int rows = D[0];
    int cols = D[1];

    int dsRows = D[2];
    int dsCols = D[3];
    int diagonalLen = min(rows, cols); //Define length of diagonal by the smaller dimension 
    for(int a = 0; a < dsRows; a++){
      for(int b = 0; b < dsCols; b++){
        DS[a][b] = 0;  //Populate all of DS with zeros to handle leftover parts of the A matrix and set up the Matrix
      }
    }
    
    for(int i = 0; i < diagonalLen; i++){ //Loop through length of diagonal 
      if(0 < dsRows && 0 < dsCols){
        DS[0][0] += A[i][i]; //Calculate the diagonal sum and populate it at the 0,0 position
      }
      if(0 < dsRows && 1 < dsCols){
        DS[0][1] += A[i][cols-1-i]; //Calculate the anti diagonal sum and populate it at the 0,1 position
      }
    }

    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        if(1 < dsRows && j < dsCols){
          DS[1][j] += A[i][j]; //Loop through the rows and columns, populate the row sums at 1,j position(s)
        }
        if(i+2 < dsRows && 0 < dsCols){
          DS[i+2][0] += A[i][j]; //Populate the column sums at i+2,0 positions
        }
      }
    }
    if(dsRows == rows + 2 && dsCols == max(2, cols)){
      return 1;  //If the matrix is compatible, return 1
    }
    if(dsRows >= rows + 2 && dsCols >= max(2, cols)){
      return 2;  //If the matrix is oversized, return 2
    }
    return -1; //If matrix is undersized, return -1
}
