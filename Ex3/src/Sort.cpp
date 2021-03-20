#include <iostream>
#include <fstream>
using namespace std;

static void swap(char *a, char *b, size_t n){
	register char *an = a + n;
	register char tmp;
	do {
		tmp = *a;
		*a++ = *b;
		*b++ = tmp;
	} while (a < an);
}

void selectionSort(void *base, size_t nmemb, size_t size, int (* compare) (const void *, const void *))
{
	if (nmemb <= 1)
		return;
	register char *i, *j, *minId;
	char *hi = ((char *) base) + (nmemb - 1) * size;
	char *lo = (char *) base;
	
	for(i=lo; i<=hi; i+=size){
        minId = i;
		for(j=i+size; j<=hi; j+=size){
            if(compare(minId, j) > 0){
                minId = j;
            }
        }
		swap (i, minId, size);
    }
}

void insertionSort(void *base, size_t nmemb, size_t size, int (* compare) (const void *, const void *))
{
	if (nmemb <= 1)
		return;
	register char *i, *j;
	char *hi = ((char *) base) + (nmemb - 1) * size;
	char *lo = (char *) base;
	
	for(i=lo+size; i<=hi; i+=size){
		for(j=i-size; j>=lo; j-=size){
            if(compare(j, j+size) > 0){
                swap (j, j+size, size);
            }
        }
    }
}

void bubbleSort(void *base, size_t nmemb, size_t size, int (* compare) (const void *, const void *))
{
	if (nmemb <= 1)
		return;
	register char *i, *j, *minId;
	char *hi = ((char *) base) + (nmemb - 1) * size;
	char *lo = (char *) base;
	
	for(i=lo; i<=hi; i+=size){
		for(j=i+size; j<=hi; j+=size){
            if(compare(i, j) > 0){
                swap (i, j, size);
            }
        }
    }
}

struct StuData{
	int age;
	int number;
	float score;
};

int cmp_age(const void *a ,const void *b){
	return ((StuData *)a)->age > ((StuData *)b)->age ? 1 : -1;
}

int cmp_score(const void *a ,const void *b){
	return ((StuData *)a)->score > ((StuData *)b)->score ? 1 : -1;
}

int main(int argc, char *argv[])
{
	cout<<"Number of elements for quick sort:";
	int N;
	cin>>N;
	struct StuData student[N];
	
	ifstream ageFile;
    ageFile.open("../data/age.txt");
    for(int i=0; i<N; i++)
        ageFile >> student[i].age;
	ageFile.close();
	
	ifstream scoreFile;
    scoreFile.open("../data/score.txt");
    for(int i=0; i<N; i++)
        scoreFile >> student[i].score;
	scoreFile.close();
	
	for(int i=0; i<N; i++)
        student[i].number = i;
	
	if(argc > 1 && std::string(argv[1]) == "--selection"){
		if(argc > 2 && std::string(argv[2]) == "--age")
			selectionSort(student, N, sizeof(student[0]), cmp_age);
		else
			selectionSort(student, N, sizeof(student[0]), cmp_score);
	}
	else if(argc > 1 && std::string(argv[1]) == "--insertion"){
		if(argc > 2 && std::string(argv[2]) == "--age")
			insertionSort(student, N, sizeof(student[0]), cmp_age);
		else
			insertionSort(student, N, sizeof(student[0]), cmp_score);
	}
	else if(argc > 1 && std::string(argv[1]) == "--bubble"){
		if(argc > 2 && std::string(argv[2]) == "--age")
			bubbleSort(student, N, sizeof(student[0]), cmp_age);
		else
			bubbleSort(student, N, sizeof(student[0]), cmp_score);
	}
	else{
		if(argc > 1 && std::string(argv[1]) == "--age")
			qsort(student, N, sizeof(student[0]), cmp_age);
		else
			qsort(student, N, sizeof(student[0]), cmp_score);
	}
	
	ofstream outputFile;
    outputFile.open("../data/output.txt");
	outputFile << "name" << "\t" << "age" << "\t" << "score" << endl;
	for(int i=0; i<N; i++)
        outputFile << "Stud" << student[i].number << "\t" << student[i].age << "\t" << student[i].score << endl;
    outputFile.close();
	
	return 0;
}