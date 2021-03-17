#include <iostream>
#include <fstream>
using namespace std;

struct StuData{
	int age;
	float score;
} student[10];

int cmp_age( const void *a ,const void *b){
	return ((StuData *)a)->age > ((StuData *)b)->age ? 1 : -1;
}

int cmp_score( const void *a ,const void *b){
	return ((StuData *)a)->score > ((StuData *)b)->score ? 1 : -1;
}

int main(int argc, char *argv[])
{
	ifstream ageFile;
    ageFile.open("../data/age.txt");
    for(int i=0; i<10; i++)
        ageFile >> student[i].age;
	ageFile.close();
	
	ifstream scoreFile;
    scoreFile.open("../data/score.txt");
    for(int i=0; i<10; i++)
        scoreFile >> student[i].score;
	scoreFile.close();
	
	if(std::string(argv[1]) == "--compare_age")
		qsort(student, 10, sizeof(student[0]), cmp_age);
	else
		qsort(student, 10, sizeof(student[0]), cmp_score);
	
	ofstream outputFile;
    outputFile.open("../data/output.txt");
	outputFile << "name" << "\t" << "age" << "\t" << "score" << endl;
	for(int i=0; i<10; i++)
        outputFile << "Stud" << i << "\t" << student[i].age << "\t" << student[i].score << endl;
    outputFile.close();
	
	return 0;
}