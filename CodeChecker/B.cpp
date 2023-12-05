#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n, mod;
vector <ii> adj[maxN];
int up[maxN][20];
int down[maxN][20];
int lg[maxN];
int dep[maxN];
int father[maxN][20];
int po[maxN];

int mul(int a, int b){
    return (a * b) % mod;
}
int add(int a, int b){
    return (a + b) % mod;
}

void dfs(int nu, int fa){
    for (auto i: adj[nu]){
        if (i.se == fa){
            continue;
        }
        dep[i.se] = dep[nu] + 1;
        up[i.se][0] = down[i.se][0] = i.fi;
        father[i.se][0] = nu;
        dfs(i.se, nu);
    }
}

void init(){
    dep[0] = -1;
    for (int j = 1, base = 1; j <= lg[n]; j++){
        base = mul(base,10);
        for (int i = 1; i <= n; i++){
            father[i][j] = father[father[i][j - 1]][j - 1];
            int fa = father[i][j - 1];
            up[i][j] = add(mul(up[fa][j - 1], base), up[i][j - 1]);
            down[i][j] = add(mul(down[i][j - 1], base), down[fa][j - 1]);
        }
    }
}

int LCA(int a, int b){
    if (dep[a] < dep[b]){
        swap(a,b);
    }
    for (int i = lg[dep[a]]; dep[a] != dep[b]; i--){
        if (dep[father[a][i]] >= dep[b]){
            a = father[a][i];
        }
    }
    if (a == b){
        return a;
    }
    for (int i = lg[dep[a]]; i >= 0; i--){
        if (father[a][i] != father[b][i]){
            a = father[a][i];
            b = father[b][i];
        }
    }
    return father[a][0];
}

int getdown(int a, int lca){
    int res = 0;
    // cout << a << "=" << lca << endl;
    for (int i = lg[a]; i >= 0; i--){
        if (dep[father[a][i]] >= dep[lca]){
            res = add(down[a][i],mul(res, po[1 << i]));
            // cout << a << " " << i << " " << down[a][i] << " " << po[(1 << i) - 1] << endl;
            a = father[a][i];
        }
    }
    return res;
}

int getup(int a, int lca){
    int res = 0;
    // cout << a << "=" << lca << endl;
    int t = 0;
    for (int i = lg[a]; i >= 0; i--){
        if (dep[father[a][i]] >= dep[lca]){
            res = add(res,mul(up[a][i], po[t]));
            // cout << a << " " << i << " " << up[a][i] << " " << po[t] << endl;
            a = father[a][i];
            t += (1 << i);
        }
    }
    return res;
}

int dist[maxN];

void bfs(int st){
    queue <int> q;
    q.push(st);
    memset(dist, -1, sizeof(dist));
    dist[st] = 0;
    while(q.size()){
        int t = q.front();
        q.pop();
        // cout << t << " " << endl;
        for (auto i: adj[t]){
            if (dist[i.se] != -1){
                continue;
            }
            dist[i.se] = add(mul(dist[t], 10),i.fi);
            q.push(i.se);
        }
    }
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> mod;
    po[0] = 1;
    for (int i = 1; i <= n; i++){
        lg[i] = log2(i);
        po[i] = mul(po[i - 1], 10);
    }
    for (int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }
    dfs(1,1);
    init();

    int test;
    cin >> test;
    while(test--){
        int a, b;
        cin >> a >> b;
        bfs(a);
        cout << dist[b] << endl;
    }

    return 0;
}