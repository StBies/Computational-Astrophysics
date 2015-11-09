#include <iostream>
#include <omp.h>

using namespace std;

/**
 *  An application to measure the gain in computationtime by vector optimization and by
 *  multithreading realized with openMP
 *
 *  @author Stefan
 *  @date Nov. 1, 2015
 *
 *  @version 0.9
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

    //measure starttime: omp_time is a "real" seconds timestamp
    double ompTimeStart = omp_get_wtime();

    //(parallel) computation of c = a * b
    #pragma omp parallel for
    for(int i = 0; i < size; i++)
    {
        c[i] = a[i] * b[i];
    }
    //measure passed time
    double ompTime = 1000 *(omp_get_wtime() - ompTimeStart);

    //print the result
    cout << ompTime << endl;

    //cleanup memory
    delete [] a;
    delete [] b;
    delete [] c;

    return 0;
}
