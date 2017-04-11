#pragma once

#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include <algorithm>

class checker
{
public:
	int operator()(int &i, int &j) {
		return std::pow(i, j);
	}
}check1;

void calls()
{
	std::function<int(int, int)> powfunc = [](int i, int j) { return pow(i, j); };

	std::vector<std::string> v = { "apple", "bun", "cat" };

	std::cout << count_if(v.begin(), v.end(), check1);// [](std::string &test) { return test.size() == 3; });
}