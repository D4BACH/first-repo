#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 1000

int **vectintomatrix(int *V, int len) {
    int **p;
    int x = sqrt(len);

    if ((len-(x*x)) > 0) {
        p = (int**)malloc(++x * sizeof(int *));
        for (int i = 0; i < x; ++i)
            p[i] = (int *)malloc(x * sizeof(int));
    }
    else {
        p = (int**)malloc(x*sizeof(int *));
        for (int i = 0; i < x; ++i)
            p[i] = (int *)malloc(x*sizeof(int));
    }       
    for (int j = 0, y = 0; j < x; j++)
        for (int k = 0; k < x; k++, y++) {
           if ( y >= len) 
                p[j][k] = 0;
           else 
                p[j][k] = V[y];
        }

    return p;
}

void rotate(int **A, int lim) {
    for (int i = 0, n = sqrt(lim); i < n; i++) {
        for (int j = i; j < lim-i-1; j++) {
            int temp = A[i][j];
            A[i][j] = A[lim-j-1][i];
            A[lim-j-1][i] = A[lim-i-1][lim-j-1];
            A[lim-i-1][lim-j-1] = A[j][lim-i-1];
            A[j][lim-i-1] = temp;
        }
   }        
}

void printm(int **mtr, int d) {
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) 
            printf("%3d", mtr[i][j]);
        putchar(10);
    }
}

int simple_getint(void) {
    int i;
    scanf("%d", &i);
    return i;
}

int main(void) 
{
   int array[MAX], c, b;
   while ((c = simple_getint()) != 99) 
       array[b++] = c;
   int **matrix = vectintomatrix(array, b);
   c = sqrt(b);
   if ((b - (c*c)) > 0)
       c++;
   printf("\033[0;31m");
   printf("turning into a %d by %d matrix..............100%%\n", c, c);
   printm(matrix, c);
   rotate(matrix, c);
   printf("retating the matrix.......................100%%\n");
   printm(matrix, c);
}
