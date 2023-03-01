```

The idea is to recursively solve it. To solve top i stack, we use the same tactic we used to solve top i-1 stack, but to map to different rod.

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

int N;

vector<pi> recur(int n){
    if (n == 1){
        return {{0,  (N%2? 2 :1)}}; 
    }

    vector<pi> prev = recur(n-1);

    vector<pi> sol = prev;

    if (N % 2){
        if (n % 2){
            sol.pb({0, 2});
            vi mp = {1, 2, 0};
            for(auto& i : prev){
                sol.pb({mp[i.fir], mp[i.sec]});
            }
        }else{
            sol.pb({0, 1});
            vi mp = {2, 0, 1};
            for(auto& i : prev){
                sol.pb({mp[i.fir], mp[i.sec]});
            }
        }
    }else{
        if (n % 2 == 0){
            sol.pb({0, 2});
            vi mp = {1, 2, 0};
            for(auto& i : prev){
                sol.pb({mp[i.fir], mp[i.sec]});
            }
        }else{
            sol.pb({0, 1});
            vi mp = {2, 0, 1};
            for(auto& i : prev){
                sol.pb({mp[i.fir], mp[i.sec]});
            }
        }
    }

    return sol;
}

void solve(){
    cin >> N;

    vector<pi> sol = recur(N);

    cout << sz(sol)<< '\n';
    for(auto& i : sol){
        cout << i.fir+1 << ' ' << i.sec+1 << '\n';
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