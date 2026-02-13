#include <iostream>
#include <vector>

using namespace std;

static int N = 0;

double P[4];
vector<vector<bool>> visited;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

double answer = 0.0;

void DFS(int r, int c, int count, double prob);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int e = 0, w = 0, s = 0, n = 0;
    cin >> N >> e >> w >> s >> n;
    
    P[0] = e / 100.0;
    P[1] = w / 100.0;
    P[2] = s / 100.0;
    P[3] = n / 100.0;
    
    visited = vector<vector<bool>>(2 * N + 1, vector<bool>(2 * N + 1));
    DFS(N, N, 0, 1.0);

    cout.setf(ios::fixed);
    cout.precision(10);
    cout << answer;
}

void DFS(int r, int c, int count, double prob)
{
    if(visited[r][c])
        return;

    if(count == N)
    {
        answer += prob;
        return;
    }

    visited[r][c] = true;

    for (int d = 0; d < 4; d++)
    {
        if (P[d] == 0.0) 
            continue;

        int nr = r + dr[d];
        int nc = c + dc[d];

        DFS(nr, nc, count + 1, prob * P[d]);
    }

    visited[r][c] = false;   
}