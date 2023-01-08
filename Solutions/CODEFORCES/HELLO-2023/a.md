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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    int n;
    cin >> n;
 
    string s;
    cin >> s;
 
    pair<int,int> p {-1, n};
    for(int i{}; i < n; i++){
        if (s[i] == 'L') p.fir = max(p.fir, i);
        else p.sec = min(p.sec, i);
    }
 
    if (p.sec == n || p.fir == -1) cout << -1 << '\n';
    else if (p.fir > p.sec) cout << 0 << '\n';
    else{
        for(int i{}; i < n-1; i++){
            if (s[i] == 'L' && s[i+1] == 'R'){
                cout << i+1 << '\n';
                return;
            }
        }
        cout << -1 << '\n';
    }
 
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