#include <iostream>

auto check(int num)
{
	for (auto i = 2; i * i <= num; i++)
		if (num % i == 0)
			return false;

	return true;
}

void dfs(int N, int num, int length)
{
	if (length == N)
	{
		std::cout << num << '\n';
		return;
	}

	for (auto i = 1; i <= 9; i++)
		if (check(num * 10 + i))
			dfs(N, num * 10 + i, length + 1);
}

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	auto N = 0;
	std::cin >> N;

	dfs(N, 2, 1);
	dfs(N, 3, 1);
	dfs(N, 5, 1);
	dfs(N, 7, 1);

	return 0;
}