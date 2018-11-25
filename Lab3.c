//Purpose :

/*	Arrange columns items
	the matrix by ​​increasing their values methods insertion sort
	fi(aij) - the sum of the elements in each row above the main one
	diagonal matrix; F(fi(aij)) - geometric mean
	the value of fi(aij) */

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define SIZE_OF_MATRIX 5
#define SIZE_OF_ARRAY SIZE_OF_MATRIX - 1
#define TRUE 1
#define FALSE 0

void insertionSortColumnMatrixByIncrease(int matrix[][SIZE_OF_MATRIX]);
void inputOfMatrix(int matrix[][SIZE_OF_MATRIX]);
void outputOfMatrix(int matrix[][SIZE_OF_MATRIX]);
void outputOfArray(int array[], const int size_of_array);
void calculateSumElementsEachRowMatrixOverMainDiagonal(int matrix[][SIZE_OF_MATRIX],
	int array[]);
float calculateGeometricMeanInArray(int array[],const int size_of_array);

int main()
{
	int matrix[SIZE_OF_MATRIX][SIZE_OF_MATRIX];
	int arraySumElementsOfMatrix[SIZE_OF_ARRAY];
	inputOfMatrix(matrix);
	printf("You  entered matrix : \n");
	outputOfMatrix(matrix);
	insertionSortColumnMatrixByIncrease(matrix);
	printf("\nSorted column matrix elements as their values grow : \n");
	outputOfMatrix(matrix);
	calculateSumElementsEachRowMatrixOverMainDiagonal(matrix, 
		arraySumElementsOfMatrix);
	printf("\nAn array of sum of elements in each row over " 
		"the main diagonal of the matrix : \n");
	outputOfArray(arraySumElementsOfMatrix, SIZE_OF_ARRAY);
	printf("\nGeometric mean = %f\n", 
		calculateGeometricMeanInArray(arraySumElementsOfMatrix, SIZE_OF_ARRAY));
	printf("\nPress any key to end program ...\n");
	_getch();
	return 0;
}

void insertionSortColumnMatrixByIncrease(int matrix[][SIZE_OF_MATRIX])
{
	int key, i;
	for (int j = 0; j < SIZE_OF_MATRIX; ++j)
	{
		for (int k = 1; k < SIZE_OF_MATRIX; ++k)
		{
			key = matrix[k][j];
			for (i = k - 1; i >= 0 && matrix[i][j] > key; --i){
					matrix[i + 1][j] = matrix[i][j];
			}
			matrix[i + 1][j] = key;
		}
	}
	return;
}

void inputOfMatrix(int matrix[][SIZE_OF_MATRIX])
{
	printf("Enter the matrix elements : \n\n");
	for (int i = 0; i < SIZE_OF_MATRIX; ++i){
		for (int j = 0; j < SIZE_OF_MATRIX; ++j){
			printf("Enter the matrix element [%d][%d] : ", i + 1, j + 1);
				scanf_s("%d",&matrix[i][j]);
        }
		putchar('\n');
	}
	return;
}

void outputOfMatrix(int matrix[][SIZE_OF_MATRIX])
{
	putchar('\n');
	for (int i = 0; i < SIZE_OF_MATRIX; ++i) {
		for (int j = 0; j < SIZE_OF_MATRIX; ++j) {
			printf("%d\t", matrix[i][j]);
		}
		putchar('\n');
	}
	return;
}

void outputOfArray(int array[], const int size_of_array)
{
	putchar('\n');
	for (int i = 0; i < size_of_array; ++i) {
		printf("%d\t", array[i]);
	}
	putchar('\n');
	return;
}

void calculateSumElementsEachRowMatrixOverMainDiagonal(int matrix[][SIZE_OF_MATRIX],int array[])
{
	int isElementOverMainDiagonal = FALSE;
	int Sum = 0;
	for (int i = 0; i < SIZE_OF_MATRIX; ++i) {
		for (int j = 0; j < SIZE_OF_MATRIX; ++j) {
			if (j > i) {
				isElementOverMainDiagonal = TRUE;
				Sum += matrix[i][j];
			}
		}
		if (isElementOverMainDiagonal)
			array[i] = Sum;
		Sum = 0;
		isElementOverMainDiagonal = FALSE;
	}
	return;
}

float calculateGeometricMeanInArray(int array[], const int count_of_elements)
{
	float geometricMean = 1;
	for (int i = 0; i < count_of_elements; ++i) {
		geometricMean *= array[i];
	}
	geometricMean = pow(geometricMean, 1.0 /(double)count_of_elements);
	return  geometricMean;
}

