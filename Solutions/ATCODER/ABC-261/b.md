```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using pll = pair<ll,ll>;
using vll = vector<ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;
 
    vector<string> a(n);
    for(auto& i : a) cin >> i;
 
    bool ok = 1;
    for(int i{}; i < n; i++){
        for(int j{}; j < n; j++){
            if (i == j) continue;
            if ((a[i][j] != 'D' && a[i][j] == a[j][i]) || (a[i][j] == 'D' && a[i][j] != a[j][i])) ok = 0;
        }
    }
 
    cout << (ok ? "correct" : "incorrect");
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
	return 0;
}
```