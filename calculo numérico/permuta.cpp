#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void ler_matriz(vector<vector<double> >&A, int n, vector<double> &b){
    for(int i = 0; i < n; i++){
        vector<double> linha;
        for(int j = 0; j < n + 1; j++){
            double val;
            cin >> val;
            if(j < n)
                linha.push_back(val);
            else
                b.push_back(val);
        }
        A.push_back(linha);
    }
}
bool criterio_linha(vector<vector<double> > &A){
    int n = A.size();
    for(int i = 0; i < n; i++){
        double sum = -2 * abs(A[i][i]);
        for(int j = 0; j < n; j++){
            sum += abs(A[i][j]);
        }
        if(sum >= 0) return false;
    }
    return true;
}

bool criterio_coluna(vector<vector<double> > &A){
    int n = A.size();
    for(int i = 0; i < n; i++){
        double sum = -2 * abs(A[i][i]);
        for(int j = 0; j < n; j++){
            sum += abs(A[j][i]);
        }
        if(sum >= 0) return false;
    }
    return true;
}

bool criterio_sassenfeld(vector<vector<double> >&A){
    int n = A.size();
    vector<double> beta(n);
    double maior = 0;
    for(int i = 0; i < n; i++){
        double val = 0;
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            if(j > i)
                val += abs(A[i][j]);
            else
                val += beta[j] * abs(A[i][j]);
        }
        val /= abs(A[i][i]);
        beta[i] = val;
        maior = max(maior, beta[i]);
    }
    if(maior < 1) return true;
    return false;
}
vector<vector<double> > permutLinhaA(vector<vector<double> >&A, vector<int> &permutaLinha){
    vector<vector<double> > ansA = A;
    for(int i = 0; i < permutaLinha.size(); i++){
        ansA[i] = A[permutaLinha[i]];
    }
    return ansA;
}
vector<vector<double> > permutColunaA(vector<vector<double> >&A, vector<int> &permutaColuna){
    vector<vector<double> > ans = A;
    int n = A.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[j][i] = A[j][permutaColuna[i]];
        }
    }
    return ans;
}
vector<double> permutB(vector<double> &b, vector<int> &permutaLinha){
    vector<double> ansb = b;
    for(int i = 0; i < permutaLinha.size(); i++){
        ansb[i] = b[permutaLinha[i]];
    }
    return ansb;
}
void mostra_matriz(vector<vector<double> > &A, vector<double> &b){
    int n = A.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n+1; j++){
            if(j < n)
                cout << A[i][j] << ' ';
            else{
                cout << b[i] << endl;
            }
        }
    }
}
int32_t main(){
    int n;
    cin >> n;
    vector<int> permutaLinha(n);
    for(int i = 0; i < n; i++){
        permutaLinha[i] = i;
    }
    vector<vector<double> > matriz;
    vector<double> equal;
    ler_matriz(matriz, n, equal);
    cout << endl;
    // Testa todas permutações de linha e pra cada permutação de linha testa todas permutações de coluna
    // Testa apenas criterio de linha e criterio de coluna.
    int x = 1;
    do{
        vector<vector<double> > A = permutLinhaA(matriz, permutaLinha);
        vector<double> b = permutB(equal, permutaLinha);
        vector<vector<double> > auxiliar = A;
        vector<int> permutaColuna(n);
        for(int i = 0; i < n; i++){
            permutaColuna[i] = i;
        }
        do{
            cout << "Permutação " << x++ << endl;
            A = permutColunaA(auxiliar, permutaColuna);
            mostra_matriz(A, b);
            if(criterio_linha(A)){
               cout << "Passa no critério das linhas" << endl;
            }
            if(criterio_coluna(A)){
                cout << "Passa no critério das colunas" << endl;
            }
            if(criterio_sassenfeld(A)){
                cout << "Passa no critério de sassenfeld" << endl;
            }
            cout << endl;
        }while(next_permutation(permutaColuna.begin(), permutaColuna.end()));
    }while(next_permutation(permutaLinha.begin(), permutaLinha.end()));
}