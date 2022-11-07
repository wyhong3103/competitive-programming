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
 
    pll cnt;
    for(int i{}; i < n; i++){
        if (s[i] == '0') cnt.fir++;
        else cnt.sec++;
    }
 
    ll mx = 0;
    pll cur;
    for(int i{}; i < n; i++){
        if (s[i]-'0' == cur.fir) cur.sec++;
        else{
            cur.fir = !cur.fir;
            cur.sec = 1;
        }
        mx = max(mx,cur.sec * cur.sec);
    }
 
    cout << max(mx, cnt.fir*cnt.sec) << '\n';
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