#include <iostream>
#include <vector>
using namespace std;
int fibDp(int n, vector<int> &f)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    if (f[n] != -1)
    {
        return f[n];
    }

    f[n] = fibDp(n - 1, f) + fibDp(n - 2, f);

    return f[n];
}

int fibTab(int n) {
    vector<int> f(n+1);
    f[0] = 0;
    f[1] = 1;

    for(int i = 2;i <= n;i++) {
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

int main()
{
    int n = 6;
    vector<int> f(n+1, -1);

    cout << fibDp(n, f) << endl;
    cout << fibTab(n) << endl;

    return 0;
}