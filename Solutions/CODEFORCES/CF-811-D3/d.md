Greedily select string that could take us to the furthest at each instance.
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
    string s;
    cin >> s;
    
    int n;
    cin >> n;
 
    vector<string> a(n);
    for(auto& i : a) cin >> i;
 
    //for each index store the longest we could use, including self
    vector<pi> bst(sz(s));
    for(auto& i : bst) i = {-1,-1};
 
    for(int i{}; i < n; i++){
        if (sz(a[i]) > sz(s)) continue;
        for(int j{}; j <= sz(s)-sz(a[i]); j++){
            if (s.substr(j, sz(a[i])) == a[i]){
                for(int k{}; k < sz(a[i]); k++){
                    if ((int)(sz(a[i])-k) > bst[j+k].fir){
                        bst[j+k].fir = (sz(a[i])-k);
                        bst[j+k].sec = i;
                    }
                }
 
            }
 
        }
    }
 
    for(auto& i : bst){
        if (i.fir == -1){
            cout << -1 << '\n';
            return;
        }
    }
 
    vector<pi> res;
    int at = 0;
    while (at < sz(s)){
        res.pb({at-(sz(a[bst[at].sec])-bst[at].fir),bst[at].sec});
        at += bst[at].fir;
    }
 
    cout << sz(res) << '\n';
    for(auto& i : res) cout << i.sec+1 << ' ' << i.fir+1 << '\n';
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
```