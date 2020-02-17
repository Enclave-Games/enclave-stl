#include "list/list.cpp"
#include "list/linked_list.cpp"
#include <iostream>
#include <cassert>
#include <stdio.h>
#include "algorithms/algorithms.h"

#include <vector>

void sort(std::vector<int> input_array)
{
	std::vector<int> first;
	std::vector<int> second;

	size_t middle_element = input_array.size() / 2;
	size_t minimum = middle_element - input_array[0] + 1;
	size_t max = (input_array.size() - 1) - middle_element;
	size_t i, j;

	for (i = 0; i < middle_element; i++)
	{
		first.push_back(input_array[i]);
	}

	for (j = middle_element; j < input_array.size(); j++)
	{
		second.push_back(input_array[j]);
	}

	while (i < minimum && j < max)
	{
		if (first[i] <= second[j])
		{
		}
	}

}

int main()
{
	setlocale(0, "ru");
	enclave_stl::list<int> list = {1, 2, 4, 1234, 3};

	/*list.push_back(22);
	list.push_back(24);
	list.push_back(2);*/

	const int size = 7;
	int arr[size] = {1, 3, 2, 54, 43, 11, 23};

	enclave_stl::algorithms::qsort(arr, 0, size - 1);

	//std::cout << "After Quick Sort the array is:\n";

	/*for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}*/


	for (size_t i = 0; i < list.size(); i++)
	{
		std::cout << list[i] << std::endl;
	}

	//for (enclave_stl::list<int>::iterator it = list.begin(); it != list.end(); it++)
	//{
	//	std::cout << *it << "\n";
	//}

	//enclave_stl::sort(list.begin(), list.end());

	//list.clear();

	//for (size_t i = 0; i < list.size(); i++)
	//{
	//	std::cout << list[i] << std::endl;
	//}



	return 0;
}