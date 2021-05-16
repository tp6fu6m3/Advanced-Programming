// Sort.h
struct Data
{
	int intX;
	float floatX;
	double doubleX;
};

double identityF(double x);
double squareF(double x);

int cmpareInt(const void *a ,const void *b);
int cmpareFloat(const void *a ,const void *b);
int cmpareDouble(const void *a ,const void *b);
static void swap(char *a, char *b, size_t n);

double selectionSort(void *base, size_t nmemb, size_t size, int (* compare) (const void *, const void *));
double insertionSort(void *base, size_t nmemb, size_t size, int (* compare) (const void *, const void *));
double bubbleSort(void *base, size_t nmemb, size_t size, int (* compare) (const void *, const void *));

double selectionSortArr(int N, int* num);
double selectionSortArr(int N, double* num);
double selectionSortArr(int N, double* num, double (* F)(double x));

double insertionSortArr(int N, int* num);
double insertionSortArr(int N, double* num);
double insertionSortArr(int N, double* num, double (* F)(double x));

double bubbleSortArr(int N, int* num);
double bubbleSortArr(int N, double* num);
double bubbleSortArr(int N, double* num, double (* F)(double x));

void reverseSortArr(int N, int* num);
void reverseSortArr(int N, double* num);

double SchwartzianSelectionSortArr(int N, double* num, double (* F)(double x));
double SchwartzianInsertionSortArr(int N, double* num, double (* F)(double x));
double SchwartzianBubbleSortArr(int N, double* num, double (* F)(double x));
