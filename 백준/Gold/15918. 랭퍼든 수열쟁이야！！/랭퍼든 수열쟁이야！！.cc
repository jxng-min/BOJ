#include <iostream>
#include <vector>

int dfs(std::vector<int>& vec,  
        int number_count, 
        int z, 
        int num)
{
    if(num == z)
        return dfs(vec, number_count, z, num + 1);

    if(num == number_count + 1)
        return 1;

    auto count = 0;
    for(auto i = 1; (i + num + 1) < 2 * number_count + 1; i++)
        if(vec[i] == 0 && vec[i + num + 1] == 0)
        {
            vec[i] = vec[i + num + 1] = num;
            count += dfs(vec, number_count, z, num + 1);
            vec[i] = vec[i + num + 1] = 0;
        }

    return count;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto number_count = 0;
    std::cin >> number_count;

    auto x = 0;
    auto y = 0;
    std::cin >> x >> y;

    auto vec = std::vector<int>(number_count * 2 + 1);
    auto count = 0;

    auto z = y - x - 1;
    vec[x] = vec[y] = z;

    std::cout << dfs(vec, number_count, z, 1);
}