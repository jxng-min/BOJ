#include <iostream>
#include <deque>
#include <queue>

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto N = 0, K = 0;
    std::cin >> N >> K;

    auto deque = std::deque<int>();
    for(int i = 0; i < N; i++)
        deque.push_back(i + 1);
    
    auto queue = std::queue<int>();
    auto count = 1;
    while(!deque.empty())
    {
        if(count != K)
        {
            deque.push_back(deque.front());
            count++;
        }
        else
        {
            queue.push(deque.front());
            count = 1;
        }
        deque.pop_front();
    }

    std::cout << "<";
    while(!queue.empty())
    {
        std::cout << queue.front();
        queue.pop();

        if(queue.size() != 0)
            std::cout << ", ";
    }
    std::cout << ">" << '\n';

    return 0;
}