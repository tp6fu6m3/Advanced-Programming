#include <iostream>
#include <fstream>
#include <math.h>
#define N 9
using namespace std;

int grid[N][N] = {0};
bool inCol[N][N] = {false};
bool inRow[N][N] = {false};
bool inBox[(int)sqrt(N)][(int)sqrt(N)][N] = {false};

void initGrid(){
	ifstream inputFile("../data/sudoku.csv");
	char c;
	int row = 0, col = 0, num = 0;
	while(inputFile.get(c)){
		num = c - '0';
		if(num==47)
			col++;
		else if((num > 0) && (num < 10)){
			grid[row][col] = num;
			inRow[row][num] = inCol[col][num] = inBox[row/3][col/3][num] = true;
			col++;
		}
		else if(num==-38){
			col = 0;
			row++;
		}
	}
	inputFile.close();
}

void printGrid(){ 
	ofstream outputFile("../data/output.csv");
	for (int row = 0; row < N; row++){
		for (int col = 0; col < N; col++)
			outputFile << grid[row][col] << ",";
		outputFile << endl;
	}
	outputFile.close();
}

bool findEmptyPlace(int &row, int &col){
	for ( ; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == 0)
				return true;
	return false;
}

bool solveSudoku(int row, int col){
	if (!findEmptyPlace(row, col)){
		printGrid();
		return true;
	}
	for (int num = 1; num <= 9; num++){
		if (!inRow[row][num] && !inCol[col][num] && !inBox[row/3][col/3][num]){
			grid[row][col] = num;
			inRow[row][num] = inCol[col][num] = inBox[row/3][col/3][num] = true;
			if (solveSudoku(row, col))
				return true;
			grid[row][col] = 0;
			inRow[row][num] = inCol[col][num] = inBox[row/3][col/3][num] = false;
		}
	}
	return false;
}

int main(){
	initGrid();
	if (!solveSudoku(0, 0))
		cout << "No solution exists!";
	return 0;
}