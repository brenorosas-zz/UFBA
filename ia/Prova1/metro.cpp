#include <iostream>
#include <iomanip>
#include <map>
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
vector<pair<int, double>> adj[15];
int s, t;
double velo, bald;
vector<vector<double>> dist;
double h[15];
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
map<pair<int, int>, string> linha;
vector<int> levi;
bool exist(vector<int> &vet, int x)
{
    for (int &i : vet)
    {
        if (i == x)
        {
            return true;
        }
    }
    return false;
}
vector<int> A_star()
{
    vector<int> vinicius;
    vector<double> mendist(15, INF);
    set<pair<int, string>> q;
    q.insert({s, "neutro"});
    vector<int> p(15);
    vector<double> score(15, INF);
    mendist[s] = 0;
    score[s] = h[s];
    while (!q.empty())
    {
        double menor = 1e9 + 50;
        int v;
        string cor;
        for (auto &i : q)
        {
            if (score[i.first] < menor)
            {
                menor = score[i.first];
                v = i.first;
                cor = i.second;
            }
        }
        if (!exist(levi, v))
            levi.push_back(v);
        if (v == t)
        {
            return path(p);
        }
        q.erase({v, cor});
        for (auto edge : adj[v])
        {
            int to = edge.first;
            double len = edge.second * 60.0 / velo + mendist[v];
            if (linha[{v, to}] != cor and cor != "neutro")
            {
                len += bald;
            }
            if (len < mendist[to])
            {
                p[to] = v;
                mendist[to] = len;
                score[to] = mendist[to] + h[to];
                if (!q.count({to, linha[{v, to}]}))
                {
                    q.insert({to, linha[{v, to}]});
                }
            }
        }
    }
    return vinicius;
}
void cost(int i, double pi)
{
    h[i] = dist[i - 1][t - 1] * 60.0 / velo;
}
void insere(int i, int j, double c)
{
    adj[i].push_back({j, c});
}
void make_color(int i, int j, string color)
{
    linha[{i, j}] = color;
}
double take_dist(int i, int j)
{
    for (auto edge : adj[i])
    {
        if (edge.first == j)
        {
            return edge.second;
        }
    }
    return 0.0;
}
void solve()
{
    cin >> s >> t;
    cin >> velo >> bald;
    for (int i = 1; i <= 14; i++)
    {
        cost(i, t);
    }
    vector<int> ans = A_star();
    for (int i = 0; i < (int)levi.size() - 1; i++)
    {
        cout << levi[i] << '-';
    }
    cout << levi.back() << endl;
    for (int i = 0; i < (int)ans.size() - 1; i++)
    {
        cout << ans[i] << '-';
    }
    cout << ans.back() << endl;
    double temp = 0;
    string cor = "neutra";
    for (int i = 1; i < (int)ans.size(); i++)
    {
        double distan = take_dist(ans[i - 1], ans[i]);
        temp += distan * 60 / velo;
        if (cor != "neutra" and linha[{ans[i - 1], ans[i]}] != cor)
        {
            temp += bald;
        }
        cor = linha[{ans[i - 1], ans[i]}];
    }
    cout << fixed << setprecision(1);
    cout << temp << endl;
}

int32_t main()
{
    fastio;
    // freopen("in.txt", "r", stdin);
    int t = 1;
    // cin >> t;
    // int x = 1;
    insere(1, 2, 10);
    insere(2, 1, 10);
    insere(2, 3, 8.5);
    insere(2, 9, 10);
    insere(2, 10, 3.5);
    insere(3, 2, 8.5);
    insere(3, 4, 6.3);
    insere(3, 9, 9.4);
    insere(3, 13, 18.7);
    insere(4, 3, 6.3);
    insere(4, 5, 13);
    insere(4, 8, 15.3);
    insere(4, 13, 12.8);
    insere(5, 4, 13);
    insere(5, 6, 3);
    insere(5, 7, 2.4);
    insere(5, 8, 30);
    insere(6, 5, 3);
    insere(7, 5, 2.4);
    insere(8, 4, 15.3);
    insere(8, 5, 30);
    insere(8, 9, 9.6);
    insere(8, 12, 6.4);
    insere(9, 2, 10);
    insere(9, 3, 9.4);
    insere(9, 8, 9.6);
    insere(9, 11, 12.2);
    insere(10, 2, 3.5);
    insere(11, 9, 12.2);
    insere(12, 8, 6.4);
    insere(13, 3, 18.7);
    insere(13, 4, 12.8);
    insere(13, 14, 5.1);
    insere(14, 13, 5.1);
    make_color(1, 2, "azul");
    make_color(2, 3, "azul");
    make_color(3, 4, "azul");
    make_color(4, 5, "azul");
    make_color(5, 6, "azul");
    make_color(2, 1, "azul");
    make_color(3, 2, "azul");
    make_color(4, 3, "azul");
    make_color(5, 4, "azul");
    make_color(6, 5, "azul");
    make_color(10, 2, "amarelo");
    make_color(2, 9, "amarelo");
    make_color(9, 8, "amarelo");
    make_color(8, 5, "amarelo");
    make_color(5, 7, "amarelo");
    make_color(2, 10, "amarelo");
    make_color(9, 2, "amarelo");
    make_color(8, 9, "amarelo");
    make_color(5, 8, "amarelo");
    make_color(7, 5, "amarelo");
    make_color(11, 9, "vermelho");
    make_color(9, 3, "vermelho");
    make_color(3, 13, "vermelho");
    make_color(9, 11, "vermelho");
    make_color(3, 9, "vermelho");
    make_color(13, 3, "vermelho");
    make_color(12, 8, "verde");
    make_color(8, 4, "verde");
    make_color(4, 13, "verde");
    make_color(13, 14, "verde");
    make_color(8, 12, "verde");
    make_color(4, 8, "verde");
    make_color(13, 4, "verde");
    make_color(14, 13, "verde");
    dist.push_back({0, 10, 18.5, 24.8, 36.4, 38.8, 35.8, 25.4, 17.6, 9.1, 16.7, 27.3, 27.6, 29.8});
    dist.push_back({10, 0, 8.5, 14.8, 26.6, 29.1, 26.1, 17.3, 10, 3.5, 15.5, 20.9, 19.1, 21.8});
    dist.push_back({18.5, 8.5, 0, 6.3, 18.2, 20.6, 17.6, 13.6, 9.4, 10.3, 19.5, 19.1, 12.1, 16.6});
    dist.push_back({24.8, 14.8, 6.3, 0, 12, 14.4, 11.5, 12.4, 12.6, 16.7, 23.6, 18.6, 10.6, 15.4});
    dist.push_back({36.4, 26.6, 18.2, 12, 0, 3, 2.4, 19.4, 23.3, 28.2, 34.2, 24.8, 14.5, 17.9});
    dist.push_back({38.8, 29.1, 20.6, 14.4, 3, 0, 3.3, 22.3, 25.7, 30.3, 36.7, 27.6, 15.2, 18.2});
    dist.push_back({35.8, 26.1, 17.6, 11.5, 2.4, 3.3, 0, 20, 23, 27.3, 34.2, 25.7, 12.4, 15.6});
    dist.push_back({25.4, 17.3, 13.6, 12.4, 19.4, 22.3, 20, 0, 8.2, 20.3, 16.1, 6.4, 22.7, 27.6});
    dist.push_back({17.6, 10, 9.4, 12.6, 23.3, 25.7, 23, 8.2, 0, 13.5, 11.2, 10.9, 21.2, 26.6});
    dist.push_back({9.1, 3.5, 10.3, 16.7, 28.2, 30.3, 27.3, 20.3, 13.5, 0, 17.6, 24.2, 18.7, 21.2});
    dist.push_back({16.7, 15.5, 19.5, 23.6, 34.2, 36.7, 34.2, 16.1, 11.2, 17.6, 0, 14.2, 31.5, 35.5});
    dist.push_back({27.3, 20.9, 19.1, 18.6, 24.8, 27.6, 25.7, 6.4, 10.9, 24.2, 14.2, 0, 28.8, 33.6});
    dist.push_back({27.6, 19.1, 12.1, 10.6, 14.5, 15.2, 12.4, 22.7, 21.2, 18.7, 31.5, 28.8, 0, 5.1});
    dist.push_back({29.8, 21, 8, 16.6, 15.4, 17.9, 18.2, 15.6, 27.6, 26.6, 21.2, 35.5, 33.6, 5.1, 0});
    while (t--)
    {
        // cout << "Case #"<<x++<<": ";
        solve();
    }
}