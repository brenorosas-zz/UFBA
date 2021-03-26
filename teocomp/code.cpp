#include<iostream>
#include<cmath>
using namespace std;

string wi(int i){
    int tam = 0;
    int x = 1;
    while(i >= x){
        i -= x;
        x*=2;
        tam++;
    }
    string ans(tam,'a');
    for(int j = 0; j < tam; j++){
        if((i >> j) & 1){
            ans[tam-j-1] = 'b';
        }
    }
    return ans;
}

bool ehprimo(int n){
    int divisores = 0;
    for(int i = 1; i <= n; i++){
        if(n%i == 0){
            divisores += 1;
        }
    }
    if(divisores == 2){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n;
    cin >> n;
    cout << ehprimo(n) << endl;
}