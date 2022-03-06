#include <iostream>

int size1, size2 = 0;
bool even;

void getSize(int& size)
{
	std::cout << "Enter a size of the array:\n";
	std::cin >> size1;
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

void getUserChoice()
{
	std::cout << "to delete odd numbers, enter 1\n"
		      << "to delete even numbers enter 2\n";
	bool entered = false;
	int choice = 0;
	while (!entered)
	{
		std::cin >> choice;
		if (choice == 1)
		{
			even = true;
			entered = true;
		}
		else if (choice == 2)
		{
			even = false;
			entered = true;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << " incorrect input\n";
			std::cout << "to delete odd numbers, enter 1\n"
				      << "to delete even numbers enter 2\n";
		}
	}
}

int* deleteUserChoice(int* arr)
{
	int* pArr = arr;
	if (even)
	{
		for (int i = 0; i < size1; i++)
		{
			if (!(*(pArr + i) % 2))
				size2++;
		}

		int* newArr = new int[size2];
		int* pnewArr = newArr;

		for (int i = 0; i < size1; i++)
		{
			if (!(*(pArr + i) % 2))
			{
				*pnewArr = *(pArr + i);
				pnewArr++;
			}	
		}
		return newArr;
	}
	else
	{
		for (int i = 0; i < size1; i++)
		{
			if (*(pArr + i) % 2)
				size2++;
		}

		int* newArr = new int[size2];
		int* pnewArr = newArr;

		for (int i = 0; i < size1; i++)
		{
			if (*(pArr + i) % 2)
			{
				*pnewArr = *(pArr + i);
				pnewArr++;
			}
		}
		return newArr;
	}
}

int main()
{
	srand(time(nullptr));
	getSize(size1);
	int* arr = initArray(size1);
	std::cout << "random generated array: ";
	showArray(arr, size1);
	getUserChoice();
	int* modifiedArr = deleteUserChoice(arr);
	std::cout << "\nyour choice is deleted: ";
	showArray(modifiedArr, size2);
	delete[] arr;
	delete[] modifiedArr;
}

