#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using Long = long long;

struct Data
{
    int appear_index;
    Long number;
    int count;

    Data() {}

    Data(int appear_index, Long number, int count)
        : appear_index(appear_index)
        , number(number)
        , count(count)
    {}
};

struct Compare
{
    bool operator()(const Data& arg1, const Data& arg2) const
    {
        if(arg1.count == arg2.count)
        {
            return arg1.appear_index < arg2.appear_index;
        }

        return arg1.count > arg2.count;
    }
};

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto message_length = 0;
    auto maximum_num = Long(0);
    std::cin >> message_length >> maximum_num;

    auto map = std::unordered_map<Long, Data>();
    
    for(auto i = 0; i < message_length; i++)
    {
        auto num = Long(0);
        std::cin >> num;

        if(map.find(num) == map.end())
            map.insert(std::make_pair(num, Data(i, num, 1)));
        else
            map[num].count++;
    }

    auto vec = std::vector<Data>();
    for(auto& kv : map)
        vec.push_back(kv.second);

    std::sort(vec.begin(), vec.end(), Compare{});

    for(const auto& data : vec)
        for(auto i = 0; i < data.count; i++)
            std::cout << data.number << " ";
    
    return 0;
}