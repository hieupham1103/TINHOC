#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	long long ans=0;
	while(n>0){
		ans=max(ans,n%10);
		n/=10;
	}
	cout<<ans;
	return 0;
}