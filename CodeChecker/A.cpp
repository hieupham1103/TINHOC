#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int n;
int a[maxN];
vector <int> adj[maxN];
int dp[maxN];
int dp2[maxN];
int child[maxN];
int lvl[maxN];


void dfs(int nu, int fa){
    child[nu] = 1;
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        lvl[i] = lvl[nu] + 1;
        dfs(i, nu);
        child[nu] += child[i];
        dp[nu] += dp[i];
    }
    dp[nu] += (child[nu] - 1);
}
int cnt = 0;
void dfs2(int nu, int fa){
    cnt++;
    dp2[nu] += dp2[fa];
    if (fa != nu){
        for (auto i: adj[fa]){
            if (i == nu or lvl[i] < lvl[fa]){
                continue;
            }
            dp2[nu] += dp[i];
        }
        dp2[nu] += n - (child[nu] + 1);
    }
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        dfs2(i,nu);
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    dfs2(1,1);

    cout << n << endl;

    return 0;
}