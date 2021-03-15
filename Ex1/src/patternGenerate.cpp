#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    cout<<"Number of elements for input pattern generation:";
	int N;
	cin>>N;
	
	srand(time(NULL));
	
    ofstream outputFile;
    outputFile.open("../data/input.txt");
	for(int i=0; i<N; i++){
		double x = (100.0 - (-100.0)) * rand() / (RAND_MAX + 1.0) + (-100.0);
        outputFile << x << endl;
	}
    outputFile.close();
    
	return 0;
}