#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout<<"Number of elements for selection sort:";
	int N, minId;
	cin>>N;
	
	float tmp, num[N];
	
    ifstream inputFile;
    inputFile.open("../data/input.txt");
    for(int i=0; i<N; i++)
        inputFile>>num[i];
	inputFile.close();
	
    for(int i=0; i<N; i++){
        minId = i;
		for(int j=i+1; j<N; j++){
            if(num[minId] > num[j]){
                minId = j;
            }
        }
		tmp = num[i];
		num[i] = num[minId];
		num[minId] = tmp;
    }

    ofstream outputFile;
    outputFile.open("../data/output.txt");
	for(int i=0; i<N; i++)
        outputFile << num[i] << endl;
    outputFile.close();
    
	return 0;
}