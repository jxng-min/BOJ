#include <iostream>

using namespace std;
using ULL = unsigned long long;

ULL GCD(ULL A, ULL B);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ULL A = 0, B = 0;
    cin >> A >> B;

    for(int i = 0; i < GCD(A, B); i++)
        cout << '1';
}

ULL GCD(ULL A, ULL B)
{
    if(B == 0)
        return A;
    else
        return GCD(B, A % B);
}