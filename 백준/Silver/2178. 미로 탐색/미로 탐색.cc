#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<char>> graph(101, vector<char>(101));
static vector<vector<int>> visited(101, vector<int>(101));

static vector<int> dr = {0, 0, 1, -1};
static vector<int> dc = {1, -1, 0, 0};

static queue<pair<int, int>> que;

static int N = 0;
static int M = 0;

void BFS(int r, int c);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for(int r = 1; r <= N; r++)
        for(int c = 1; c <= M; c++)
            cin >> graph[r][c];

    BFS(1, 1);
    cout << visited[N][M];
}

void BFS(int r, int c)
{
    que.push(make_pair(r, c));
    visited[r][c] = 1;

    while(!que.empty())
    {
        pair<int, int> current = que.front();
        que.pop();

        r = current.first;
        c = current.second;

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 1 || nr > N || nc < 1 || nc > M)
                continue;

            if(graph[nr][nc] == '0' || visited[nr][nc] != 0)
                continue;
            
            que.push(make_pair(nr, nc));
            visited[nr][nc] = visited[r][c] + 1;
        }
    }
}