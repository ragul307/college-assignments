#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

void optbst()
{
	long   size {};
	std::vector<long> key {};
	std::vector<long> frequency {};

	std::cin >> size;
	long temp {};

	for (long i = 0; i < size; ++i) {
		std::cin >> temp;
		key.push_back(temp);
	}

	for (long i = 0; i < size; ++i) {
		std::cin >> temp;
		frequency.push_back(temp);
	}

	std::vector<std::vector<long>> cost {};
	cost.resize(size);

	for (auto& element : cost) {
		element.resize(size);
	}

	for (long i = 0; i < size; ++i) {
		cost[i][i] = frequency[i];
	}

	for (long aux = 2; aux <= size; ++aux) {
		auto temp = size - aux + 1;

		for (long i = 0; i <= temp; ++i) {
			auto j     = i + aux - 1;
			cost[i][j] = std::numeric_limits<long>::max();

			for (long k = i; k <= j; ++k) {
				long c {};

				if (k > i) {
					c += cost[i][k - 1];
				}
				if (k < j && k + 1 < size) {
					c += cost[k + 1][j];
				}

				auto last  = frequency.cbegin() + j + 1;
				auto first = frequency.cbegin() + i;
				c += std::accumulate(first, last, 0ll);

				if (c < cost[i][j]) {
					cost[i][j] = c;
				}
			}
		}
	}

	std::cout << cost[0][size - 1];
}

int main()
{
	optbst();

	return EXIT_SUCCESS;
}
