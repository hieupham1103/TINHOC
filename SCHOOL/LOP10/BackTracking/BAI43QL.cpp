#include<bits/stdc++.h>
using namespace std;

string s;
bool check[100] = {0};
string ans = "";
void backTracking(int index){
    // cout << '#' << endl;
    for (int i = 0; i < s.size(); i++){
        if (check[i] == 0){
            check[i] = 1;
            ans += s[i];
            backTracking(index + 1);
            if (index >= s.size() - 1){
                cout << ans << endl;
            }
            ans = ans.substr(0, ans.size() - 1);
            check[i] = 0;
        }
    }
}

int main(){
    freopen("BAI43QL.INP", "r", stdin);
    freopen("BAI43QL.OUT", "w", stdout);
    
    cin >> s;
    backTracking(0);
    // cout << s.substr(0, s.size() - 1);
    return 0;
}