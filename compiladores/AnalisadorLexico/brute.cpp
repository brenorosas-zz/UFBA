#include <bits/stdc++.h>
#define int long long
#define double long double
#define ms(v,x) memset(v,x,sizeof(v))
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define td(v) v.begin(), v.end()
#define tdr(v) v.rbegin(), v.rend()
#define endl "\n"
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 2e18;
const double pi = acos(-1.0);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
// int lcm(int a, int b) { return (a * b) / gcd(a, b); }
inline long long mod(long long n, long long m) {
    long long ret = n % m;
    if (ret < 0) ret += m;
    return ret;
}

double rad(double x) { return x * pi / 180.0; }

int exp(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1) result = result * a % MOD;

        b >>= 1;
        a = a *a  % MOD;
    }
    return result;
}

void solve(){
    string s;
    vector<string> aux;
    while(cin >> s){
        cout << s << endl;
        aux.push_back(s);
    }
    sort(td(aux));
    cout << "{";
    for(auto &i : aux){
        cout << "\"" <<i << "\"";
        if(i!=aux.back()) cout << ", ";
    }
    cout << '}' << endl;
}

int32_t main() {
	fastio;
	// freopen("in.txt", "r", stdin);
	int t = 1;
	// cin>>t;
	while (t--) {
		solve();
	}
}