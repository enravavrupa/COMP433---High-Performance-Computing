#include<stdio.h>

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}}; 
    int c[2][2] = {{0, 0}, {0, 0}};
    int N = 2;

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            for(int k = 0; k<N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}