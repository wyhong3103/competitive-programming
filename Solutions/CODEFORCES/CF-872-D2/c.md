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
    int n,m;
    cin >> n >> m;
 
    int l = 0, r = 0;
    vi found(m+1);
    vi seat;
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        if (x == -1) l++;
        else if (x == -2) r++;
        else {
            if (!found[x]) seat.pb(x);
            found[x]=1;
        }
    }
 
    sort(all(seat));
 
    int mx = max(min(m, (int)sz(seat)+l), min(m, (int)sz(seat)+r));
    for(int i{}; i < sz(seat); i++){
        mx = max(mx, 1 + min(seat[i]-1, l+i) + min(m-seat[i], r+((int)sz(seat)-i-1)));
    }
    cout << mx << '\n';
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