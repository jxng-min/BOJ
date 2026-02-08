#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n = 0;
    cin >> n;

    vector<int> vec(n);
    for(int rep = 0; rep < n; rep++)
        cin >> vec[rep];

    sort(vec.begin(), vec.end());

    int x = 0;
    cin >> x;

    int s_idx = 0;
    int e_idx = static_cast<int>(vec.size() - 1);

    int answer = 0;
    while(s_idx < e_idx)
    {
        int ai = vec[s_idx];
        int aj = vec[e_idx];

        if(ai + aj == x)
        {
            answer++;
            e_idx--;
        }
        else if(ai + aj > x)
        {
            e_idx--;
        }
        else
        {
            s_idx++;
        }
    }

    cout << answer;
}