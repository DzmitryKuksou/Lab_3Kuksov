#include"iostream";
using namespace std;
void EnterMatrix(int**, int n);
void SortedMatrix(int**, int**, int n);
int Maxelement(int**, int, int, int, int);
void DisplayMatrix(int**, int);
int** AllocMemory(int n);
int EnterDimention(int n);
int main()
{
	int n = 100;
	cout << "enter size of matrix:\n";
	n = EnterDimention(n);
	int** matrix1 = AllocMemory(n);
	EnterMatrix(matrix1, n);
	DisplayMatrix(matrix1, n);
	cout << "-----------------------------------------------\n";
	int** matrix2 = AllocMemory(n);
	SortedMatrix(matrix1, matrix2, n);
	DisplayMatrix(matrix2, n);
	system("pause");
}
int EnterDimention(int n)
{
	int k;
	while (true)
	{
		cin >> k;
		if (k > 0 && k <= n)
			return k;
		cout << "0<k<100" << endl;
	}
}
int** AllocMemory(int n)
{
	int**matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int [n];
	return matrix;
}
void DisplayMatrix(int**matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(5);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}
void EnterMatrix(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = rand() % 100;
		}
	}
}
void SortedMatrix(int**matrix1, int**matrix2, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix2[i][j] = Maxelement(matrix1, matrix1[i][j], i, j, n);
		}
	}
}
int Maxelement(int** matrix1, int a, int k, int l, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((l > j && k - l <= i - j && k >= i) || (l > j && k + l >= i + j && k <= i) || (l < j && k + l <= i + j && k >= i) || (l < j && k - l >= i - j && k <= i))
			{
				if (matrix1[i][j] > a)
				a = matrix1[i][j];
			}

		}
	}
	return a;
}