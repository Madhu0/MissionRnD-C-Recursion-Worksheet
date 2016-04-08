/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

int spiral_recursion(int rows, int columns, int **input, int **check, int *res, int posr,int posc,int respos){
	int i, j;
	if ((posr >= rows) || (posc >= columns)){
		return respos;
	}
	if ((posc + 1 < columns) && (check[posr][posc + 1] == 0)){
		for (j = posc + 1; (j < columns) && (check[posr][j] == 0); j++){
			res[respos++] = input[posr][j];
			check[posr][j] = 1;
		}
		respos = spiral_recursion(rows, columns, input, check,res, posr, j-1,respos);
	}
	else if ((posr + 1 < rows) && (check[posr+1][posc] == 0)){
		for (i = posr + 1; (i < rows) && (check[i][posc] == 0); i++){
			res[respos++] = input[i][posc];
			check[i][posc] = 1;
		}
		respos = spiral_recursion(rows, columns, input, check, res, i-1, posc, respos);
	}
	else if ((posc - 1 >=0) && (check[posr][posc - 1] == 0)){
		for (j = posc - 1; (j >=0) && (check[posr][j] == 0); j--){
			res[respos++] = input[posr][j];
			check[posr][j] = 1;
		}
		respos = spiral_recursion(rows, columns, input, check, res, posr, j+1, respos);
	}
	else if ((posr - 1 >= 0) && (check[posr - 1][posc] == 0)){
		for (i = posr - 1; (i >= 0) && (check[i][posc] == 0); i--){
			res[respos++] = input[i][posc];
			check[i][posc] = 1;
		}
		respos = spiral_recursion(rows, columns, input, check, res, i + 1, posc, respos);
	}
	else
		return respos;
}

int *spiral(int rows, int columns, int **input_array)
{	
	if (input_array == NULL || rows < 1 || columns < 1)
		return NULL;
	int *res, **check,i,j;
	res = (int *)malloc(sizeof(int)*rows*columns);
	check = (int **)malloc(sizeof(int *)*rows);
	for (i = 0; i < rows; i++)
		check[i] = (int *)malloc(sizeof(int)*columns);
	for (i = 0; i < rows; i++){
		for (j = 0; j < columns; j++){
			check[i][j] = 0;
		}
	}
	res[0] = input_array[0][0];
	check[0][0] = 1;
	spiral_recursion(rows, columns, input_array, check, res,0,0,1);
	return res;
}
