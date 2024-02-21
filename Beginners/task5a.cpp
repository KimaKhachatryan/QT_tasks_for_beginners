#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

std::pair<int, int> max_min (int* arr, size_t size);
double average (int* arr, size_t size);

int main()
{
	const size_t size = 5;
	int arr[size];

	std::cout << "Enter array elements!" << std::endl;
	for (size_t i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}

	std::cout << "The maximum of the array = " << max_min(arr, size).second << std::endl;
	std::cout << "The minimum of the array = " << max_min(arr, size).first << std::endl;
	std::cout << "The average of the array = " << average(arr, size) << std::endl;

	return 0;
}

std::pair<int, int> max_min (int* arr, size_t size)
{
	std::pair<int, int> result;
	int max = arr[0];
	int min = arr[0];

	for (size_t i = 1; i < size; ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}

		if (arr[i] < min) {
			min = arr[i];
		}
	}

	result.first = min;
	result.second = max;

	return result;
}

double average(int* arr, size_t size)
{
	long result = 0;
	for (size_t i = 0; i < size; ++i) {
		result += arr[i];
	}

	return static_cast<double>(result) / size;
}
