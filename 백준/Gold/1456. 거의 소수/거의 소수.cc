#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static vector<bool> V;
static vector<long long> Primes;
static int answer = 0;

void GetPrime(long long B);
void GetAlmostPrimeCount(long long A, long long B);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long A = 0, B = 0;
    cin >> A >> B;
    
    GetPrime(B);
    GetAlmostPrimeCount(A, B);

    cout << answer;
}

void GetPrime(long long B)
{
    int limit = static_cast<int>(floor(sqrt(B)));
    V.resize(limit + 1);

    Primes.push_back(2);
    for(long long t = 3; t * t <= limit; t += 2)
    {
        if(!V[t])
        {
            for(long long i = t * t; i <= limit; i += t)
                V[i] = true;
        }
    }

    for(int i = 3; i <= limit; i += 2)
    {
        if(!V[i])
            Primes.push_back(i);
    }
}

void GetAlmostPrimeCount(long long A, long long B)
{
    for(const long long prime : Primes)
    {
        long long pow_prime = prime * prime;

        while (pow_prime <= B)
        {
            if (pow_prime >= A) 
                answer++;

            if(pow_prime > B / prime)
                break;
            
            pow_prime *= prime;
        }
    }
}