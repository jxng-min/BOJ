#include <iostream>
#include <vector>
#include <string>

using namespace std;

static vector<bool> Checked;
static vector<int> Primes;

static int answer = 0;

void GetPrime();
void CheckPalindrome(int N);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0;
    cin >> N;

    GetPrime();
    CheckPalindrome(N);

    cout << answer;
}

void GetPrime()
{
    Checked.resize(2'000'001);

    Primes.push_back(2);
    for(int t = 3; t * t <= 2'000'000; t += 2)
    {
        if(!Checked[t])
        {
            for(int i = t * t; i <= 2'000'000; i += t)
                Checked[i] = true;
        }
    }

    for(int t = 3; t <= 2'000'000; t += 2)
        if(!Checked[t])
            Primes.push_back(t);
}

void CheckPalindrome(int N)
{
    for(const int prime : Primes)
    {
        if(N > prime)
            continue;

        string s_prime = to_string(prime);

        int s_idx = 0;
        int e_idx = s_prime.length() - 1;

        bool failed = false;
        for(int t = 0; t < s_prime.length() / 2; t++)
        {
            if(s_prime[s_idx] != s_prime[e_idx])
            {
                failed = true;
                break;
            }

            s_idx++;
            e_idx--;
        }

        if(!failed)
        {
            answer = prime;
            return;
        }
    }
}