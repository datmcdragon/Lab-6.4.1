#include <iostream>

using namespace std;

void InArr(int* arr, const int size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = -10 + rand() % 30;
}

void PrArr(const int* const arr, const int size)
{
	cout << "{";
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i != size - 1)
			cout << ", ";

	}
	cout << "}" << endl;
}
void SortArr(int* arr, const int size)
{
	for (int j = 1; j < size; j++)
		for (int i = 0; i < size - j; i++) 
			if (arr[i] < arr[i + 1]) 
			{ 
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
}

int SerMin(const int* const arr, const int size)
{
	int min = arr[0];
	int index = 0;
		for (int i = 0; i < size; i++)
			if (abs(arr[i]) < abs(min))
			{
				min = arr[i];	
				index = i;
			}
		return index;
}

int SerMax(const int* const arr, const int size)
{
	int max = arr[0];
	int index = 0;
	for (int i = 0; i < size; i++)
		if (abs(arr[i]) > abs(max))
		{
			max = arr[i];
			index = i;
		}
	return index;
}

int ModSum(const int* const arr, const int size)
{
	int P = 1, start=SerMin(arr,size), end=SerMax(arr,size);
	if (start>end)
	{
		int temp = start;
		start = end;
		end = temp;
	}
	for (int i = 1 + start; i < end; i++)
	{
		P *= arr[i];
	}
	return P;
}

int PoSumArr(const int* const arr, const int size)
{
	int S = 0;
	for (size_t i = 0; i < size; i++)
		if (arr[i] < 0 == 0)
		{
			S += arr[i];
		}
	return S;
}

int main()
{
	srand(time(0));
	int n;
	cout << "n = "; cin >> n;

	int* a = new int[n];

	InArr(a, n);
	PrArr(a, n);

	cout << "P = " << ModSum(a, n) << endl;
	cout << "S = " << PoSumArr(a, n) << endl;

	SortArr(a, n);
	PrArr(a, n);

	delete[]a;
	a = nullptr;

	return 0;
}