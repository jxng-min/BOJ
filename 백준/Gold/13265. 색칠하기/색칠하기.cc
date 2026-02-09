#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> graph;
static vector<int> visited;
static bool ended = false;

void DFS(int v);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 0;
    cin >> T;

    for(int test = 0; test < T; test++)
    {
        int n = 0, m = 0;
        cin >> n >> m;

        ended = false;

        graph.clear();
        visited.clear();

        graph.resize(n + 1);
        visited.resize(n + 1);

        for(int i = 0; i < m; i++)
        {
            int from = 0, to = 0;
            cin >> from >> to;
        
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        for(int i = 1; i <= n; i++)
        {
            if(ended)
                break;

            if(!visited[i])
            {
                visited[i] = 1;
                DFS(i);
            }
        }

        cout << (ended ? "impossible" : "possible") << '\n';
    }
}

void DFS(int v)
{
    for(int n : graph[v])
    {
        if(visited[n] == 0)
        {
            visited[n] = -1 * visited[v];
            DFS(n);

            if(ended)
                return;
        }
        else if(visited[n] == visited[v])
        {
            ended = true;
            return;
        }
    }

}