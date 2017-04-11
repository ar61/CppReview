#pragma once
#include <vector>
#include <iostream>

// need to figure out how to do diophantine equations efficiently
std::vector<std::pair <long, long>> solEquaStr(long long n)
{
	long long y2, y, x2;
	std::vector<std::pair <long, long>> ret;
	std::cout << n << std::endl;
	for (long long i = n / 2 + 5; i > 0; --i) {
		x2 = i*i;
		y2 = (x2 - n) / 4;
		long lhs = sqrt(y2);
		if (lhs > 0 && lhs*lhs == y2 && (x2 - 4 * y2 == n)) {
			std::cout << "(x,y) = " << i << "," << lhs << std::endl;
			ret.push_back(std::make_pair(i, lhs));
		}
	}
	//solEquaStr(90005);
	return ret;
}