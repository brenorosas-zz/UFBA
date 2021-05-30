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

double g(double a, double b, double x){
    return a*x + b;
}

double media(vector<double> &v){
    int n = v.size();
    return somatorio(v)/n;
}

double coeficienteDeterminacao(vector<double> &x, vector<double> &y, double a, double b){
    double y_media = media(y);
    double SQReg = 0;
    for(auto &i : x){
        SQReg += (g(a, b, i) - y_media) * (g(a, b, i) - y_media);
    }
    double SQRes = 0;
    for(int i = 0; i < x.size(); i++){
        SQRes += (g(a, b, x[i]) - y[i]) * (g(a, b, x[i]) - y[i]);
    }
    double SQTot = SQRes + SQReg;
    return SQReg / SQTot;
}

int32_t main(){
    int n;
    cin >> n;
    vector<double>x(n);
    vector<double>y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    double a, b;
    cin >> a >> b;
    cout << coeficienteDeterminacao(x, y, a, b) << endl;
}