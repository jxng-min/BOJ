#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int A, int B);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = 0;
    cin >> n;

    vector<int> V(n);
    for(int i = 0; i < n; i++)
        cin >> V[i];

    int target = V[0];
    for(int i = 1; i < n; i++)
        V[i] = abs(V[i] - V[0]);

    vector<int> Candidate(V.begin() + 1, V.end());
    int gcd = Candidate[0];
    for(int i = 1; i < n - 1; i++)
        gcd = GCD(max(gcd, Candidate[i]), min(gcd, Candidate[i]));
    
    cout << gcd;
}

int GCD(int A, int B)
{
    if(B == 0)
        return A;
    else
        return GCD(B, A % B);
}