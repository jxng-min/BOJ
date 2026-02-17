#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

LL Euler(LL n);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    LL n = 0;
    cin >> n;
    
    cout << Euler(n);
}

LL Euler(LL n)
{
    LL result = n;

    if(n % 2 == 0)
    {
        result -= result / 2;

        while(n % 2 == 0)
            n /= 2;
    }

    for(LL p = 3; p <= n / p; p += 2)
    {
        if(n % p == 0)
        {
            result -= result / p;

            while(n % p == 0)
                n /= p;
        }
    }

    if(n > 1)
        result -= result / n;

    return result;
}