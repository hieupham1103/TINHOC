#include <bits/stdc++.h>
using namespace std;

long long a[100005];


int main() {
	freopen("TKNP.INP","r",stdin);
	freopen("TKNP.OUT","w",stdout);
	int n;
	long long k;
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	int left=1;
	int right=n;
	while (left<=right){
		int mid=(left+right)/2;
		if (a[mid]==k){
			cout<<mid;
			return 0;
		}
		else if (k<a[mid]){
			right=mid-1;
		}
		else {
			left=mid+1;
		}
	}
	cout<<-1;

	return 0;
}