/*
 * x86_64-apple-darwin13.4.0-clang -isystem ${CONDA_PREFIX}/include 
 *                                 -fopenmp 
 *                                 openmp.c -o bin/openmp
 * 
*/

#include <omp.h>
#include <stdio.h>

int main() {
  int nthreads = omp_get_max_threads();
  printf("Maximum number of threads is %i\n", omp_get_max_threads());
  
  omp_set_num_threads(nthreads);

#pragma omp parallel
  printf("Hello World\n");
}
