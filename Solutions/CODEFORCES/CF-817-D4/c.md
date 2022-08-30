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
    
    vi score(3);
 
    map<string,vi> freq;
 
    for(int i{}; i < 3; i++){
        for(int j{}; j < n; j++){
            string s;
            cin >> s;
            freq[s].pb(i);
        }
    }
 
    for(auto& i : freq){
        if (sz(i.sec) == 1){
            for(auto& j : i.sec) score[j]+=3;
        }else if (sz(i.sec) == 2){
            for(auto& j : i.sec) score[j]++;
        }
    }
 
    for(auto& i : score) cout << i << ' ';
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