#include <bits/stdc++.h>
using namespace std;
#define int long long
bool mesmo_sinal(double a, double b)
{
    if (a > 0 and b > 0)
    {
        return true;
    }
    if (a < 0 and b < 0)
    {
        return true;
    }
    return false;
}
double f(double x)
{
    return x * x * x - 9 * x + 3;
}
int32_t main()
{
    double n;
    cin >> n;
    cout << f(n) << endl;
    // double a, b;
    // double m = (a + b) / 2;
    // cin >> a >> b;
    // while (true)
    // {
    //     m = (a + b) / 2.0;
    //     if (abs(f(m)) < 0.002)
    //     {
    //         cout << m << endl;
    //         cout << f(m) << endl;
    //         return 0;
    //     }
    //     if (mesmo_sinal(f(m), f(a)))
    //     {
    //         a = m;
    //     }
    //     else
    //     {
    //         b = m;
    //     }
    // }
}