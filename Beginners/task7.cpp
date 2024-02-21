#include <iostream>

void BubbleSort(int* arr, const size_t size);
void SelectionSort(int* arr, const size_t size);
void SortChoice(int* arr, const size_t size, void(*)(int*, const size_t));

int main()
{
	const size_t size = 7;
	int arr[size];

	std::cout << "Enter array elements: ";
	for (size_t i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}

	int choice = 0;
	do {
		std::cout << "For Bubble Sort enter 1, for Selection Sort enter 2: ";
		std::cin >> choice;
	} while (choice != 1 &&  choice != 2);

	if (choice == 1) {
		SortChoice(arr, size, &BubbleSort);
		std::cout << "Array sorted with Bubble sorting algorith." << std::endl;
	} else {
		SortChoice(arr, size, &SelectionSort);
		std::cout << "Array sorted with Selection sorting algorith." << std::endl;
	}

	std::cout << "Sorted array: ";
	for (size_t i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
	return 0;
}

void BubbleSort (int* arr, const size_t size)
{
	for(int j = 0; j < size - 1; ++j) { 
		bool swap = false;
		
		for (int i = 0; i < size - 1 - j; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swap = true;
			}
		}

		if (swap == false) {
			break;
		}
	}
}

void SelectionSort (int* arr, const size_t size)
{
	for (int i = 0; i < size - 1; ++i) {
		int min_ind = i;

		for (int j = i + 1; j < size; ++j) {
			if (arr[j] < arr[min_ind]) {
				min_ind = j;
			}

			if (i != min_ind) {
				std::swap(arr[i], arr[min_ind]);
			}
		}
	}
}


void SortChoice(int* arr, const size_t size, void(*fptr)(int*, const size_t))
{
	fptr(arr, size);
}
