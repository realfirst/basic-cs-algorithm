
//////////////////////////////////////////////////////////////
// START_IP_HEADER                                          //
//                                                          //
// Written by Jingen Ding                                   //
// Contact <dingje.gm@gmail.com> for comments & bug reports //
//                                                          //
// END_IP_HEADER                                            //
//////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

static int a[] = {9, 11, 8, 1, 5, 6, 16, 10, 2 ,4};
static int n = SIZE;

void print(int a[], int size);
void merge1(int lo, int m, int hi);      // straightforward variant
void merge2(int lo, int m, int hi);      // efficient variant
void merge3(int lo, int m, int hi);
void mergesort1(int lo, int hi);
void mergesort2(int lo, int hi);
void mergesort3(int lo, int hi);


int main(int argc, char **argv) {
  print(a, n);
  mergesort1(0, SIZE-1);
  print(a, n);
}

void print(int a[], int size) {
  for (int i = 1; i < size; i++) {
	std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

void mergesort1(int lo, int hi) {
  if (lo < hi) {
    int m = (lo + hi) / 2;
    mergesort1(lo, m);
    mergesort1(m+1, hi);
    merge1(lo, m, hi);
  }
}

// straightforward variant
void merge1(int lo, int m, int hi) {
  int i, j, k;
  int b[hi];

  // copy both halves of a to auxiliary array b
  for (i = lo; i <= hi; i++) {
	b[i] = a[i];
  }

  i = lo; j = m+1; k = lo;
  // copy back next-greatest element at each time
  while (i <= m && j <= hi) {
	if (b[i] <= b[j]) {
      a[k++] = b[i++];
    } else {
      a[k++] = b[j++];
    }
  }

  // copy back remaining elements of first half (if any)
  while (i <= m) {
	a[k++] = b[i++];
  }
}

void mergesort2(int lo, int hi) {
  if (lo < hi) {
    int m = (lo + hi) / 2;
    mergesort2(lo, m);
    mergesort2(m+1, hi);
    merge2(lo, m, hi);
  }
}

// efficient variant
void merge2(int lo, int m, int hi) {
  int i, j, k;
  int b[m];
  i = 0;
  j = lo;
  // copy first half of array a to auxiliary array b
  while (j <= m) {
	b[i++] = a[j++];
  }

  i = 0;
  k = lo;
  // copy back next-greatest element at each time
  while (k < j && j <= hi) {
	if (b[i] <= a[j]) {
      a[k++] = b[i++];
    } else {
      a[k++] = a[j++];
    }
  }

  // copy back remaining elements of first half (if any)
  while (k < j) {
	a[k++] = b[i++];
  }
}

// Bitonic variant
void merge3(int lo, int m, int hi) {
  int i = lo, j = hi, k = lo;
  int b[hi];
  
  // copy first half of array a to auxiliary array b
  while (i <= m) {
	b[k++] = a[i++];
  }

  // copy second half of array a to auxiliary array b,
  // but in opposite order
  while (j > m) {
	b[k++] = a[j--];
  }

  i = lo; j = hi; k = lo;
  // copy back next-greatest element at each time
  // until i and j cross
  while (i <= j) {
	if (b[i] <= b[j]) {
      a[k++] = b[i++];
    } else {
      a[k++] = b[j--];
    }
  } 
}

void mergesort3(int lo, int hi) {
  if (lo < hi) {
    int m = (lo + hi) / 2;
    mergesort3(lo, m);
    mergesort3(m+1, hi);
    merge3(lo, m, hi);
  }
}

