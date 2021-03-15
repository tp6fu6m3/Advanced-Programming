#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout<<"Number of elements for insertion sort:";
	int N;
	cin>>N;
	
	float tmp, num[N];
	
    ifstream inputFile;
    inputFile.open("../data/input.txt");
    for(int i=0; i<N; i++)
        inputFile>>num[i];
	inputFile.close();
	
    for(int i=1; i<N; i++){
        tmp = num[i];
		for(int j=i-1; j>=0; j--){
            if(num[j] > tmp){
                num[j+1] = num[j];
                num[j] = tmp;
            }
        }
    }

    ofstream outputFile;
    outputFile.open("../data/output.txt");
	for(int i=0; i<N; i++)
        outputFile << num[i] << endl;
    outputFile.close();
    
	return 0;
}