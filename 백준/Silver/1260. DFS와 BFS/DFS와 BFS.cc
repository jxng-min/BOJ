#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<int>> graph;
static vector<bool> visited;
static queue<int> que;

void DFS(int v);
void BFS(int v);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0, M = 0, V = 0;
    cin >> N >> M >> V;

    graph.resize(N + 1);
    visited.resize(N + 1);

    for(int i = 0; i < M; i++)
    {
        int from = 0, to = 0;
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for(auto iter = graph.begin(); iter != graph.end(); iter++)
        sort(iter->begin(), iter->end());

    DFS(V);
    cout << '\n';

    visited.clear();
    visited.resize(N + 1);

    BFS(V);
}

void DFS(int v)
{
    if(visited[v])
        return;

    visited[v] = true;
    cout << v << ' ';

    for(int n : graph[v])
        if(!visited[n])
            DFS(n);
}

void BFS(int v)
{
    que.push(v);
    visited[v] = true;

    while(!que.empty())
    {
        v = que.front();
        que.pop();

        cout << v << ' ';

        for(int n : graph[v])
            if(!visited[n])
            {
                visited[n] = true;
                que.push(n);
            }
    }
}