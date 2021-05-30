#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    float a = 1, s = 2;
    while(s > 1){
        a = a/2;
        s = 1 + a;
    }
    float prec = 2*a;
    cout<<fixed<<setprecision(30);
    cout << prec << endl;
}