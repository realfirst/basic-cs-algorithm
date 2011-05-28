#include <stdio.h>
#define SIZE 10

static int a[] = {9, 11, 8, 1, 5, 6, 16, 10, 2 ,4};
static int n = SIZE;


void buildheap();
void downheap(int v);
void exchange(int i, int j);
void print(int a[], int size);

void heapsort() {
  print(a, SIZE);
  buildheap();
  print(a, SIZE);
  while (n > 1) {
	n--;
    exchange(0, n);
    downheap(0);
  }
  print(a, SIZE);
}

void buildheap() {
  int v;
  for (v = n / 2 - 1; v >= 0; v--) {
	downheap(v);
  }
}

void downheap(int v) {
  int w = 2 * v + 1;
  while (w < n) {
	/* is there a second descendant? */
    if (w + 1 < n) {
      if (a[w+1] > a[w]) {
        w++;                            /* w is the descendant of v with maximum label */
      }
    }
    if (a[v] >= a[w]) return;         /* v has heap property */
    /* otherwise */
    exchange(v, w);                   /* exchange labels of v and w */
    v = w;                            /* continue */
    w = 2 * v + 1;
  }
}



void exchange(int i, int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void print(int a[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf ("%d ", a[i]);   
  }
  printf ("\n");
}

int main(int argc, char **argv) {
  heapsort();
  return 0;
}



