#include <iostream>

int size1, size2, size3 = 0;

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

void getSize3(int arr1[], int arr2[], int size1, int size2)
{
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (arr1[i] == arr2[j])
				break;
			if (j == size2 - 1) 
			{
				if (!i)
					size3 += 1;

				else 
				{
					for (int k = 0; k < i; k++)
					{
						if (arr1[k] == arr1[i])
							break;
						if (k == i - 1)
							size3 += 1;		
					}
				}
			}	
		}
	}

	for (int i = 0; i < size2; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			if (arr2[i] == arr1[j])
				break;
			if (j == size1 - 1)
			{
				if (!i)
					size3 += 1;

				else
				{
					for (int k = 0; k < i; k++)
					{
						if (arr2[k] == arr2[i])
							break;

						if (k == i - 1)
							size3 += 1;		
					}
				}
				
			}
				
		}
	}
}

int* getUniqueElements(int* arr1, int* arr2, int size1, int size2, int size3)
{
	int* arr = new int[size3];
	int* pArr1 = arr1;
	int* pArr2 = arr2;
	int* pArr = arr;

	for (int i = 0; i < size1; i++) 
	{
		for (int j = 0; j < size2; j++)
		{
			if (*(pArr1 + i) == *(pArr2 + j))
				break;
			if (j == size2 - 1)
			{
				if (!i)
				{
					*pArr = *(pArr1 + i);
					pArr++;
				}
				else
				{
					for (int k = 0; k < i; k++)
					{
						if (*(pArr1 + k) == *(pArr1 + i))
							break;
						if (k == i - 1)
						{
							*pArr = *(pArr1 + i);
							pArr++;
						}

					}
				}
				
			}				
		}
	}

	for (int i = 0; i < size2; i++)
	{
		for (int j = 0; j < size1; j++)
		{
			if (*(pArr1 + j) == *(pArr2 + i))
				break;
			if (j == size1 - 1)
			{
				if (!i)
				{
					*pArr = *(pArr2 + i);
					pArr++;
				}
				else
				{
					for (int k = 0; k < i; k++)
					{
						if (*(pArr2 + k) == *(pArr2 + i))
							break;
						if (k == i - 1)
						{
							*pArr = *(pArr2 + i);
							pArr++;
						}
					}
				}
			}
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
	getSize3(arr1, arr2, size1, size2);
	int* arr3 = getUniqueElements(arr1, arr2, size1, size2, size3);
	std::cout << "Unique elements: ";
	showArray(arr3, size3);
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;  
}

