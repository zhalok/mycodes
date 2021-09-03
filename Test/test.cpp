#include <stdio.h>
bool isPrime(int n)
{
    int i;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}
int main()
{
    int sum = 0;
    int cnt = 0;
    int i;
    for (i = 1; i <= 100; i++)
    {
        if (i % 2 == 1)
        {
            if (i != 67 || i != 97)
            {
                if (isPrime(i))
                {

                    printf("%d ", i);
                    sum += i;
                    cnt++;
                }
            }
        }
    }
    printf("\n");
    printf("%d %d\n", sum, cnt);
}