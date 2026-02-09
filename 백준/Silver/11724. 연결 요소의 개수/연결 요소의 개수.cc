#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> graph;
static vector<bool> visited;

void DFS(int v);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0, M = 0;
    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1);

    for(int i = 0; i < M; i++)
    {
        int start = 0, end = 0;
        cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    int answer = 0;
    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
        {
            answer++;
            DFS(i);
        }
    }

    cout << answer;
}

void DFS(int v)
{
    if(visited[v])
        return;

    visited[v] = true;

    for(int n : graph[v])
    {
        if(!visited[n])
            DFS(n);
    }
}