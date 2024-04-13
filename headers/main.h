#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define NOT_IMP printf("ERROR: feature not implemented yet.\n"); \
				exit(-1);

void printUsage(char * arg0)
{
	printf("Usage: %s <file>\n", arg0);
}

int mergeSort(int array[], int arraySize)
{
	NOT_IMP
}

int readFile(char * fileit)
{
	FILE *myFile;
	char c;
	myFile = fopen( fileit, "r" );
	
	if (myFile == NULL) {
		printf("ERROR 404: file not found.\n");
		return -1;
	}
	
    c = fgetc( myFile );
	
	while( !feof( myFile ) ) {
		printf( "%c", c );
    	c = fgetc( myFile );
	}
	
    fclose(myFile);
	
	return 0;
}
