#include <stdio.h>
#include <stdlib.h>

void testAnsiRand()
{
	unsigned int number = 1e3;
	srand(42);

	FILE* saveFile = fopen("./randomnumbers.txt","w+");

	for(int i = 0; i < number; i++)
	{
		fprintf(saveFile,"%f\t%f\t%f\n",rand()/(double)RAND_MAX,
				rand()/(double)RAND_MAX,
				rand()/(double)RAND_MAX);
	}
	fclose(saveFile);
}