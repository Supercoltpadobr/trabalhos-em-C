#include <stdio.h>
#include "floodfill.h"


void FloodFill(char * * Matriz, int x, int y, int M, int N){
	if (!(x>N || y>M) && Matriz[x][y] != 'X'){
		Matriz[x][y] = 'X';
		FloodFill(Matriz, x+1, y, M, N);
		FloodFill(Matriz, x, y+1, M, N);
		FloodFill(Matriz, x-1, y, M, N);
		FloodFill(Matriz, x, y-1, M, N);
	}
}