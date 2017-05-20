#ifndef Recursion_h
#define Recursion_h

// map each digit 0-9 to a set of alphabets
std::vector<std::string> PermDigits(std::string s, uint64_t n, std::vector<std::string> combos
	, std::unordered_map<char, std::string> m)
{
	std::vector<std::string> res;
	if (n == s.size() - 1) {
		char c = s[n];
		for (auto &i : m) {
			if (s[n] == i.first) {
				for (auto &k : i.second) {
					for (auto &j : combos) {
						res.push_back(j + k);
					}
				}
				break;
			}
		}
		return res;
	}

	if (combos.size() == 0) {
		for (auto &i : m) {
			if (s[n] == i.first) {
				for (auto &j : i.second) {
					combos.push_back(std::string(1, j));
				}
				break;
			}
		}
		return PermDigits(s, n + 1, combos, m);
	}
	for (auto &i : m) {
		if (s[n] == i.first) {
			for (auto &k : i.second) {
				for (auto &j : combos) {
					res.push_back(j + k);
				}
			}
			break;
		}
	}
	return PermDigits(s, n + 1, res, m);
}


void Run() {
	std::unordered_map<char, std::string> m = { { '0',{ "ABC" } },{ '1',{ "DE" } }
		,{ '2',{ "FGHI" } },{ '3',{ "J" } }
		,{ '4',{ "KL" } },{ '5',{ "MNOP" } }
		,{ '6',{ "QR" } },{ '7',{ "ST" } }
	,{ '8',{ "UVWXY" } },{ '9',{ "Z", } } };
	// generate all permutations of string of digits
	std::string s("9876543210");

	std::vector<std::string> res = PermDigits(s, 0, {}, m);

	for (int i = 0; i < res.size(); ++i) {
		std::cout << "Combo " << i + 1 << ": " << res[i] << std::endl;
	}

	getchar();
}

#endif // DEBUG

