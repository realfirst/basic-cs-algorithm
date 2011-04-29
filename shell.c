#include <stdio.h>

#define MAX_NUMBER  11

void shell_sort(int*, int);

int main(int argc, char *argv[])
{
  int i, length;
  int a[MAX_NUMBER] = {3, 11, 6, 4, 9, 5, 7, 8, 10, 2, 1};
  
  length = sizeof(a) / sizeof(int);
  printf ("length of the array is %d\n", length);
  printf ("Array before Shell sort\n");
  for (i = 0; i < length; i++)
    {
      printf ("%d ", a[i]);
    }
  printf ("\n");
  shell_sort(a, length);
  printf ("After sorted.\n");
  for (i = 0; i < length; ++i)
    {
      printf ("%d ", a[i]);
    }
  return 0;
}

void shell_sort(int* a, int n)
{
  int i, j, k, h, v;
  int cols[16] = {1291276, 463792, 198768, 86961, 33936,
		  12776, 4592, 1968, 861, 336, 112, 48, 21, 7, 3, 1};

  for (k = 0; k < 16; k++)
    {
      h = cols[k] ;
      for (i = h; i < n; i++)
	{
	  v = a[i];
	  j = i;
	  while (j >= h && a[j-h] > v)
	    {
	      a[j] = a[j-h];
	      j = j-h;
	    }
	  a[j] = v;
	}
    }
}


