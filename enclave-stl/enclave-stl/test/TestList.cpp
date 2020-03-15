#include "list.h"
#include "linked_list.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <thread>
#include <array>
#include <stdio.h>
#include "algorithms.h"
#include <forward_list>
#include <future>
#include <vector>

#include <iostream>
#include <string_view>
#include <iomanip>
#include <ctime>
#include <chrono>

void test()
{
	estl::list<int> list1;
	//estl::list<int> list2;

	list1.push_back(22);
	list1.push_back(24);
	list1.push_back(2);

	/*list2.push_back(222);
	list2.push_back(2224);
	list2.push_back(2567);*/

	for (size_t i = 0; i < list1.size(); i++)
	{
		std::cout << list1[i] << std::endl;
	}

	std::cout << std::endl;

	list1.pop_back();

	for (size_t i = 0; i < list1.size(); i++)
	{
		std::cout << list1[i] << std::endl;
	}
}

int main()
{
	setlocale(0, "ru");

	test();
	return 0;
}