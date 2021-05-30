#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
#define int long long
double somatorio(vector<double> &v){
    double ans = 0;
    for(auto &i : v)
        ans += i;
    return ans;
}

double somatorioXY(vector<double> &x, vector<double> &y){
    double somatorio = 0;
    for(int i = 0; i < x.size(); i++)
        somatorio += x[i]*y[i];
    return somatorio;
}

double somatorioQuadrado(vector<double> &v){
    double ans = 0;
    for(auto &i : v)
        ans += i*i;
    return ans;
}

double calc_a(int n, vector<double> &x, vector<double> &y){
    double ans = n*somatorioXY(x,y) - somatorio(x)*somatorio(y);
    ans /= n*somatorioQuadrado(x) - somatorio(x)*somatorio(x);
    return ans;
}

double calc_b(int n, vector<double> &x, vector<double> &y){
    double ans = somatorio(x)*somatorioXY(x,y) - somatorio(y)*somatorioQuadrado(x);
    ans /= somatorio(x)*somatorio(x) - n*somatorioQuadrado(x);
    return ans;
}
int32_t main(){
    int n;
    cin >> n;
    vector<double>x(n);
    vector<double>y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    double a = calc_a(n, x, y);
    double b = calc_b(n, x, y);
    cout << a << ' ' << b << endl;
    cout << somatorioXY(x, y) << endl;
}