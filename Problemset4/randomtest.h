#include <stdio.h>
#include <stdlib.h>
#ifdef gsl
#include <gsl/gsl_rng.h>
#endif


void testAnsiRand()
{
	unsigned int number = 1e4;
#ifndef gsl
	srand(42);
	FILE* saveFile = fopen("./ANSI_random.txt", "w+");
	for (int i = 0; i < number; i++)
	{
		fprintf(saveFile, "%f\t%f\t%f\n", rand() / (double) RAND_MAX,
				rand() / (double) RAND_MAX, rand() / (double) RAND_MAX);
	}
	fclose(saveFile);
#endif
#ifdef gsl
	FILE* saveFile = fopen("./GSL_random.txt","w+");
	const gsl_rng_type* T;
	gsl_rng* generator;
	T = gsl_rng_default;
	generator = gsl_rng_alloc(T);
	gsl_rng_env_setup();

	for (int i = 0; i < number; i++)
	{
		fprintf(saveFile, "%f\t%f\t%f\n",gsl_rng_uniform(generator),gsl_rng_uniform(generator),gsl_rng_uniform(generator));
	}
	gsl_rng_free (generator);
	fclose(saveFile);
#endif
}
