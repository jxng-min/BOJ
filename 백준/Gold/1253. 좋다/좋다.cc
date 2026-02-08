#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0;
    cin >> N;

    vector<long long> A(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    int answer = 0;
    for(int i = 0; i < N; i++)
    {
        int s_idx = 0;
        int e_idx = N - 1;

        while(s_idx < e_idx)
        {
            if(s_idx == i)
            {
                s_idx++;
                continue;
            }

            if(e_idx == i)
            {
                e_idx--;
                continue;
            }

            if(A[s_idx] + A[e_idx] == A[i])
            {
                answer++;
                break;
            }
            else if(A[s_idx] + A[e_idx] > A[i])
            {
                e_idx--;
            }
            else
            {
                s_idx++;
            }
        }
    }

    cout << answer;
}