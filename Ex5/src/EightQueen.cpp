#include <iostream>
#include <fstream>
#include <stdio.h> 
#include <stdlib.h> 
#define N 8 
using namespace std;

bool column[N] = {false};
bool slash[2*N] = {false};
bool backSlash[2*N] = {false};
int queens[N] = {0}; 
ofstream outputFile;

void printQ(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(queens[i] == j)
				outputFile << "Q ";
			else
				outputFile << "- ";
		}
		outputFile << endl;
	}
	outputFile << endl;
}

void backTrack(int i){
	if(i >= N)
		printQ();
	else{
		for(int j = 0; j < N; j++){
			if(!(column[j] || slash[i + j] || backSlash[i - j + N])){
				queens[i] = j;
				column[j] = slash[i + j] = backSlash[i - j + N] = true;
				backTrack(i+1);
				column[j] = slash[i + j] = backSlash[i - j + N] = false;
			} 
		}
	}
}

int main(){
	outputFile.open("../data/output.txt");
	backTrack(0); 
	outputFile.close();
	return 0;
} 

