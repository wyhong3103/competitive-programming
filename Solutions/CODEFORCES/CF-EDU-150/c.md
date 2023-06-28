```

bruteforce every letter, only with leftmost / rightmost, since that's the optimal, leftmost make sure the least get impacted by it, rightmost make sure they dont get impacted as well

```
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
    vll a = {1, 10, 100, 1000, 10000};
    
    vector<pi> lr(5, {INT_MAX, -1});
 
    for(int i{}; i <sz(s); i++){
        lr[s[i]-'A'].fir = min(lr[s[i]-'A'].fir, i);
        lr[s[i]-'A'].sec = max(lr[s[i]-'A'].sec, i);
    }
 
    ll mx = LONG_LONG_MIN;
    for(int i{}; i < 5; i++){
        if (lr[i].fir != INT_MAX){
            for(int j{}; j < 5; j++){
                s[lr[i].fir] = j+'A';
                vi r(5, -1);
                for(int k{}; k < sz(s); k++){
                    r[s[k]-'A'] = max(r[s[k]-'A'], k);
                }
 
                ll val = 0;
                for(int k{}; k < sz(s); k++){
                    bool found = 0;
                    for(int l{s[k]-'A'+1}; l < 5; l++){
                        found |= r[l] > k;
                    }     
                    val += (ll)(found ? -1 : 1) * (ll)a[s[k]-'A'] ;
                }
                mx = max(mx, val);
                s[lr[i].fir] = i+'A';
            }
        }
 
        if (lr[i].sec != -1){
            for(int j{}; j < 5; j++){
                s[lr[i].sec] = j+'A';
                vi r(5, -1);
                for(int k{}; k < sz(s); k++){
                    r[s[k]-'A'] = max(r[s[k]-'A'], k);
                }
 
                ll val = 0;
                for(int k{}; k < sz(s); k++){
                    bool found = 0;
                    for(int l{s[k]-'A'+1}; l < 5; l++){
                        found |= r[l] > k;
                    }     
                    val += (ll)(found ? -1 : 1) * (ll)a[s[k]-'A'] ;
                }
                mx = max(mx, val);
                s[lr[i].sec] = i+'A';
            }
        }
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