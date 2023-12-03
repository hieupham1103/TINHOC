#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

char a[maxN];
int num1[maxN];
int num2[maxN];

signed main(){
    freopen("ABSTR.INP", "r", stdin);
    freopen("ABSTR.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }  
        num2[0] = 0;
        num1[n + 1] = 0;
        for (int i = 1; i <= n; i++){
            num2[i] = num2[i - 1] + (a[i] == 'B');
        }

        for (int i = n; i >= 1; i--){
            num1[i] = num1[i + 1] + (a[i] == 'A');
        }

        // for (int i = 1; i <= n; i++){
        //     cout << num1[i] << " " << num2[i] << endl;
        // }

        int ans = n;

        for (int i = 0; i <= n; i++){
            int t = num2[i] + num1[i + 1];
            ans = min(ans, t);
        }

        cout << ans << endl;
    }

    return 0;
}