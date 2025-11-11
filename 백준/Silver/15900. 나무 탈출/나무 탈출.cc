#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>>& graph, 
         std::vector<bool>& visit,
         int& height,
         int x, 
         int depth)
{
    visit[x] = true;

    if(x != 1 && graph[x].size() == 1)
    {
        height += depth;
        return;
    }

    for(int i = 0; i < graph[x].size(); i++)
    {
        if(visit[graph[x][i]])
            continue;

        dfs(graph, visit, height, graph[x][i], depth + 1);
    }
}

int main(void)
{
    auto vertex_count = 0;
    std::cin >> vertex_count;

    auto graph = std::vector<std::vector<int>>(500001);
    auto begin = 0;
    auto end = 0;
    for(auto i = 0; i < vertex_count - 1; i++)
    {
        std::cin >> begin >> end;

        graph[begin].push_back(end);
        graph[end].push_back(begin);
    }

    auto visited = std::vector<bool>(vertex_count + 1);
    auto height = 0;
    dfs(graph, visited, height, 1, 0);

    if(height % 2 != 0)
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}