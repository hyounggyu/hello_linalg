#include <stdio.h>
#include <stdlib.h>

#include "linalg_lu.h"

const double a_data[9] = {3, 2, 0, 1, -1, 0, 0, 5, 1};
const int kN = 3;
const double kTol = 1e-6;

void print_perm(int *p, int n) {
  for (int i = 0; i < n; i++) {
    printf("[ ");
    for (int j = 0; j < n; j++) {
      printf("%+3d ", i == p[j]);
    }
    printf("]\n");
  }
}

void print_mat(double **a, int n) {
  for (int i = 0; i < n; i++) {
    printf("[ ");
    for (int j = 0; j < n; j++) {
      printf("%+3.5f ", a[i][j]);
    }
    printf("]\n");
  }
}

void print_ivec(int *v, int n) {
  printf("[ ");
  for (int i = 0; i < n; i++) {
    printf("%+3d ", v[i]);
  }
  printf("]\n");
}

void print_dvec(double *v, int n) {
  printf("[ ");
  for (int i = 0; i < n; i++) {
    printf("%+3.5f ", v[i]);
  }
  printf("]\n");
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
      a[i][j] = a_data[i * kN + j];
    }
  }

  printf("Matrix A is\n");
  print_mat(a, kN);
  printf("\n");

  LUPDecompose(a, kN, kTol, p);

  printf("L - I + U is\n");
  print_mat(a, kN);
  printf("\n");

  printf("Permutation data:\n");
  print_ivec(p, kN);
  printf("\n");

  printf("P is\n");
  print_perm(p, kN);
  printf("\n");

  double x[kN];
  double b[kN] = {2, 4, -1};

  printf("Solve Ax = b:\n\n");
  printf("b is,\n");
  print_dvec(b, kN);
  printf("\n");

  LUPSolve(a, p, b, kN, x);

  printf("x is,\n");
  print_dvec(x, kN);
  printf("\n");
}
