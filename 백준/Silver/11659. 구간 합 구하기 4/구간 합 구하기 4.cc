#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N = 0;
    size_t M = 0;
    cin >> N >> M;

    vector<int> V(N + 1);
    vector<int> S(N + 1);

    for(size_t rep = 1; rep <= N; rep++)
    {
        cin >> V[rep];
        S[rep] = (rep == 1) ? V[rep] 
                            : S[rep - 1] + V[rep];
    }

    int i = 0;
    int j = 0;
    for(size_t rep = 0; rep < M; rep++)
    {
        cin >> i >> j;
        
        int sum = S[j] - S[i - 1];
        cout << sum << '\n';
    }
}