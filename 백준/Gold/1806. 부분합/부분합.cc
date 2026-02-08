#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0;
    long long S = 0;
    cin >> N >> S;

    vector<long long> s(N + 1);
    for(int rep = 1; rep <= N; rep++)
    {
        int v = 0;
        cin >> v;

        s[rep] = s[rep - 1] + v;
    }

    int s_idx = 1;
    int e_idx = 1;

    int answer = INT_MAX;
    while(e_idx <= N)
    {
        long long sum = s[e_idx] - s[s_idx - 1];

        if(sum >= S)
        {
            answer = min(answer, e_idx - s_idx + 1);
            s_idx++;
        }
        else
        {
            e_idx++;
        }
    }

    answer = answer == INT_MAX ? 0 : answer;
    cout << answer;
}