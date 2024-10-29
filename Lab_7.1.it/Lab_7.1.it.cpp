#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** q, const int rowCount, const int colCount, const int Low,
const int High);
void Print(int** q, const int rowCount, const int colCount);
void Sort(int** q, const int rowCount, const int colCount);
void Change(int** q, const int row1, const int row2, const int colCount);
void Calc(int** q, const int rowCount, const int colCount, int& S, int& k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -26;
	int High = 23;
	int rowCount = 8;
	int colCount = 6;
	int** q = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		q[i] = new int[colCount];
	Create(q, rowCount, colCount, Low, High);
	Print(q, rowCount, colCount);
	Sort(q, rowCount, colCount);
	Print(q, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(q, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(q, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] q[i];
	delete[] q;
	return 0;
}
void Create(int** q, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			q[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** q, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << q[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** q, const int rowCount, const int colCount) {
	for (int i0 = 0; i0 < colCount - 1; i0++) {
		for (int i1 = 0; i1 < colCount - i0 - 1; i1++) {
			if ((q[0][i1] > q[0][i1 + 1]) ||
				(q[0][i1] == q[0][i1 + 1] && q[1][i1] < q[1][i1 + 1]) ||
				(q[0][i1] == q[0][i1 + 1] && q[1][i1] == q[1][i1 + 1] && q[2][i1] > q[2][i1 + 1])) {
				Change(q, i1, i1 + 1, rowCount);
			}
		}
	}
}

void Change(int** q, const int col1, const int col2, const int rowCount) {
	for (int i = 0; i < rowCount; i++) {
		int tmp = q[i][col1];
		q[i][col1] = q[i][col2];
		q[i][col2] = tmp;
	}
}


void Calc(int** q, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if(!(q[i][j]>0 && q[i][j]%2==0))
			{
				S += q[i][j];
				k++;
				q[i][j] = 0;
			}
}