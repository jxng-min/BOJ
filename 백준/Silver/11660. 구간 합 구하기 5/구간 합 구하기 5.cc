#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0;
    int M = 0;
    cin >> N >> M;

    vector<vector<int>> S(N + 1, vector<int>(N + 1));

    for(int x = 1; x <= N; x++)
        for(int y = 1; y <= N; y++)
        {
            int vxy = 0;
            cin >> vxy;

            S[x][y] = S[x - 1][y] + S[x][y - 1] - S[x - 1][y - 1] + vxy;
        }

    int x1 = 0; int y1 = 0;
    int x2 = 0; int y2 = 0;

    for(int rep = 0; rep < M; rep++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        int answer = S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];
        cout << answer << '\n';
    }
}