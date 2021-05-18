#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
#define int long long
int calc(vector<double> &w, vector<int> &v, double &bias){
    double u = 0;
    for(int i = 0; i < (int)w.size(); i++){
        u += v[i]*w[i];
    }
    u += bias;
    if(u >= 0) return 1;
    else return -1;
}
int32_t main(){
    int n, m;
    cin >> n >> m;
    double bias, taxa;
    cin >> bias >> taxa;
    int mat[n][m];
    vector<double> w(m - 1);
    for(int i = 0; i < m - 1; i++){
        cin >> w[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    int q = 100;
    while(q--){
        bool convergiu = true;
        for(int i = 0; i < n; i++){
            vector<int> aux;
            for(int j = 0; j < m - 1; j++){
                aux.push_back(mat[i][j]);
            }
            int val = calc(w, aux, bias);
            int esp = mat[i][m - 1];
            if(val != mat[i][m - 1]){
                for(int j = 0; j < m - 1; j++){
                    w[j] = w[j] + taxa * (esp - val) * aux[j];
                }
                bias = bias + taxa * (esp - val);
                convergiu = false;
            }
        }
        if(convergiu) break;
    }
    cout << fixed << setprecision(1);
    for(auto &i : w){
        cout << i << ' ';
    }
    cout << bias << endl;
    cin >> q;
    while(q--){
        vector<int>v(m - 1);
        for(int &i : v){
            cin >> i;
        }
        cout << calc(w, v, bias) << endl;
    }
}