#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

void Solve()
{
	long sz {};
	long maxWeight {};
	std::cin >> sz >> maxWeight;

	std::vector<long> weight {};
	std::vector<long> profit {};

	long temp {};
	for (long i = 0; i < sz; ++i) {
		std::cin >> temp;
		weight.push_back(temp);
	}

	for (long i = 0; i < sz; ++i) {
		std::cin >> temp;
		profit.push_back(temp);
	}

	std::vector<std::vector<long>> grid {};
	grid.resize(sz + 1);

	for (long i = 0; i <= maxWeight; ++i) {
		grid[0].emplace_back(0);
	}
	for (long i = 1; i <= sz; ++i) {
		grid[i].emplace_back(0);
	}

	for (long i = 1; i <= sz; ++i) {
		for (long j = 1; j <= maxWeight; ++j) {
			auto temp = j - weight[i - 1];

			if ((i - 1 < 0) || (temp < 0)) {
				auto aux = std::max(grid[i][j - 1], grid[i - 1][j]);
				grid[i].emplace_back(aux);
				continue;
			}

			auto aux =
				std::max(grid[i - 1][j], grid[i - 1][temp] + profit[i - 1]);

			grid[i].push_back(aux);
		}
	}

	// print grid[sz][maxWeight];
}

int main()
{
	Solve();

	return EXIT_SUCCESS;
}
