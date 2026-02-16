#include <iostream>

using namespace std;

int GCD(int A, int B);
int LCM(int A, int B);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 0;
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        int A = 0, B = 0;
        cin >> A >> B;

        cout << LCM(A, B) << '\n';
    }
}

int GCD(int A, int B)
{
    if(B == 0)
        return A;
    else
        return GCD(B, A % B);
}

int LCM(int A, int B)
{
    return A * B / GCD(A, B);
}