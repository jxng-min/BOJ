#include <iostream>
#include <vector>

using namespace std;

static vector<vector<pair<int, int>>> graph;
static vector<bool> visited;

void DFS(int from_v, int to_v, int distance);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0, M = 0;
    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1);

    for(int i = 1; i <= N - 1; i++)
    {
        int from = 0, to = 0, distance = 0;
        cin >> from >> to >> distance;

        graph[from].push_back(make_pair(to, distance));
        graph[to].push_back(make_pair(from, distance));
    }

    for(int i = 0; i < M; i++)
    {
        int from = 0, to = 0;
        cin >> from >> to;

        visited.clear();
        visited.resize(N + 1);

        DFS(from, to, 0);
    }
}

void DFS(int from_v, int to_v, int distance)
{
    if(from_v == to_v)
    {
        cout << distance << '\n';
        return;
    }

    if(visited[from_v])
        return;

    visited[from_v] = true;

    for(pair<int, int> n : graph[from_v])
    {
        if(!visited[n.first])
            DFS(n.first, to_v, distance + n.second);
    }
}