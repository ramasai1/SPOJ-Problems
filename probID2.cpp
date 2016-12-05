#include <iostream>
#include <cmath>
#define PRIMES 3401
#define PRIME 31608

int primes[PRIMES];
bool prime[PRIME];

void sieve_of_erastothenes()
{
    long int i,j,k=0;
    prime[0]=false;
    prime[1]=false;
    for (i = 2; i <= PRIME; i++)
        prime[i]=true;
    for (i = 2; ;i++)
    {
        while ((i <= PRIME) && (!prime[i]))
            i++;

        if (i > PRIME)
            break;

        primes[k++] = i;
        for (j = 2*i; j <= PRIME; j += i)
            prime[j] = false;
    }
}
int main()
{
    long int t,i,lower,upper,j,k;
    bool prime2[100001];
    sieve_of_erastothenes();
    std::cin >> t;
    for (i = 0; i < t; i++)
    {
        if (i > 0) putchar('\n');
        std::cin >> lower >> upper;
        int s = (int)sqrt(upper);
        int p;
        for (j = 0;j <= 100000; j++)
            prime2[j] = true;

        for (j = 0;(j < PRIMES) && (primes[j] <= s);j++)
        {
            p=primes[j];

            for(k = p*(lower/p) + p - lower;k <= (upper - lower);k += p)
                prime2[k] = false;

            if (lower % p == 0)
                prime2[0] = false;
        }
        for (j = 0; j <= (upper - lower); j++)
        {
            if ((j + lower) > PRIME)
                if (prime2[j])
                    printf("%d\n", j + lower);
            if (j + lower <= PRIME)
            {
                if (prime[j + lower])
                    std::cout << '\n' << j + lower;
            }
        }
    }
    return 0;
}
