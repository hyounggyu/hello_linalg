#include <stdio.h>
#include <stdlib.h>

#include "linalg_lu.h"

const double data[9] = {0, 2, 3, 4, 5, 6, 7, 8, 9};
const int kN = 3;
const double kTol = 1e-6;

void print_perm(int *p, int n) {
  printf("p = [ ");
  for (int i = 0; i < n + 1; i++) {
    printf("%d ", p[i]);
  }
  printf("]\n\n");
  for (int i = 0; i < n; i++) {
    printf("[ ");
    for (int j = 0; j < n; j++) {
      printf("%d ", i == p[j]);
    }
    printf("]\n");
  }
}

void print_mat(double **a, int n) {
  for (int i = 0; i < n; i++) {
    printf("[ ");
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
  p = (int *)calloc(kN + 1, sizeof(int));

  for (int i = 0; i < kN; i++) {
    for (int j = 0; j < kN; j++) {
      a[i][j] = data[i * kN + j];
    }
  }

  printf("Initial matrix:\n");
  print_mat(a, kN);
  printf("\n");

  LUPDecompose(a, kN, kTol, p);

  printf("LUPDecompose:\n");
  print_mat(a, kN);
  printf("\n");

  printf("Permutation matrix:\n");
  print_perm(p, kN);
}
