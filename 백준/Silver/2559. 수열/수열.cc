#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0, K = 0;
    cin >> N >> K;

    vector<int> V(N + 1);
    for(int i = 1; i <= N; i++)
        cin >> V[i];

    int s_idx = 1;
    int e_idx = K;

    int sum = 0;
    for(int i = 1; i <= K; i++)
        sum += V[i];

    int answer = sum;
    while(e_idx < N)
    {
        s_idx++;
        e_idx++;

        int temp_sum = sum + V[e_idx] - V[s_idx - 1];
        answer = max(answer, temp_sum);
        sum = temp_sum;
    }

    cout << answer;
}