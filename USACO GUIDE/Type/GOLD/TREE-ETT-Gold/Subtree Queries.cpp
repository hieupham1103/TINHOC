#include<bits/stdc++.h>

#define int long long
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'

using namespace std;

const int maxN = 3 * 1e5 + 10;
const int inf = 1e18;

int seg[maxN * 4];


void update(int i, int left, int right, int index, int val){
    if (index < left or right < index){
        return;
    }
    if (left == right){
        seg[i] = val;
        return;
    }
    int mid = (left + right) / 2;

    update(2 * i, left, mid, index, val);
    update(2 * i + 1, mid + 1, right, index, val);
    seg[i] = (seg[2 * i] + seg[2 * i + 1]);
}

int get(int i, int left, int right, int _left, int _right){
    if (right < _left or _right < left){
        return 0;
    }
    if (_left <= left and right <= _right){
        return seg[i];
    }

    int mid = (left + right) / 2;

    int t1 = get(2 * i, left, mid, _left, _right);
    int t2 = get(2 * i + 1, mid + 1, right, _left, _right);
    return (t1 + t2);
}

int st[maxN];
int en[maxN];
int v[maxN];
vector <int> adj[maxN];
int cnt = 0;

void dfs(int i, int d){
    st[i] = ++cnt;
    for (auto j: adj[i]){
        if (j == d){
            continue;
        }
        dfs(j,i);
    }
    en[i] = cnt;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, test;
    cin >> n >> test;

    
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);

    for (int i = 1; i <= n; i++){
        update(1,1,n,st[i],v[i]);
    }

    while(test--){
        int t;
        cin >> t;
        if (t == 1){
            int i, x;
            cin >> i >> x;
            update(1,1,n,st[i],x);
        }
        else{
            int i;
            cin >> i;
            cout << get(1,1,n,st[i], en[i]) << endl;
        }
    }

    return 0;
}
