#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> vec0;
vector<string> vec1;
ofstream outputFile;

void print(const vector<string>& v){
	for (int i = 0; i < v.size(); ++i)
		outputFile << v[i] << " ";
	outputFile << endl;
}

void combination(int offset, int k){
	if (k == 0){
		print(vec1);
		return;
	}
	for (int i = offset; i <= vec0.size() - k; ++i){
		vec1.push_back(vec0[i]);
		combination(i+1, k-1);
		vec1.pop_back();
	}
}

int main(){
	int n, k;
	cout<<"Enter n:";
	cin>>n;
	cout<<"Enter k:";
	cin>>k;
	string temp;
	
	ifstream inputFile;
    inputFile.open("../data/input.txt");
	for (int i = 0; i < n; ++i){
		inputFile >> temp;
		vec0.push_back(temp);
	}
	inputFile.close();
	
    outputFile.open("../data/output.txt");
	combination(0, k);
	outputFile.close();
	return 0;
}

