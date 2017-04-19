#pragma once
#include <iostream>
#include <vector>
#include <string>

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

int64_t SumSquareDifference(int64_t limit) {
	int64_t sumOfSquares = ((2*limit + 1)*(limit + 1)*limit) / 6;
	int64_t sum = limit * (limit + 1) / 2;
	return (sum*sum - sumOfSquares);
}

bool isPrime(int64_t p) {
	if (p == 2) {
		return true;
	}
	if (p % 2 == 0) {
		return false;
	}
	for (int i = 3; i <= sqrt(p); i += 2) {
		if (p%i == 0) {
			return false;
		}
	}
	return true;
}

int64_t FindNthPrime(int n) {
	int64_t p = 2;
	int pCounter = 0;
	for (;;) {
		if (isPrime(p)) {
			++pCounter;
			//std::cout << p << ", ";
		}
		if (pCounter == n) {
			return p;
		}
		++p;
	}
}

int64_t FindLargestProductInSeries(std::string s, int length) {
	int64_t lpdt = 1, finallpdt = 1;
	int j = 0, counter = 0;
	std::cout << s << std::endl;
	for (int i = 0; i < s.size(); ++i) {
		for (int j = i; j < i + length && j < s.size(); ++j) {
			//std::cout << s[j] << ", ";
			lpdt *= (s[j] - '0');
		}
		++counter;
		finallpdt = finallpdt > lpdt ? finallpdt : lpdt;
		lpdt = 1;
	}
	std::cout << std::endl;
	return finallpdt;
}

void Run() {
	std::cout << FibSum(1, 2, 4000000) << std::endl;
	std::cout << largestPrimeFactor(600851475143) << std::endl;
	std::cout << GetLargestPalindromeFactors(999, 999) << std::endl;
	std::cout << SmallestNumberDivByRange(1, 20) << std::endl;
	std::cout << SumSquareDifference(100) << std::endl;
	std::cout << FindNthPrime(10001) << std::endl; 
	std::string s = "73167176531330624919225119674426574742355349194934\
96983520312774506326239578318016984801869478851843\
85861560789112949495459501737958331952853208805511\
12540698747158523863050715693290963295227443043557\
66896648950445244523161731856403098711121722383113\
62229893423380308135336276614282806444486645238749\
30358907296290491560440772390713810515859307960866\
70172427121883998797908792274921901699720888093776\
65727333001053367881220235421809751254540594752243\
52584907711670556013604839586446706324415722155397\
53697817977846174064955149290862569321978468622482\
83972241375657056057490261407972968652414535100474\
82166370484403199890008895243450658541227588666881\
16427171479924442928230863465674813919123162824586\
17866458359124566529476545682848912883142607690042\
24219022671055626321111109370544217506941658960408\
07198403850962455444362981230987879927244284909188\
84580156166097919133875499200524063689912560717606\
05886116467109405077541002256983155200055935729725\
71636269561882670428252483600823257530420752963450";
	std::cout << FindLargestProductInSeries(s, 13) << std::endl;
}