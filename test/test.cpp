#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m = 0;
    int x = -1, y = -1;
    for (int A = 4; A <= 1000; A++){
    for (int B = 4; B <= 1000; B++){
        int a = A;
        int b = B;
        if (__gcd(a,b) != 1){
            // cout << 0 << endl;
            continue;
        }
        if (abs(a - b) == 1){
            // cout << -1 << endl;
            continue;
        }
        if (a % 2 == b % 2){
            // cout << 1 << endl;
            continue;
        }
        int ans = 1;
        while(__gcd(a + 1, b + 1) == 1){
            ans++;
            a++;
            b++;
        }

        // cout << ans << endl;
        if (ans > m){
            m = ans;
            x = A;
            y = B;
        }
    }
    }

    cout << m << " ";
    cout << x << " " << y << endl;
    return 0;
}