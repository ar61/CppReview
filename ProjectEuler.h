#pragma once
#include <iostream>
#include <vector>

int FibSum(int a, int b, int limit)
{
	if (b > limit) {
		return a % 2 == 0 ? a : 0;
	}
	if (a % 2 == 0) {
		return FibSum(b, a + b, limit) + a;
	}
	return FibSum(b, a + b, limit);
}

int largestPrimeFactor(long long n) {
	long long largest = 2;
	while (n % 2 == 0) {
		n = n / 2;
	}

	for (long long i = 3; i < sqrt(n); i += 2) {
		if (n % i == 0) {
			if (largest < i) {
				largest = i;
			}
			n = n / i;
		}
	}

	if (n > 2) {
		return n;
	}
	return largest;
}

/*A palindromic number reads the same both ways.
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.*/


bool isPalindromeNumber(int n) {
	if (n % 10 == 0) {
		return false;
	}
	std::vector<int> digits;
	while (n > 0) {
		digits.push_back(n % 10);
		n = n / 10;
	}
	for (int i = 0, j = digits.size() - 1; i <= j; ++i, --j) {
		if (digits[i] != digits[j]) {
			return false;
		}
	}
	return true;
}

int GetLargestPalindromeFactors(int a, int b)
{
	int ret = -1;
	for (int i = a; i > 100; --i) {
		if (i % 10 == 0) {
			continue;
		}
		for (int j = b; j > 100; --j) {
			if (j % 10 == 0) {
				continue;
			}
			int p = i*j;
			if (isPalindromeNumber(p)) {
				if (p > ret) {
					ret = p;
				}
			}
		}
	}

	return ret;
}


long getLCM(long a, long b)
{
	long larger = a > b ? a : b;

	for (;;) {
		if (larger%a == 0 && larger%b == 0) {
			return larger;
		}
		++larger;
	}
}

long SmallestNumberDivByRange(long a, long b)
{
	long res = 1;
	if (a == 1) {
		++a;
	}

	for (long i = b; i > a; --i) {
		res = getLCM(i, res);
	}

	return res;
}

void Run() {
	std::cout << FibSum(1, 2, 4000000) << std::endl;
	std::cout << largestPrimeFactor(600851475143) << std::endl;
	std::cout << GetLargestPalindromeFactors(999, 999) << std::endl;
	std::cout << SmallestNumberDivByRange(1, 20) << std::endl;
}