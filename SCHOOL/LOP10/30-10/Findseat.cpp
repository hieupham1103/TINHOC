#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("Findseat.inp","r",stdin);
    freopen("Findseat.out","w",stdout);
    int n,m,t;
    cin>>n>>m>>t;
    if (t/m+bool(t%m)<=n){
        cout<<t/m+bool(t%m)<<' '<<t%m;
    }
    else cout<<-1;
    return 0;
}