#include <iostream>

using namespace std;

int n;
char a[50];

void backTracking(int d) {
	if (d > n) {
		for (int i = 1; i <= n; i++) {
			cout << a[i];
		}
		cout << "\n";
	}
	else {
		a[d] = 'A';
		backTracking(d + 1);

		if (a[d - 1] == 'A') {
			a[d] = 'B';
			backTracking(d + 1);
		}
	}
}

int main() {
	freopen("BAI44QL.INP", "r", stdin);
	freopen("BAI44QL.OUT", "w", stdout);

	cin >> n;

	a[1] = 'A';
	backTracking(2);
	a[1] = 'B';
	backTracking(2);

	return 0;
}