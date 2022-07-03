#include<bits/stdc++.h>
#define ii pair <long long, long long>
#define f first
#define s second
#define ll long long
#define int ll
using namespace std;


vector <ii> lists;
ll n, k;

int dirX[] = {-2 , -2 , -1 , -1 , 1 , 1 , 2 , 2};
int dirY[] = {1 , -1 , 2 , -2 , 2 , -2 , 1 , -1};

map <ii,ll> valMap;


bool check(ll x){
    if (x >= 1 and x <= n){
        return 1;
    }
    return 0;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.inp", "r", stdin);
    freopen("out2.txt", "w", stdout);
    
    cin >> n >> k;
    for (int i = 1; i <= k; i++){
        ll x, y, val;
        cin >> x >> y >> val;
        for (int i = 0; i < 8; i++){
            if (check(x + dirX[i]) and check(y + dirY[i])){
                lists.push_back({x + dirX[i], y + dirY[i]});
                ii dir = {x + dirX[i], y + dirY[i]};
                valMap[dir] += val;
            }
        }
    }

    ll ans = 0;

    for (auto i: lists){
        ans = max(ans, valMap[i]);
    }

    cout << ans;

    
    return 0;
}
