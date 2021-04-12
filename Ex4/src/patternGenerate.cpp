#include <iostream>
#include <fstream>
#include <string> 
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    int N, type;
	cout<<"Number of elements for input pattern generation:";
	cin>>N;
	cout<<"Object type (int: 0, float: 1, string: 2):";
	cin>>type;
	
	srand(time(NULL));
	
    ofstream inputFile;
    inputFile.open("../data/input.txt");
	if(type==0){
		for(int i=0; i<N; i++){
			int x = rand() % 100;
			inputFile << x << endl;
		}
	}
	else if(type==1){
		for(int i=0; i<N; i++){
			double x = (100.0 - (-100.0)) * rand() / (RAND_MAX + 1.0) + (-100.0);
			inputFile << x << endl;
		}
	}
	else{
		for(int i=0; i<N; i++){
			string x = "object" + std::to_string(i);
			inputFile << x << endl;
		}
	}
    inputFile.close();
	return 0;
}