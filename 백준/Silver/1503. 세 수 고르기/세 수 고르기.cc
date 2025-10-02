#include <iostream>
#include <set>
#include <climits>
#include <vector>

using Long = long long;

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto N = 0;
    auto set_size = 0;
    std::cin >> N >> set_size;

    auto banned_set = std::set<int>();
    for(int i = 0; i < set_size; i++)
    {
        auto num = 0;
        std::cin >> num;

        banned_set.insert(num);
    }

    auto available_vec = std::vector<int>();
    for(auto i = 1; i <= 1001; i++)
        if(!banned_set.count(i))
            available_vec.push_back(i);
    
    auto min = LLONG_MAX;
    for(auto x : available_vec)
        for(auto y : available_vec)
            for(auto z : available_vec)
            {
                auto product = Long(x * y * z);
                auto diff = llabs(N - product);

                min = std::min(min, diff);

                if((product - N) > min)
                    break;
            }

    std::cout << min;

    return 0;
}