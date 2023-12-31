#include <stdio.h>
#include <stdlib.h>

#include "linalg_lu.h"

const double data[9] = {0, 2, 3, 4, 5, 6, 7, 8, 9};
const int kN = 3;
const double kTol = 1e-6;

void print_mat(double **a, int n) {
  for (int i = 0; i < n; i++) {
    printf("[");
    for (int j = 0; j < n; j++) {
      printf("%f ", a[i][j]);
    }
    printf("]\n");
  }
}

int main() {
  double **a;
  int *p;

  a = (double **)calloc(kN, sizeof(double *));
  for (int i = 0; i < kN; i++) {
    a[i] = (double *)calloc(kN, sizeof(double));
  }
  p = (int *)calloc(kN, sizeof(int));

  for (int i = 0; i < kN; i++) {
    for (int j = 0; j < kN; j++) {
      a[i][j] = data[i * kN + j];
    }
  }

  print_mat(a, kN);

  LUPDecompose(a, kN, kTol, p);

  print_mat(a, kN);
}
