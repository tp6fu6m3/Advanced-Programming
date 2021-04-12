#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

vector<string> vec0;
vector<string> vec1;
vector<string> vec2;
ofstream outputFile;

void print(vector<string>& v){
	for (int i = 0; i < v.size(); i++)
		outputFile << v[i] << " ";
	outputFile << endl;
}

void swap(int i, int j){
    string temp = vec2[i];
    vec2[i] = vec2[j];
    vec2[j] = temp;
} 

void permutation(int l, int r){
	if (l == r){
        print(vec2);
		return;
	}
	for (int i = l; i <= r; i++) { 
		swap(l, i);
		permutation(l + 1, r);
		swap(l, i);
	} 
} 

void combination(int l, int r){
	if (r == 0){
		vec2.assign(vec1.begin(), vec1.end());
		permutation(0, vec1.size()-1);
		return;
	}
	for (int i = l; i <= vec0.size() - r; i++){
		vec1.push_back(vec0[i]);
		combination(i + 1, r - 1);
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
	for (int i = 0; i < n; i++){
		inputFile >> temp;
		vec0.push_back(temp);
	}
	inputFile.close();
	
    outputFile.open("../data/output.txt");
	combination(0, k);
	outputFile.close();
	return 0;
}
