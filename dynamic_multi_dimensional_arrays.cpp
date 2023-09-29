#include <iostream>	
#include <conio.h>
using namespace std;

void print(int **arr,const int &row,const int &col) {
	for (size_t i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
void fill(int** arr, const int& row, const int& col, int min = 1, int max = 30) {
	for (size_t i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			arr[i][j] = min + rand() % (max - min + 1);
		}
	}
}
void addColByIndex(int**& arr, const int& row, int& col, int indexCol) {
	if (indexCol < 0 || indexCol > col) {
		cout << "Index error" << endl;
		return;
	}
	int** tmp = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		tmp[i] = new int[col+1];
	}
	for (size_t i = 0; i < row; i++)
	{
		tmp[i][indexCol] = {};
	}
	for (size_t i = 0; i < col; i++)
	{
		if (i >= indexCol) {
			for (int j = 0; j < row; j++) {
				tmp[j][i + 1] = arr[j][i];
			}
		}
		else {
			for (int j = 0; j < row; j++) {
				tmp[j][i] = arr[j][i];
			}
		}
	}
	++col;
	delete[]arr;
	arr = tmp;
}

void delColByIndex(int**& arr, const int& row, int& col, int indexCol) {
	if (indexCol < 0 || indexCol > col) {
		cout << "Index error" << endl;
		return;
	}
	int** tmp = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		tmp[i] = new int[col - 1];
	}
	for (size_t i = 0; i < col; i++)
	{
		if (i < indexCol) {
			for (int j = 0; j < row; j++) {
				tmp[j][i] = arr[j][i];
			}
		}
		else if (i == indexCol) {
			continue;
		}
		else {
			for (int j = 0; j < row; j++) {
				tmp[j][i-1] = arr[j][i];
			}
		}
	}
	--col;
	delete[]arr;
	arr = tmp;
}
int** createMatrix(const int& row, const int& col) {
	int** arr = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	return arr;
}
void up(int **&arr, const int row, const int col) {

	int** tmp = createMatrix(row, col);

	tmp[row - 1] = arr[0];
	for (size_t i = 1; i < row; i++)
	{
		tmp[i-1] = arr[i];
	}
	delete[]arr;
	arr = tmp;
}
void down(int**& arr, const int row, const int col) {

	int** tmp = createMatrix(row, col);

	tmp[0] = arr[row - 1];
	for (size_t i = 0; i < row - 1; i++)
	{
		tmp[i + 1] = arr[i];
	}
	delete[]arr;
	arr = tmp;
}

void left(int**& arr, const int row, const int col) {

	int** tmp = createMatrix(row, col);

	for (size_t i = 0; i < row; i++)
	{
		tmp[i][col - 1] = arr[i][0];
		for (size_t j = 1; j < col; j++)
		{
			tmp[i][j - 1] = arr[i][j];
		}
	}
	delete[]arr;
	arr = tmp;
}
void right(int**& arr, const int row, const int col) {

	int** tmp = createMatrix(row, col);

	for (size_t i = 0; i < row; i++)
	{
		tmp[i][0] = arr[i][col - 1];
		for (size_t j = 0; j < col - 1; j++)
		{
			tmp[i][j + 1] = arr[i][j];
		}
	}
	delete[]arr;
	arr = tmp;
}

int main()
{
    int row = 4, col = 4;
 //   int** arr = new int* [row];
	//for (size_t i = 0; i < row; i++)
	//{
	//	arr[i] = new int[col];
	//}
	//fill(arr, row, col);
	////print(arr, row, col);
	//addColByIndex(arr, row, col, 1);
	//print(arr, row, col);
	//delColByIndex(arr, row, col, 1);
	//print(arr, row, col);
	int** Matrix = createMatrix(row, col);
	fill(Matrix, row, col);
	print(Matrix, row, col);
	//up(Matrix, row, col);
	//down(Matrix, row, col);
	//left(Matrix, row, col);
	//right(Matrix, row, col);
	

	bool flow = true;
	cout << "Use buttons W,A,S,D for moving rows and cols of the array: " << endl;
	while (flow)
	{
		int button = _getch();
		switch (button)
		{
			case 119:
				up(Matrix, row, col);
				print(Matrix, row, col);
				cout << endl;
				break;
			case 115:
				down(Matrix, row, col);
				print(Matrix, row, col);
				cout << endl;
				break;
			case 97:
				left(Matrix, row, col);
				print(Matrix, row, col);
				cout << endl;
				break;
			case 100:
				right(Matrix, row, col);
				print(Matrix, row, col);
				cout << endl;
				break;
			case 27:
				flow = false;
				break;
			default:
				cout << "Wrong button" << endl;
				break;
		}

	}
	

}


