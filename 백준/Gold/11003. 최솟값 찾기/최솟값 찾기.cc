#include <iostream>
#include <vector>
#include <deque>

using namespace std;

using PIL = pair<int, long long>;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0, L = 0;
    cin >> N >> L;

    deque<PIL> D;
    for(int i = 0; i < N; i++)
    {
        int current;
        cin >> current;

        while(D.size() > 0 && D.back().first > current)
            D.pop_back();

        D.push_back(make_pair(current, i));

        if(D.front().second <= i - L)
            D.pop_front();

        cout << D.front().first << ' ';
    }
}