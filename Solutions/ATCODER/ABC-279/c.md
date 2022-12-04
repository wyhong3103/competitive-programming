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
    int n, m;
    cin >> n >> m;
 
    vector<string> s(n);
    for(auto& i : s) cin >> i;
    vector<string> t(n);
    for(auto& i : t) cin >> i;
 
    map<string,int> freq;
 
    for(int j{}; j < m; j++){
        string temp;
        for(int i{}; i < n; i++){
            temp += s[i][j];
        }
        freq[temp]++;
    }
 
    bool ok = 1;
    for(int j{}; j < m; j++){
        string temp;
        for(int i{}; i < n; i++){
            temp += t[i][j];
        }
        ok &= (freq.count(temp) && freq[temp]--);
    }
    cout << (ok? "Yes": "No");
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