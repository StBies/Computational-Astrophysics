/*
 * main.c
 *
 *  Created on: Dec 9, 2015
 *      Author: Stefan
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	int x = 0;
	srand(1337);
	for(int i = 0; i < 1e6; i++)
	{
		x = rand();
		printf("%d\n",x);
	}
	return 0;
}
