/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include "stdafx.h"
#include<stdlib.h>


int path_finder(int *maze, int **path, int rows, int columns, int x1, int y1, int x2, int y2){
	int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
	if (x1 >= rows || y1 >= columns || x1<0 || y1<0)
		return 0;
	if (path[x1][y1] == 0)
		path[x1][y1] = 1;
	else
		return 0;
	if (maze[(x1*columns) + y1] == 0){
		path[x1][y1] = -1;
		return 0;
	}
	if (x1 == x2&&y1 == y2)
		return 1;
	temp1 = path_finder(maze, path, rows, columns, x1 + 1, y1, x2, y2);
	temp2 = path_finder(maze, path, rows, columns, x1, y1 + 1, x2, y2);
	temp3 = path_finder(maze, path, rows, columns, x1 - 1, y1, x2, y2);
	temp4 = path_finder(maze, path, rows, columns, x1, y1 - 1, x2, y2);
	if (temp1 || temp2 || temp3 || temp4)
		return 1;
	else
		return 0;
}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int **path;
	int i, j;
	path = (int **)malloc(sizeof(int *)*rows);
	for (i = 0; i<rows; i++)
		path[i] = (int *)malloc(sizeof(int)*columns);
	for (i = 0; i<rows; i++)
	for (j = 0; j<columns; j++)
		path[i][j] = 0;
	if (x1 > rows || x2 > rows || y1 > columns || y2 > columns)
		return 0;
	if (maze[(x1*columns) + y1] == 0 || maze[(x2*columns) + y2] == 0)
		return 0;
	return path_finder(maze, path, rows, columns, x1, y1, x2, y2);
}
