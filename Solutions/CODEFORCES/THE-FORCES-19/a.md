
Let's list down the obvious case first:

- When $[l_1,r_1]$ = $[l_2, r_2]$, it's obvious that the probability of Alice beating Bob will be the same as Bob beating Alice.
- When they are partially intersected, the segment that has bigger $r$ is always gonna win.
- When one segment is full contained inside another segment, let the difference $r_\text{max} - r_\text{min} = d_r$ , and $d_l$ for left
	- If $d_r = d_l$ , probability will also stay the same, because they cancel out each other. Just think of this, when you have outer segment = $[1, 3]$ and inner segment = $[2,2]$. The only difference between these two segments is outer segment has $+1$ and $-1$. So the probability of outer getting sum with $3$ and sum with $1$ is equal, so they cancel out each other.

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
    pll a, b;
    cin >> a.fir >> a.sec;
    cin >> b.fir >> b.sec;
 
    if (a == b){
        cout << "NO" << '\n'; 
    }else if (a.sec > b.sec && a.fir >= b.fir){
        cout << "YES" << '\n'; 
    }else if (b.sec > a.sec && b.fir >= a.fir){
        cout << "NO" << '\n'; 
    }else{
        if (a.sec >= b.sec && a.fir <= b.fir){
            //A contain B
            cout << (a.sec - b.sec > b.fir - a.fir ? "YES" : "NO") << '\n';
        }else{
            //B contain A
            cout << (b.sec - a.sec >= a.fir - b.fir ? "NO" : "YES") << '\n';
 
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