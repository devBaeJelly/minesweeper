#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    char** matrix = malloc(sizeof(char*)*m);
    for (int i = 0; i < m; i++) {
        matrix[i] = malloc(sizeof(char) * n + 1);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", matrix[i]);
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            if (matrix[i][j] == '*')
                printf("*");
            else if (matrix[i][j] == '.') {
                
                if (i == 0) {
                    if (j == 0 || j == n - 1) {
                        goto Calcu;
                    }
                    for (int row = i; row <= i + 1; row++) {
                        for (int col = j-1; col <= (j-1)+2; col++) {
                            if (matrix[row][col] == '*') count++;
                        }
                    }
                }
                else if (i == m - 1) {
                    if (j == 0 || j == n - 1) {
                        goto Calcu;
                    }
                    for (int row = i-1; row <= i; row++) {
                        for (int col = j - 1; col <= (j - 1) + 2; col++) {
                            if (matrix[row][col] == '*') count++;
                        }
                    }
                }
 
                Calcu:
                if (j == 0) {
                    if (i == 0) {
                        if (matrix[i][j + 1] == '*') count++;
                        if (matrix[i+1][j] == '*') count++;
                        if (matrix[i + 1][j+1] == '*') count++;
                    }
                    else if (i == m-1) {
                        if (matrix[i][j + 1] == '*') count++;
                        if (matrix[i - 1][j] == '*') count++;
                        if (matrix[i - 1][j + 1] == '*') count++;
                    }
                    else {
                        for (int row = i - 1; row <= (i - 1) + 2; row++) {
                            for (int col = j; col <= 1; col++) {
                                if (matrix[row][col] == '*') count++;
                            }
                        }
                    }
                }
                else if (j == n-1) {
                    
                    if (i == 0) {
                        if (matrix[i][j - 1] == '*') count++;
                        if (matrix[i + 1][j] == '*') count++;
                        if (matrix[i + 1][j - 1] == '*') count++;
                    }
                    else if (i == m - 1) {
                        if (matrix[i][j - 1] == '*') count++;
                        if (matrix[i - 1][j] == '*') count++;
                        if (matrix[i - 1][j - 1] == '*') count++;
                    }
                    else {
                        for (int row = i - 1; row <= (i - 1) + 2; row++) {
                            for (int col = j-1; col <= n-1; col++) {
                                if (matrix[row][col] == '*') count++;
                            }
                        }
                    }
                }
                
                if(i!=0 && i!=n-1 && j!=0 && j!=m-1) {
                    for (int row = i - 1; row <= (i - 1) + 2; row++) {
                        for (int col = j - 1; col <= (j - 1) + 2; col++) {
                            if (matrix[row][col] == '*') count++;
                        }
                    }
                }
                printf("%d", count);


            }
            else {
                printf("wrong char\n");
            }
            
        }
        printf("\n");
    }

   

    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);


    return 0;
}