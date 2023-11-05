#include <stdio.h>

// Function to input a matrix from the user
void inputMatrix(int matrix[][100], int rows, int cols, const char *name) {
    printf("Enter elements for matrix %s:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to add two matrices
void addMatrices(int mat1[][100], int mat2[][100], int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to search for an element in a matrix
int searchMatrix(int matrix[][100], int rows, int cols, int key) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == key) {
                return 1; // Element found
            }
        }
    }
    return 0; // Element not found
}

int main() {
    int rows, cols;
    
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);
    
    int matrix1[100][100], matrix2[100][100], result[100][100];
    
    inputMatrix(matrix1, rows, cols, "A");
    inputMatrix(matrix2, rows, cols, "B");
    
    addMatrices(matrix1, matrix2, result, rows, cols);
    
    printf("Resultant Matrix (A + B):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    
    int searchElement;
    printf("Enter an element to search in the resultant matrix: ");
    scanf("%d", &searchElement);
    
    if (searchMatrix(result, rows, cols, searchElement)) {
        printf("%d found in the resultant matrix.\n", searchElement);
    } else {
        printf("%d not found in the resultant matrix.\n", searchElement);
    }

    return 0;
}
