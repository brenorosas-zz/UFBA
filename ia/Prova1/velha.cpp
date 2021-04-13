#include <iostream>
using namespace std;
#define int long long
int mat[9][9];
int a1, a2;
int n;
const int INF = 1e18;
void resp()
{
    cout << a1 << ',' << a2 << endl;
}
bool win(int x)
{
    bool d1 = true;
    bool d2 = true;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][i] != x)
            d1 = false;
        if (mat[n - i][i] != x)
            d2 = false;
        bool ganha = true;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != x)
                ganha = false;
        }
        if (ganha)
            return true;
        ganha = true;
        for (int j = 0; j < n; j++)
        {
            if (mat[j][i] != x)
                ganha = false;
        }
        if (ganha)
            return true;
    }
    return d1 or d2;
}
bool complet()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == -1)
                return false;
        }
    }
    return true;
}
int calc(int jg)
{
    if (complet())
    {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == -1)
            {
                mat[i][j] = jg;
                if (win(jg) and jg == 0)
                {
                    ans++;
                }
                else if (!win(1))
                {
                    ans += calc((jg + 1) % 2);
                }
                mat[i][j] = -1;
            }
        }
    }
    return ans;
}
int32_t main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    a1 = -1, a2 = -1;
    if (win(0) or win(1) or complet())
    {
        resp();
    }
    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == -1)
            {
                int qt;
                mat[i][j] = 1;
                if (win(1))
                {
                    qt = 0;
                }
                else
                {
                    qt = calc(0);
                }
                // cout << i << ' ' << j << ' ' << qt << endl;
                if (qt < ans)
                {
                    ans = qt;
                    a1 = i;
                    a2 = j;
                }
                mat[i][j] = -1;
            }
        }
    }
    resp();
}