#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <chrono>
#include <random>
using namespace std;
#define int long long
const int INF = 2e9;
int gol[4] = {-1, 0, 1, 0};
int goc[4] = {0, 1, 0, -1};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int32_t main(){
    int n;
    cin >> n;
    double alpha, gamma, epsilon;
    cin >> epsilon >> gamma >> alpha;
    int mat[n][n];
    double q_table[n][n][4];
    int gi, gj;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 100){
                gi = i;
                gj = j;
            }
            for(int k = 0; k < 4; k++){
                q_table[i][j][k] = 0;
            }
        }
    }
    int x, y;
    cin >> x >> y;
    // q_table[gi][gj][0] = INF;
    // q_table[gi][gj][1] = INF;
    // q_table[gi][gj][2] = INF;
    // q_table[gi][gj][3] = INF;
    for(int i = 0; i < 1000; i++){
        int vx = x;
        int vy = y;
        int penalties = 0;
        int reward = 0;
        int epochs = 0;
        bool done = false;
        while(!done){
            int newx = vx, newy = vy;
            int action;
            if((rng()%101)/100.0 < epsilon){
                action = rng()%4;
                newx += gol[action];
                newy += goc[action];
            }
            else{
                action = 0;
                if(q_table[vx][vy][1] > q_table[vx][vy][action]){
                    action = 1;
                }
                if(q_table[vx][vy][2] > q_table[vx][vy][action]){
                    action = 2;
                }
                if(q_table[vx][vy][3] > q_table[vx][vy][action]){
                    action = 3;
                }
                newx += gol[action];
                newy += goc[action];
            }
            if(newx < 0 or newx >= n) continue;
            if(newy < 0 or newy >= n) continue;
            reward = mat[newx][newy];
            done = (mat[newx][newy] == 100);
            double old_value = q_table[vx][vy][action];
            double next_max;
            int actionaux = 0;
            if(q_table[newx][newy][1] > q_table[newx][newy][actionaux]){
                    actionaux = 1;
            }
            if(q_table[newx][newy][2] > q_table[newx][newy][actionaux]){
                actionaux = 2;
            }
            if(q_table[newx][newy][3] > q_table[newx][newy][actionaux]){
                actionaux = 3;
            }
            next_max = q_table[newx][newy][actionaux];
            double new_value = (1.0 - alpha) * old_value + alpha * (reward + gamma * next_max);
            q_table[vx][vy][action] = new_value;
            if(reward == -100){
                penalties++;
            }
            if(mat[newx][newy] != -100){
                vx = newx;
                vy = newy;
            }
            epochs += 1;
        }
    }
    while(x != gi or y != gj){
        int action = -1;
        double num = -INF;
        cout << x << ' ' << y << endl;
        if(q_table[x][y][0] > num){
            action = 0;
            num = q_table[x][y][0];
            // cout << "cima" << ' ';
            // cout << q_table[x][y][0] << endl;
        }
        if(q_table[x][y][1] > num){
            action = 1;
            num = q_table[x][y][1];
            // cout << "direita" << ' ';
            // cout << q_table[x][y][1] << endl;
        }
        if(q_table[x][y][2] > num){
            action = 2;
            num = q_table[x][y][2];
            // cout << "baixo" << ' ';
            // cout << q_table[x][y][2] << endl;
        }
        if(q_table[x][y][3] > num){
            action = 3;
            num = q_table[x][y][3];
            // cout << "esquerda" << ' ';
            // cout << q_table[x][y][3] << endl;
        }
        // cout << action << endl;
        x += gol[action];
        y += goc[action];
    }
    cout << gi << ' ' << gj << endl;
}