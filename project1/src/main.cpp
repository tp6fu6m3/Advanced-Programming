#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include "Sort.h"
using namespace std;

void SizeVsTime(int logSize, int maxSize)
{
	ofstream File;
	File.open("../data/SizeVsTime.csv");
	File << "input size\\time in seconds" << ',' << "bubbleSort" << ',';
	File << "insertionSort" << ',' << "selectionSort" << endl;
	int N;
	double *Arr1, *Arr2, *Arr3;
	srand(time(NULL));
	while(logSize < maxSize){
		N = pow(2, logSize);
		Arr1 = new double[N];
		Arr2 = new double[N];
		Arr3 = new double[N];
		for(int i=0; i<N; i++)
			Arr1[i] = Arr2[i] = Arr3[i] = rand() % 10000;
		
		File << N << ',';
		File << bubbleSortArr(N, Arr1) << ',';
		File << insertionSortArr(N, Arr2) << ',';
		File << selectionSortArr(N, Arr3) << endl;
		cout << "Sorting with data size of " << N << endl;
		logSize++;
	}
	File.close();
}

void OrderVsTime(int Size)
{
	ofstream File;
	File.open("../data/OrderVsTime.csv");
	File << "time in seconds" << ',' << "selectionSort" << ',' << "insertionSort" << ',';
	File << "bubbleSort" << endl;
	int N = pow(2, Size);
	double *Arr1, *Arr2, *Arr3;
	srand(time(NULL));
	Arr1 = new double[N];
	Arr2 = new double[N];
	Arr3 = new double[N];
	for(int i=0; i<N; i++)
		Arr1[i] = Arr2[i] = Arr3[i] = rand() % 10000;
	
	File << "random" << ',';
	File << selectionSortArr(N, Arr1) << ',';
	File << insertionSortArr(N, Arr2) << ',';
	File << bubbleSortArr(N, Arr3) << endl;
	
	File << "increasing" << ',';
	File << selectionSortArr(N, Arr1) << ',';
	File << insertionSortArr(N, Arr2) << ',';
	File << bubbleSortArr(N, Arr3) << endl;
	
	reverseSortArr(N, Arr1);
	reverseSortArr(N, Arr2);
	reverseSortArr(N, Arr3);
	
	File << "decreasing" << ',';
	File << selectionSortArr(N, Arr1) << ',';
	File << insertionSortArr(N, Arr2) << ',';
	File << bubbleSortArr(N, Arr3) << endl;
	
	for(int i=0; i<N; i++)
		Arr1[i] = Arr2[i] = Arr3[i] = i + rand()%5 - 2;
	
	File << "semi-ordered" << ',';
	File << selectionSortArr(N, Arr1) << ',';
	File << insertionSortArr(N, Arr2) << ',';
	File << bubbleSortArr(N, Arr3) << endl;
	File.close();
}

void ValueSetVsTime(int Size){
	ofstream File;
	File.open("../data/ValueSetVsTime.csv");
	File << "time in seconds" << ',' << "bubbleSort" << ',' << "insertionSort" << ',';
	File << "selectionSort" << endl;
	int N = pow(2, Size);
	double *Arr1, *Arr2, *Arr3;
	srand(time(NULL));
	Arr1 = new double[N];
	Arr2 = new double[N];
	Arr3 = new double[N];
	for(int i=0; i<N; i++)
		Arr1[i] = Arr2[i] = Arr3[i] = rand() % 10000;
	
	File << "real" << ',' << bubbleSortArr(N, Arr1) << ',' << insertionSortArr(N, Arr2) << ',';
	File << selectionSortArr(N, Arr3) << endl;
	
	int *Arr4, *Arr5, *Arr6;
	Arr4 = new int[N];
	Arr5 = new int[N];
	Arr6 = new int[N];
	for(int i=0; i<N; i++)
		Arr4[i] = Arr5[i] = Arr6[i] = rand() % 10000;
	
	File << "integer" << ',' << bubbleSortArr(N, Arr4) << ',' << insertionSortArr(N, Arr5) << ',';
	File << selectionSortArr(N, Arr6) << endl;
}

void DataStructureVsTime(int Size){
	ofstream File;
	File.open("../data/DataStructureVsTime.csv");
	File << "time in seconds" << ',' << "bubbleSort" << ',' << "insertionSort" << ',';
	File << "selectionSort" << endl;
	int N = pow(2, Size);
	double *Arr1, *Arr2, *Arr3;
	struct Data Data1[N], Data2[N], Data3[N];
	srand(time(NULL));
	Arr1 = new double[N];
	Arr2 = new double[N];
	Arr3 = new double[N];
	
	for(int i=0; i<N; i++){
		Arr1[i] = Arr2[i] = Arr3[i] = rand() % 10000;
		Data1[N].doubleX = Data2[N].doubleX = Data3[N].doubleX = Arr1[i];
	}
	File << "Complex data structure" << ',' << bubbleSort(Data1, N, sizeof(Data1[0]), cmpareDouble) << ',';
	File << insertionSort(Data2, N, sizeof(Data2[0]), cmpareDouble) << ',' << selectionSort(Data3, N, sizeof(Data3[0]), cmpareDouble) << endl;
	
	File << "Simple data structure" << ',' << bubbleSortArr(N, Arr1) << ',';
	File << insertionSortArr(N, Arr2) << ',' << selectionSortArr(N, Arr3) << endl;
}

void SchwartzianVsTime(int Size){
	ofstream File;
	File.open("../data/SchwartzianVsTime.csv");
	File << "time in seconds" << ',' << "bubbleSort" << ',' << "insertionSort" << ',';
	File << "selectionSort" << endl;
	int N = pow(2, Size);
	double *Arr1, *Arr2, *Arr3, *Arr4, *Arr5, *Arr6;
	srand(time(NULL));
	Arr1 = new double[N];
	Arr2 = new double[N];
	Arr3 = new double[N];
	Arr4 = new double[N];
	Arr5 = new double[N];
	Arr6 = new double[N];
	
	for(int i=0; i<N; i++){
		Arr1[i] = Arr2[i] = Arr3[i] = Arr4[i] = Arr5[i] = Arr6[i] = rand() % 10000;
	}
	File << "with Schwartzian" << ',' << SchwartzianBubbleSortArr(N, Arr1, squareF) << ',';
	File << SchwartzianInsertionSortArr(N, Arr2, squareF) << ',' << SchwartzianSelectionSortArr(N, Arr3, squareF) << endl;
	
	File << "without Schwartzian" << ',' << bubbleSortArr(N, Arr4, squareF) << ',';
	File << insertionSortArr(N, Arr5, squareF) << ',' << selectionSortArr(N, Arr6, squareF) << endl;
}

int getLines(string path){
	ifstream iFile;
	iFile.open(path);
	int line = 0;
	string temp;
	while(getline(iFile, temp))
		line++;
	iFile.close();
	return line;
}

int main(int argc, char *argv[])
{
	if(argc >= 2 && std::string(argv[1]) == "--SizeVsTime"){
		cout << "Input size among 2^10 ~ 2 to the power of ";
		int N;
		cin>>N;
		SizeVsTime(10, N);
	}
	else if(argc >= 2 && std::string(argv[1]) == "--OrderVsTime"){
		cout << "Input size = 2 to the power of ";
		int N;
		cin>>N;
		OrderVsTime(N);
	}
	else if(argc >= 2 && std::string(argv[1]) == "--ValueSetVsTime"){
		cout << "Input size = 2 to the power of ";
		int N;
		cin>>N;
		ValueSetVsTime(N);
	}
	else if(argc >= 2 && std::string(argv[1]) == "--DataStructureVsTime"){
		cout << "Input size = 2 to the power of ";
		int N;
		cin>>N;
		DataStructureVsTime(N);
	}
	else if(argc >= 2 && std::string(argv[1]) == "--SchwartzianVsTime"){
		cout << "Input size = 2 to the power of ";
		int N;
		cin>>N;
		SchwartzianVsTime(N);
	}
	else if(argc >= 2 && std::string(argv[1]) == "--selection" || "--insertion" || "--bubble"){
		string path = (argc >= 4 && std::string(argv[2]) == "-i") ? argv[3] : "../data/input.txt";
		int N = getLines(path);
		double *Arr = new double[N];
		
		ifstream iFile;
		iFile.open(path);
		for(int i=0; i<N; i++)
			iFile >> Arr[i];
		iFile.close();
		
		if(std::string(argv[1]) == "--selection")
			cout<< "Execution time = " << selectionSortArr(N, Arr) << " seconds" << endl;
		else if(std::string(argv[1]) == "--insertion")
			cout<< "Execution time = " << insertionSortArr(N, Arr) << " seconds" << endl;
		else if(std::string(argv[1]) == "--bubble")
			cout<< "Execution time = " << bubbleSortArr(N, Arr) << " seconds" << endl;
		
		ofstream oFile;
		oFile.open("../data/output.txt");
		for(int i=0; i<N; i++)
			oFile << Arr[i] << endl;
		oFile.close();
	}
	return 0;
}