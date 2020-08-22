#include <cstdio>
using namespace std;

void solve(int n, char src, char dest, char aux)
{
    if (n == 1)
    {
        printf("Move %d from %c to %c\n", n, src, dest);
        return;
    }
    solve(n - 1, src, aux, dest);
    printf("Move %d from %c to %c\n", n, src, dest);
    solve(n - 1, aux, dest, src);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", (1 << n) - 1);
        solve(n, 'A', 'C', 'B');
    }
}