#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
using namespace std;
const int INF = 1000000000;
vector<pair<int, int>> adj[13];
int s, t;
vector<vector<int>> dist;
double h[13];
vector<int> path(vector<int> p)
{
    vector<int> ans;
    int x = t;
    while (x != s)
    {
        ans.push_back(x);
        x = p[x];
    }
    ans.push_back(x);
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> A_star()
{
    vector<int> vinicius;
    vector<int> mendist(13, INF);
    set<int> q;
    q.insert(s);
    vector<int> p(13);
    vector<double> score(13, INF);
    mendist[s] = 0;
    score[s] = h[s];
    while (!q.empty())
    {
        double menor = 1e9 + 50;
        int v;
        for (auto &i : q)
        {
            if (h[i] < menor)
            {
                menor = h[i];
                v = i;
            }
        }
        if (v == t)
        {
            return path(p);
        }
        q.erase(v);
        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second + mendist[v];
            if (len < mendist[to])
            {
                p[to] = v;
                mendist[to] = len;
                score[to] = mendist[to] + h[to];
                if (!q.count(to))
                {
                    q.insert(to);
                }
            }
        }
    }
    return vinicius;
}
void cost(int i, double pi)
{
    h[i] = dist[i - 1][t - 1] * pi;
}
void insere(int i, int j, int c)
{
    adj[i].push_back({j, c});
}
void solve()
{
    cin >> s >> t;
    int vac;
    cin >> vac;
    vector<double> pi(13);
    for (int i = 1; i <= 12; i++)
    {
        int x;
        double c;
        cin >> x >> c;
        cost(x, c);
        pi[x] = c;
    }
    vector<int> ans = A_star();
    int total = vac;
    for (int &i : ans)
    {
        vac -= floor(total * (0.2 * (1.0 - pi[i])));
    }
    for (int i = 0; i < (int)ans.size() - 1; i++)
    {
        cout << ans[i] << '-';
    }
    cout << ans.back() << endl;
    cout << vac << endl;
}

int32_t main()
{
    fastio;
    // freopen("in.txt", "r", stdin);
    int t = 1;
    // cin >> t;
    // int x = 1;
    insere(1, 2, 270);
    insere(1, 10, 1093);
    insere(1, 3, 475);
    insere(1, 4, 675);
    insere(1, 8, 980);
    insere(2, 1, 270);
    insere(2, 3, 225);
    insere(3, 2, 225);
    insere(3, 4, 205);
    insere(3, 1, 475);
    insere(4, 3, 205);
    insere(4, 1, 675);
    insere(4, 8, 933);
    insere(4, 5, 99);
    insere(4, 7, 623);
    insere(5, 4, 99);
    insere(5, 6, 152);
    insere(5, 7, 551);
    insere(6, 5, 152);
    insere(6, 7, 430);
    insere(7, 6, 430);
    insere(7, 5, 551);
    insere(7, 4, 623);
    insere(7, 8, 493);
    insere(8, 7, 493);
    insere(8, 4, 933);
    insere(8, 1, 980);
    insere(8, 10, 845);
    insere(8, 9, 325);
    insere(9, 8, 325);
    insere(9, 10, 957);
    insere(9, 11, 488);
    insere(10, 9, 957);
    insere(10, 1, 1093);
    insere(10, 8, 845);
    insere(10, 12, 1032);
    insere(10, 11, 965);
    insere(11, 10, 965);
    insere(11, 9, 488);
    insere(11, 12, 1787);
    insere(12, 11, 1787);
    insere(12, 10, 1032);
    dist.push_back({0, 270, 475, 675, 749, 828, 1017, 980, 1318, 1093, 1664, 1924});
    dist.push_back({270, 0, 225, 394, 484, 612, 837, 938, 1236, 1238, 1646, 2128});
    dist.push_back({475, 225, 0, 205, 290, 426, 712, 933, 1230, 1376, 1683, 2343});
    dist.push_back({675, 394, 205, 0, 99, 247, 623, 933, 1190, 1508, 1673, 2457});
    dist.push_back({749, 484, 290, 99, 0, 152, 551, 902, 1158, 1524, 1632, 2508});
    dist.push_back({828, 612, 426, 247, 152, 0, 430, 846, 1078, 1545, 1553, 2533});
    dist.push_back({1017, 837, 712, 623, 551, 430, 0, 493, 657, 1298, 1227, 2334});
    dist.push_back({980, 938, 933, 933, 902, 846, 493, 0, 325, 845, 746, 1860});
    dist.push_back({1318, 1236, 1230, 1190, 1158, 1078, 657, 325, 0, 957, 488, 1938});
    dist.push_back({1093, 1238, 1376, 1508, 1524, 1545, 1298, 845, 957, 0, 965, 1032});
    dist.push_back({1664, 1646, 1683, 1673, 1632, 1553, 1227, 746, 488, 965, 0, 1787});
    dist.push_back({1924, 2128, 2343, 2457, 2508, 2533, 2334, 1860, 1938, 1032, 1787, 0});
    while (t--)
    {
        // cout << "Case #"<<x++<<": ";
        solve();
    }
}