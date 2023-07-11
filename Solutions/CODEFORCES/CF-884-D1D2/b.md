Any subarray that doesn't have $1$ will not be counted, we want to minimize this, so it is always optimal to put $1$ in the middle of the array, if $n$ is an even number, it doesn't matter if we put it at $\frac{n}{2}$ or $\frac{n}{2} + 1$, because the total subarray that contains 1 remain the same.

Another thing is that, we should put $2$ and $3$ at both end of the array, because other than $[1,n]$, every subarray that contains $1$ will be counted.

Hence, this yields the optimal answer.

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
    int n;
    cin >> n;
 
    if (n <= 2){
        for(int i{}; i < n; i++) cout << i + 1 << ' '; 
    }else{
        vi a(n, -1);
        a[0] = 2;
        a[n-1] = 3;
        a[n/2] = 1;
        int cur = 4;
        for(int i{1}; i <= n; i++){
            if (a[i] == -1) {
                a[i] = cur++;
            }
        }
        for(auto& i : a) cout << i << ' ';
    }
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