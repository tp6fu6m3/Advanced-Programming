#include <time.h>
#include <math.h>
#include "Sort.h"
using namespace std;

double identityF(double x){
	return x;
}
double squareF(double x){
	return x*x;
}

int cmpareInt(const void *a ,const void *b){
	return ((Data *)a)->intX > ((Data *)b)->intX ? 1 : -1;
}
int cmpareFloat(const void *a ,const void *b){
	return ((Data *)a)->floatX > ((Data *)b)->floatX ? 1 : -1;
}
int cmpareDouble(const void *a ,const void *b){
	return ((Data *)a)->doubleX > ((Data *)b)->doubleX ? 1 : -1;
}

static void swap(char *a, char *b, size_t n)
{
	register char *an = a + n;
	register char tmp;
	do {
		tmp = *a;
		*a++ = *b;
		*b++ = tmp;
	} while (a < an);
}

double selectionSort(void *base, size_t nmemb, size_t size, int (* compare) (const void *, const void *))
{
	double tStart = clock();
	if (nmemb <= 1)
		return 0.;
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
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double insertionSort(void *base, size_t nmemb, size_t size, int (* compare) (const void *, const void *))
{
	double tStart = clock();
	if (nmemb <= 1)
		return 0.;
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
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double bubbleSort(void *base, size_t nmemb, size_t size, int (* compare) (const void *, const void *))
{
	double tStart = clock();
	if (nmemb <= 1)
		return 0.;
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
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double selectionSortArr(int N, int* num)
{
    double tStart = clock();
	for(int i=0; i<N; i++){
        int minId = i;
		for(int j=i+1; j<N; j++){
            if(num[minId] > num[j])
                minId = j;
        }
		int tmp = num[i];
		num[i] = num[minId];
		num[minId] = tmp;
    }
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double selectionSortArr(int N, double* num)
{
    double tStart = clock();
	for(int i=0; i<N; i++){
        int minId = i;
		for(int j=i+1; j<N; j++){
            if(num[minId] > num[j])
                minId = j;
        }
		double tmp = num[i];
		num[i] = num[minId];
		num[minId] = tmp;
    }
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double insertionSortArr(int N, int* num)
{
    double tStart = clock();
	for(int i=1; i<N; i++){
        int tmp = num[i];
		for(int j=i-1; j>=0; j--){
            if(num[j] > tmp){
                num[j+1] = num[j];
                num[j] = tmp;
            }
        }
    }
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double insertionSortArr(int N, double* num)
{
    double tStart = clock();
	for(int i=1; i<N; i++){
        double tmp = num[i];
		for(int j=i-1; j>=0; j--){
            if(num[j] > tmp){
                num[j+1] = num[j];
                num[j] = tmp;
            }
        }
    }
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double bubbleSortArr(int N, int* num)
{
    double tStart = clock();
	for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(num[i] > num[j]){
                int tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double bubbleSortArr(int N, double* num)
{
    double tStart = clock();
	for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(num[i] > num[j]){
                double tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

void reverseSortArr(int N, int* num)
{
	for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(num[i] < num[j]){
                int tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
}

void reverseSortArr(int N, double* num)
{
	for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(num[i] < num[j]){
                double tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
}

double selectionSortArr(int N, double* num, double (* F)(double x))
{
    double tStart = clock();
	for(int i=0; i<N; i++){
        int minId = i;
		for(int j=i+1; j<N; j++){
            if(F(num[minId]) > F(num[j]))
                minId = j;
        }
		double tmp = num[i];
		num[i] = num[minId];
		num[minId] = tmp;
    }
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double insertionSortArr(int N, double* num, double (* F)(double x))
{
    double tStart = clock();
	for(int i=1; i<N; i++){
        double tmp = num[i], tmpF = F(num[i]);
		for(int j=i-1; j>=0; j--){
            if(F(num[j]) > tmpF){
                num[j+1] = num[j];
                num[j] = tmp;
            }
        }
    }
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double bubbleSortArr(int N, double* num, double (* F)(double x))
{
    double tStart = clock();
	for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(F(num[i]) > F(num[j])){
                double tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double SchwartzianSelectionSortArr(int N, double* num, double (* F)(double x))
{
    double tStart = clock();
	for(int i=0; i<N; i++){
		num[i] = F(num[i]);
	}
	for(int i=0; i<N; i++){
        int minId = i;
		for(int j=i+1; j<N; j++){
            if(num[minId] > num[j])
                minId = j;
        }
		double tmp = num[i];
		num[i] = num[minId];
		num[minId] = tmp;
    }
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double SchwartzianInsertionSortArr(int N, double* num, double (* F)(double x))
{
    double tStart = clock();
	for(int i=0; i<N; i++){
		num[i] = F(num[i]);
	}
	for(int i=1; i<N; i++){
        double tmp = num[i];
		for(int j=i-1; j>=0; j--){
            if(num[j] > tmp){
                num[j+1] = num[j];
                num[j] = tmp;
            }
        }
    }
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}

double SchwartzianBubbleSortArr(int N, double* num, double (* F)(double x))
{
    double tStart = clock();
	for(int i=0; i<N; i++){
		num[i] = F(num[i]);
	}
	for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            if(num[i] > num[j]){
                double tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
	return (double)(clock() - tStart)/CLOCKS_PER_SEC;
}
