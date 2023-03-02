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
    for(int i = 0; i < m; i++){
        free(mat[i]);
    }
    free(mat);
}

void matrixOneBigArray(int n, int m){
    float* mat = malloc((n * m) * sizeof(float));
    float num = 1.0;

    float** matBig  = (float**)malloc(m * sizeof(float*));

    for(int i = 0; i < m * n; i++){
        mat[i] = num;
        num += 1.0;
    }
    for(int i = 0; i < n; i++){
        matBig[i] = &mat[i*m];
    }
    for(int i = 0; i < m; i++){
        for(int t = 0; t < n; t++){
            printf("%f\t", matBig[t][i]);
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++){
        for(int t = 0; t < m; t++){
            printf("%f\t", matBig[i][t]);
        }
        printf("\n");
    }
    free(mat);
    free(matBig);
}

int main(int argc, char** argv){
    matrixArrayOfArrays(N, M);
    printf("\n");
    matrixOneBigArray(N, M);
    return 0;
}