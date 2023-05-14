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
 
ll gcd(int a, int b){
    return (!b ? a : gcd(b , a % b));
}
 
void solve(){
    int n;
    cin >> n;
 
    vi a(n);
    for(auto& i : a) cin >> i;
 
    int g = -1;
    for(int i{}; i < n; i++){
        if (a[i] != i+1){
            if (g == -1) g = abs(i-(a[i]-1));
            else g = gcd(g, abs(i-(a[i]-1)));
        }
    }
    cout << g << '\n';
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