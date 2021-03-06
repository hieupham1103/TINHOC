#include<bits/stdc++.h>
using namespace std;

const int maxN = 500;
const int INF = 1e7;

int n, m;
int Start, End;
int mid[maxN][maxN];
int val[maxN][maxN];

void backtracking(int s, int e){
    if (mid[s][e] != -1){
        backtracking(s, mid[s][e]);
        cout << ' ' << mid[s][e];
        backtracking(mid[s][e], e);
    
    }
}

int main(){
    freopen("FLOYD.INP", "r", stdin);
    freopen("FLOYD.OUT", "w", stdout); 
    cin >> n >> m >> Start >> End;
    // cout << n << ' ' << m << ' ' << Start << ' ' << End << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            mid[i][j] = -1;
            val[i][j] = INF;
            if (i == j){
                val[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        val[a][b] = w;
        val[b][a] = w;
        // cout << a << ' ' << b << ' ' << w << endl;
     }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (val[i][j] > val[i][k] + val[k][j]){
                    val[i][j] = val[i][k] + val[k][j];
                    mid[i][j] = k;
                }
            }
        }
    }
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j++){
    //         if (val[i][j] != INF)
    //             cout << mid[i][j] << ' ';
    //         else{
    //             cout << "x" << ' ';
    //         }
    //     }
    //     cout << endl;
    // }
    // cout << "------" << endl;
    cout << val[Start][End] << endl;
    cout << Start;
    backtracking(Start, End);
    cout << ' ' << End;
    return 0;
}