#include <stdio.h>
#include <stdlib.h>

void testAnsiRand()
{
	unsigned int number = 1e4;
	srand(42);

	FILE* saveFile = fopen("./ANSI_random.txt","w+");

	for(int i = 0; i < number; i++)
	{
		fprintf(saveFile,"%f\t%f\t%f\n",rand()/(double)RAND_MAX,
				rand()/(double)RAND_MAX,
				rand()/(double)RAND_MAX);
	}
	fclose(saveFile);
}
