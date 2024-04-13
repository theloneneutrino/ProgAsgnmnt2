#include "../headers/main.h"

int main(int argc, char *argv[]) {
	
	switch(argc)
	{
	case 2:
		readFile(argv[1]);
		break;
	default:
		printUsage(argv[0]);
		break;
	}
	
	exit(0);
}
