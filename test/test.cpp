#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int maxN = 2 * 1e5 + 10;

vector <int> adj[maxN];
int dp[maxN];
int si[maxN];

void dfs1(int node, int father){
    si[node] = 1;
    dp[node] = 0;
    for (auto i: adj[node]){
        if (i == father){
            continue;
        }
        dfs1(i,node);
        si[node] += si[i];
        dp[node] += dp[i];
    }
    dp[node] += si[node];
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root = 3;
    dfs1(root,root);

    for (int i = 1; i <= n; i++){
        cout << i << ": " << dp[i] << endl;
    }
    return 0;
}