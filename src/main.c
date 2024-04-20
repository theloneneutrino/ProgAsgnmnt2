#include "../headers/main.h"

int main(int argc, char *argv[]) {
	//int array[SIZE];
	int status = 0;
	
	switch(argc) {
	case 1:
		status = userMenu();
		break;
	case 2:
		status = processFile(argv[1]);
		break;
	default:
		printUsage(argv[0]);
		status = 1;
		break;
	}
	
	exit(status);
}
