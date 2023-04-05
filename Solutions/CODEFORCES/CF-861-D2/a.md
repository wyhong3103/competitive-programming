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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    vector<vi> a(10);
 
    for(int i{1}; i < 1e6 + 5; i++){
        string s = to_string(i);
        for(int j{}; j < sz(s); j++){
            for(int k{}; k < sz(s); k++){
                a[abs(s[j]-s[k])].pb(i);
            }
        }
    }
 
    int n;
    cin >> n;
    while(n--){
        int l, r;
        cin >> l >> r;
        
        for(int i{9}; i  >= 0; i--){
            if (lower_bound(all(a[i]), l) != a[i].end() && *lower_bound(all(a[i]), l) <= r){
                cout << *lower_bound(all(a[i]), l) << '\n';
                break;
            }
        }
    }
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