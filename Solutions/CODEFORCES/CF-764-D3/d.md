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
    int n, k;
    cin >> n >> k;
 
    vi freq(26);
 
    string s;
    cin >> s;
    for(auto& i : s){
        freq[i-'a']++;
    }
 
    int cnt = 0;
    int total = 0;
    for(int i{}; i < 26; i++){
        total += freq[i]/2;
        cnt += freq[i] % 2;
    }
    
    cout << total/k * 2 + ((((total - (total/k * k)) * 2) + cnt) >= k) << '\n';
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