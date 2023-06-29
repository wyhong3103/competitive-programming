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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
   int n, k, x;
   cin >> n >> k >> x;
 
   if (x > 1){
        cout << "YES" << '\n';
        cout << n << '\n';
        for(int i{}; i < n; i++) cout << 1 << ' ';
        cout << '\n';
   }else{
        if (n % 2 == 0 && k >= 2){
            cout << "YES" << '\n';
            cout << n/2 << '\n';
            for(int i{}; i < n/2; i++) cout << 2 << ' ';
            cout << '\n';
        }else{
            //if n >= 3, then yes
            if (k <= 2) cout << "NO" << '\n';
            else{
                cout << "YES" << '\n';
                cout << n/2 << '\n';
                cout << 3 << ' ';
                for(int i{1}; i < n/2; i++) cout << 2 << ' ';
                cout << '\n';
            }
        }
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