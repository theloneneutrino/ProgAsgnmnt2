#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void *ec_malloc(size_t size) {
	if (size == 0) {
		fprintf(stderr, "ERROR: ammount allocated should be greater than zero.\n");
		exit(-1);
	}
	
	void *ptr;
	ptr = malloc(size);
	if (ptr == NULL) {
		fprintf(stderr, "ERROR: couldn't allocate heap memory.\n");
		exit(-1);
	}
	
	return ptr;
}

void printUsage(char * arg0) {
	printf("Usage: %s <file>\n", arg0);
}

int min(int x, int y) {
	if(x <= y)
		return x;
	else
		return y;
}

int max(int x, int y) {
	if(x >= y)
		return x;
	else
		return y;
}

void sort(int *x, int *y) {
	int minVal = min(*x, *y);
	int maxVal = max(*x, *y);
	
	*x = minVal;
	*y = maxVal;
}

int ReadUnsignedInteger() {
	//reads from istream until input is not integer
	int result = 0;
	char c = 0;
	int v = 0;
	
	c = getchar(); 
	
	for(size_t it = 0; ('0' <= c) && (c <= '9') && (it < 9); it++) {
		v = c - '0';
		result = 10 * result + v;
		c = getchar();
	}
	
	return result;
}

int ReadInteger() {
	//reads from istream until input is not integer
	int result = 0;
	char c = 0;
	bool neg = false;
	
	c = getchar();
	if( c == '-') // if negative number
		neg = true; // sets neg flag
	else if (('0' <= c ) && (c <= '9')) { // else sets result to first number
		ungetc(c, stdin);
	}
	
	result = ReadUnsignedInteger();
		
	if (!neg)
	{
		return result;
	}
	else {
		result *= -1;
		return result;
	}
}

void printIntArray (int *intArray, size_t arrSize) {
	if (arrSize == 0) {
		printf("WTF bro!?");
		exit(1);
	}
	
	printf("(");	

	for (size_t it = 0; it < arrSize - 1; it++)
		printf("%d, ", intArray[it]);
	
	printf("%d)\n", intArray[arrSize - 1]);
}

void merge(int *array1, size_t size1, int *array2, size_t size2) {
	size_t totalSize = (size1 + size2); 
	int *arrayTmp = ec_malloc(totalSize * sizeof(int));
	
	// Loop 1: puts smaller of array 1 & 2 front in C until one list empty
	size_t iterator1 = 0;
	size_t iterator2 = 0;
	size_t iteratorTmp = 0;
	
	while ( (iterator1 < size1) && (iterator2 < size2) && (iteratorTmp < totalSize) ) {
		if ( array1[iterator1] < array2[iterator2] ) {
			arrayTmp[iteratorTmp] = array1[iterator1++];
		}
		else {
			arrayTmp[iteratorTmp] = array2[iterator2++];
		}
		
		iteratorTmp++;
	}
	
	// Loop 2: if A not empty, put A's items into C
	while( (iterator1 < size1) && (iteratorTmp < totalSize) ) {
    	arrayTmp[iteratorTmp++] = array1[iterator1++];
	}
	
	// Loop 3: if B not empty, put B's items into C
	while( (iterator2 < size2) && (iteratorTmp < totalSize) ) {
    	arrayTmp[iteratorTmp++] = array2[iterator2++];
	}
	
	//loop 4: put C into A, then B
	for (iterator1 = 0; iterator1 < size1; iterator1++) {
		array1[iterator1] = arrayTmp[iterator1];
	}
	
	for (iterator2 = 0; iterator2 < size2; iterator2++) {
		array2[iterator2] = arrayTmp[iterator2 + size1];
	}
	
	free(arrayTmp);
	return;
}

int *mergeSort (int *array, size_t arraySize) {
	if (arraySize == 1) return array;
	
	size_t m = (arraySize / 2);

	int *L = &array[0];
	int *R = &array[m];
	
	int *A = mergeSort(L, m);
	int *B = mergeSort(R, arraySize - m);
		
	merge(A, m, B, arraySize - m);
	
	return A;
}

char *readFile(char *filename) {
	FILE *filePoint;
	
	filePoint = fopen( filename, "r" );
	
	if (filePoint == NULL)	{
		printf("ERROR: file \"%s\" not found.", filename);
		exit(-1);
	}
	
	fseek(filePoint, 0, SEEK_END);
	unsigned int fileLength = ftell(filePoint);
	fseek(filePoint, 0, SEEK_SET);
	
	char *fileString = ec_malloc(sizeof(char) * (fileLength + 1));
	
	char c;
	unsigned int i = 0;
	
	while ( (c = fgetc(filePoint)) != EOF) {
		fileString[i++] = c;
	}
	
	fileString[i] = '\0';
	fclose(filePoint);
	
	return fileString;
}

void readUserInput(int *array, size_t sze) {
	size_t i = 0;
	for (i = 0; i < sze; i++) {
		printf("Number: ");
		array[i] = ReadInteger();
	}
}

int parseString() { // (char *string, int *intArray) {
	printf("ERROR");
	exit(1);
}

int userMenu() {
	printf("Enter number of numbers: ");
	size_t arrSize = ReadUnsignedInteger();
	
	int *intArray = ec_malloc(arrSize * sizeof(int));
	readUserInput(intArray, arrSize);
	
	intArray = mergeSort(intArray, arrSize);
	
	printIntArray(intArray, arrSize);
	
	free(intArray);
	
	return 0;
}

int processFile(char *arg1) {
	// int *intArray = ec_malloc(arrSize * sizeof(int));
	
	char *fileString;
	fileString = readFile(arg1);
	
	parseString(); // (fileString, intArray);
	
	free(fileString);

	return 0;
}
