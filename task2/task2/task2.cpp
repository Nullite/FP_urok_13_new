#include <iostream>
#include <iostream>

int size1, size2, size3;

void getSize(int& size1, int& size2)
{
	std::cout << "Enter a size of the first array:\n";
	std::cin >> size1;

	std::cout << "Enter a size of the second array:\n";
	std::cin >> size2;

}

int* initArray(int size)
{
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
	return arr;
}

void showArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

int* mergeArrays(int* arr1, int* arr2, int size1, int size2)
{
	size3 = size1 + size2;
	int* arr = new int[size3];
	int* pArr1 = arr1;
	int* pArr2 = arr2;

	for (int i = 0; i < size3; i++)
	{
		if (i < size3 - size2)
		{
			arr[i] = *pArr1;
			pArr1++;
		}
		else
		{
			arr[i] = *pArr2;
			pArr2++;
		}
	}
	return arr;
}


int main()
{
	srand(time(nullptr));
	getSize(size1, size2);
	int* arr1 = initArray(size1);
	int* arr2 = initArray(size2);
	std::cout << "Array one: ";
	showArray(arr1, size1);
	std::cout << "Array two: ";
	showArray(arr2, size2);
	int* arr3 = mergeArrays(arr1, arr2, size1, size2);
	std::cout << "Merged arrays: ";
	showArray(arr3, size3);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
}
