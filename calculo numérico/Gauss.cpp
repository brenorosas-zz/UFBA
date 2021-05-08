#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

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

bool criterio_sassenfield(vector<vector<double> >&A){
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

vector<double> inicial(vector<vector<double> >&A, vector<double> &b, int n){
    vector<double> x(n);
    for(int i = 0; i < n; i++){
        x[i] = b[i] / A[i][i];
    }
    return x;
}

bool ok(vector<double> &x, vector<double>&newx, double epsilon){
    double maior = 0;
    double maiornew = 0;
    for(int i = 0; i < x.size(); i++){
        maior = max(maior, abs(newx[i] - x[i]));
        maiornew = max(maiornew, abs(newx[i]));
    }
    return maior / maiornew < epsilon;
}

vector<double> gauss_jacobi(vector<vector<double> >&A, vector<double> &b, int n, double epsilon){
    vector<double> x = inicial(A, b, n);
    vector<double> newx(n, 0);
    int it = 0;
    while(true){
        it++;
        for(int i = 0; i < n; i++){
            newx[i] = b[i];
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                newx[i] -= A[i][j] * x[j];
            }
            newx[i] /= A[i][i];
        }
        bool acabou = ok(x, newx, epsilon);
        x = newx;
        if(acabou) break;
    }
    cout << it << " iterações com o método gauss-jacobi" << endl;
    return x;
}

vector<double> gauss_seidel(vector<vector<double> >&A, vector<double> &b, int n, double epsilon){
    vector<double> x = inicial(A, b, n);
    vector<double> newx(n, 0);
    int it = 0;
    while(true){
        it ++;
        for(int i = 0; i < n; i++){
            newx[i] = b[i];
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(j < i)
                    newx[i] -= A[i][j] * newx[j];
                else
                    newx[i] -= A[i][j] * x[j];
            }
            newx[i] /= A[i][i];
        }
        bool acabou = ok(x, newx, epsilon);
        x = newx;
        if(acabou) break;
    }
    cout << it << " iterações com método gauss_seidel" << endl;
    return x;
}

int32_t main(){
    int n;
    double epsilon;
    cin >> n >> epsilon;
    vector<vector<double> > A;
    vector<double> b;
    ler_matriz(A, n, b);
    vector<double> gaussJacobi = gauss_jacobi(A, b, n, epsilon);
    vector<double> gaussseidel = gauss_seidel(A, b, n, epsilon);
    cout << "Resposta com método Gauss-Jacobi" << endl;
    for(int i = 0; i < n; i++){
        cout << "x" << i+1 << " = " << gaussJacobi[i] << endl;;
    }
    cout << "Resposta com método de Gauss-seidel" << endl;
    for(int i = 0; i < n; i++){
        cout << "x" << i+1 << " = " << gaussseidel[i] << endl;;
    }
    if(criterio_linha(A) or criterio_coluna(A) or criterio_sassenfield(A)){
        cout << "O sistema linear possui convergência assegurada" << endl;
    }
    else{
        cout << "O sistema linear não possui convergência assegurada." << endl;
    }
}