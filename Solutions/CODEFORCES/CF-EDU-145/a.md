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
    string s;
    cin >> s;
    map<char,int> st;
    for(auto& i : s){
        st[i]++;
    }
 
    int n = sz(st);
    if (n == 4) cout << 4 << '\n';
    else if (n == 2){
        // 2 2
        // 3 1
        
        if (st.begin()->sec != 2)cout << 6 << '\n';
        else cout << 4 << '\n';
    }
    else if (n == 3) cout << 4 << '\n';
    else cout << -1 << '\n';
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