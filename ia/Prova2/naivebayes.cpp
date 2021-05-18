#include <iostream>
using namespace std;
#define int long long
int32_t main(){
    int n, m;
    cin >> n >> m;
    int mat[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    int v[m-1];
    for(int i = 0; i < m - 1; i++){
        cin >> v[i];
    }
    int V = n*(m - 1); 
    double reszero = 1, resum = 1;
    for(int j = 0; j < m - 1; j++){
        int qtz = 1;
        int qtu = 1;
        int zero, um;
        zero = um = 0;
        for(int i = 0; i < n; i++){
            if(mat[i][j] == v[j]){
                if(mat[i][m-1] == 0)
                    qtz++;
                else
                    qtu++;
            }
            if(mat[i][m - 1] == 0) zero++;
            else um++;
        }
        reszero *= qtz * 1.0 / (zero + V);
        resum *= qtu * 1.0 / (um + V);
    }
    if(reszero > resum){
        cout << 0 << endl;
    }
    else{
        cout << 1 << endl;
    }
}