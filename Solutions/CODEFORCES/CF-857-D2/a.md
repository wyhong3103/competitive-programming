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
    int n;
    cin >> n;
 
    vi a(n);
    for(auto& i : a) cin >> i;
 
    set<int> s;
    for(auto& i : a){
        s.insert(abs(i));
    }
 
    for(int i{}; i < sz(s); i++){
        cout << i+1 << ' ';
    }
    int cnt = 1;
    for(int i{sz(s)}; i < n; i++){
        cout << sz(s)-cnt << ' ';
        cnt++;
    }
    cout<<'\n';
    for(int i{}; i < (n-(int)sz(s)) * 2; i++){
        cout << ((i+1) % 2) << ' ';
    }
    for(int i{(n-(int)sz(s)) * 2}; i < n; i++){
        cout << i-((n-(int)sz(s)) * 2)+1 << ' ';
    }
    cout << '\n';
 
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