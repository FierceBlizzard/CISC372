#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 6

void matrixArrayOfArrays(int n, int m){
    float** mat = malloc(m * sizeof(float*));
    float num = 1.0;

    for(int i = 0; i < m; i++){
        mat[i] = malloc(n * sizeof(float));
    }
    for(int i = 0; i < m; i++){
        for(int t = 0; t < n; t++){
            mat[i][t] = num;
            num += 1.0;
        }
    }
    for(int i = 0; i < m; i++){
        for(int t = 0; t < n; t++){
            printf("%f\t",mat[i][t]);
        }
        printf("\n");
    }
    //transpose
    for(int i = 0; i < n; i++){
        for(int t = 0; t < m; t++){
            printf("%f\t",mat[t][i]);
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++){
        free(mat[i]);
    }
}

void matrixOneBigArray(int n, int m){
    float* mat = malloc((n * m) * sizeof(float));
    float num = 1.0;

    for(int i = 0; i < m * n; i++){
        mat[i] = num;
        num += 1.0;
    }
    for(int i = 0; i < m; i++){
        for(int t = 0; t < n; t++){
            printf("%f\t", mat[t * m + i]);
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++){
        for(int t = 0; t < m; t++){
            printf("%f\t", mat[i * m + t]);
        }
        printf("\n");
    }
    free(mat);
}

int main(int argc, char** argv){
    matrixArrayOfArrays(N, M);
    printf("\n");
    matrixOneBigArray(N, M);
    return 0;
}