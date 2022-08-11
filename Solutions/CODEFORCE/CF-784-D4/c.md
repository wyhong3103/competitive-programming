It's only possible to make all number even if all odd/even numbers has the same even/odd properties
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vi a(n);
        for(auto& i : a) cin >> i;
 
        bool ok = true;
        int prev = 0;
        for(int i{}; i < n; i+=2){
            if (i > 0 && a[i] % 2 != prev){
                cout << "NO" << '\n';
                ok = false;
                break;
            }
            prev = a[i] % 2;
        }
 
        if (ok){
            for(int i{1}; i < n; i+=2){
                if (i > 1 && a[i] % 2 != prev){
                    cout << "NO" << '\n';
                    ok = false;
                    break;
                }
                prev = a[i] % 2;
            }
            if (ok)cout << "YES" << '\n';
        }
 
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```