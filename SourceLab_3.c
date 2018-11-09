/*31  65  –83  - 2  - 85
  9  - 2   11  - 4    70
  52  73  - 8  - 1    60
  57  83  - 1   82    50
  1  - 3  - 2   78   - 9*/
  /*Впорядкувати елементи стовпців
  матриці за зростанням їх значень методом вставки*/
  /*fi(aij) - сума елементів у кожному рядку над головною
  діагоналлю матриці; F(fi(aij)) - середнє геометричне
  значення fi(aij)*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define N 5
#define TRUE 1
#define FALSE 0

void insertionSortColMatrix(int matrix[][N]);
void inputOfMatrix(int matrix[][N]);
void outputOfMatrix(int matrix[][N]);
void outputOfArray(int array[], const int size_of_array);
void calcSumElementsEachRowMatrixOverMainDiagonal(int matrix[][N],int array[]);
float calcGeometricMean(int array[],const int size_of_array);

int main()
{
	int matrix[N][N];
	int arraySumElements[N - 1];/*зберігає суму елементів у кожному рядку над головною 
	діагоналлю матриці.*/
	inputOfMatrix(matrix);
	printf("You  entered matrix : \n");
	outputOfMatrix(matrix);// вивід непосортованої матриці
	insertionSortColMatrix(matrix);
	printf("\nSorted column matrix elements as their values grow : \n");
	outputOfMatrix(matrix);
	calcSumElementsEachRowMatrixOverMainDiagonal(matrix, arraySumElements);
	printf("\nAn array of sum of elements in each row over the main diagonal of the matrix : \n");
	outputOfArray(arraySumElements,N - 1);
	printf("\nGeometric mean = %f\n", calcGeometricMean(arraySumElements,N - 1));
	printf("\nPress any key to end program ...\n");
	_getch();
	return 0;
}

void insertionSortColMatrix(int matrix[][N])
{
	int key, i;
	for (int j = 0; j < N; ++j)
	{
		for (int k = 1; k < N; ++k)
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

void inputOfMatrix(int matrix[][N])
{
	printf("Enter the matrix elements : \n\n");
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			printf("Enter the matrix element [%d][%d] : ", i + 1, j + 1);
				scanf_s("%d",&matrix[i][j]);
        }
		putchar('\n');
	}
	return;
}

void outputOfMatrix(int matrix[][N])
{
	putchar('\n');
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
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

void calcSumElementsEachRowMatrixOverMainDiagonal(int matrix[][N],int array[])
{
	int flag = FALSE;
	int Sum = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j > i) {
				flag = TRUE;
				Sum += matrix[i][j];
			}
		}
		if (flag)
			array[i] = Sum;
		Sum = 0;
		flag = FALSE;
	}
	return;
}

float calcGeometricMean(int array[], const int count_of_elements)
{
	float geometricMean = 1;
	for (int i = 0; i < count_of_elements; ++i) {
		geometricMean *= array[i];
	}
	geometricMean = pow(geometricMean, 1.0 /(double)count_of_elements);
	return  geometricMean;
}

