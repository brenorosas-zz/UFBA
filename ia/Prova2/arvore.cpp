#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
const double INF = 2e9;
void debug(){
    cout << "debug" << endl;
}
double entropiaEspecifica(vector<vector<int> >&mat, int espc){
    vector<pair<int,int> > vet((int)mat.size(), make_pair(0,0));
    int tot = (int)mat.size();
    for(int i = 0; i < (int)mat.size(); i++){
        vet[mat[i][espc]].first += (mat[i].back() == 0);
        vet[mat[i][espc]].second += (mat[i].back() == 1);
    }
    double ans = 0;
    for(int i = 0; i < (int)vet.size(); i++){
        int zero = vet[i].first;
        int um = vet[i].second;
        // cout << zero << ' ' << um << endl;
        if(zero == 0 or um == 0) continue;
        ans += -(zero+um)*1.0/tot*(-zero*log2(zero) - um*log2(um));
    }
    return ans;
}
double entropia(vector<vector<int> >&mat){
    int u = 0;
    int z = 0;
    for(int i = 0; i < (int)mat.size(); i++){
        z += (mat[i].back() == 0);
        u += (mat[i].back() == 1);
    }
    return -z*1.0*log2(z) - u*1.0*log2(u);
}
double ganho(int vt, vector<vector<int> >&mat, vector<int> &v){
    double ans = entropia(mat) - entropiaEspecifica(mat, vt);
    return ans;
}
int calc(vector<vector<int> >&mat, vector<int> &v){
    double melhor = -INF;
    int escolha;
    int z = 0;
    int u = 0;
    for(int i = 0; i < (int)mat.size(); i++){
        z += (mat[i].back() == 0);
        u += (mat[i].back() == 1);
    }
    if(z == (int)mat.size()) return 0;
    if(u == (int)mat.size()) return 1;
    for(int i = 0; i < (int)v.size(); i++){
        double x = ganho(i, mat, v);
        if(x > melhor){
            melhor = x;
            escolha = i;
        }
    }
    vector<vector<int> >newmat;
    vector<int> newv;
    for(int i = 0; i < (int)v.size(); i++){
        if(i == escolha) continue;
        newv.push_back(v[i]);
    }
    for(int i = 0; i < (int)mat.size(); i++){
        if(mat[i][escolha] != v[escolha]) continue;
        vector<int> aux;
        for(int j = 0; j < (int)mat[i].size(); j++){
            if(j == escolha) continue;
            aux.push_back(mat[i][j]);
        }
        newmat.push_back(aux);
    }
    return calc(newmat, newv);
}

int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> >mat;
    for(int i = 0; i < n; i++){
        vector<int> aux;
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            aux.push_back(x);
        }
        mat.push_back(aux);
    }
    vector<int>v(m - 1);
    for(int i = 0; i < m - 1; i++){
        cin >> v[i];
    }
    cout << calc(mat, v) << endl;
}