#include <iostream>
#include <ctime>
#include <omp.h>

using namespace std;

/**
 *  An application to measure the gain in computationtime by vector optimization and by
 *  multithreading realized with openMP
 */
int main()
{
    //allocate heap-memory for the arrays of size "size"
    int size = 50000;
    int* a = new int[size];
    int* b = new int[size];
    int* c = new int[size];

    //fill the knows arrays
    #pragma omp parallel for
    for(int i = 0; i < size; i++)
    {
        a[i] = i;
        b[i] = size - 1 - i;
    }

    //measure starttime: omp_time is a "real" seconds timestamp, clock is accumulated CPU-Clocks over ALL threads
    double ompTimeStart = omp_get_wtime();
    clock_t cl = clock();

    //(parallel) computation of c = a * a
    #pragma omp parallel for
    for(int i = 0; i < size; i++)
    {
        c[i] = a[i] * b[i];
    }
    //measure passed time
    cl = clock() - cl;
    double runtime = 1000 * (double)cl/ CLOCKS_PER_SEC;
    double ompTime = 1000 *(omp_get_wtime() - ompTimeStart);

    //print the result
    cout << runtime << "\t" << ompTime << endl;

    //cleanup memory
    delete [] a;
    delete [] b;
    delete [] c;

    return 0;
}
