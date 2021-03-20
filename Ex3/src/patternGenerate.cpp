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
	
    ofstream scoreFile;
    scoreFile.open("../data/score.txt");
	for(int i=0; i<N; i++){
		double x = (100.0 - (-100.0)) * rand() / (RAND_MAX + 1.0) + (-100.0);
        scoreFile << x << endl;
	}
    scoreFile.close();
	
	ofstream ageFile;
    ageFile.open("../data/age.txt");
	for(int i=0; i<N; i++){
		int x = rand() % 100;
        ageFile << x << endl;
	}
    ageFile.close();
    
	return 0;
}