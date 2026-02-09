#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> graph;
static vector<bool> visited;
static bool arrived = false;

void DFS(int v, int c);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0, M = 0;
    cin >> N >> M;

    graph.resize(N);
    visited.resize(N);

    for(int i = 0; i < M; i++)
    {
        int from = 0, to = 0;
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for(int i = 0; i < N; i++)
        DFS(i, 1);

    cout << (arrived ? 1 : 0);
}

void DFS(int v, int c)
{
    if(c == 5 || arrived)
    {
        arrived = true;
        return;
    }

    visited[v] = true;

    for(int n : graph[v])
    {
        if(!visited[n])
            DFS(n, c + 1);
    }

    visited[v] = false;
}