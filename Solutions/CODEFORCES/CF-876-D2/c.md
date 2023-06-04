```
given a sequence a consist of binary numbers
 
and a sequence b, which is initally empty
 
we're going to perform n operations on b
 
at the ith operation, we choose an integer from 0 to i-1, p, 
 
at p+1 insert a 0, for every element before p, NOT it
 
is it possible to get a at the end
 
we always start with 0, 
 
basically, in the existing array b, we can insert 0 at any arbitary position, and every element before it is NOTed

Example,
 
1 1 0 0 0

Strategy 

make 4 0 first
 
0 0 0 0
 
0 0 |0| 0 0 -> 1 1 0 0 0

we can start by constructing from the last element
 
not possible to have 1 as the first element, because we can never NOT the last element
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
    int n;
    cin >> n;
 
    vi a(n);
    for(auto& i : a) cin >> i;
 
    if (a[n-1] == 1){
        cout << "NO" << '\n';
        return;
    }
 
    vi res;
 
    int at = n-1;
    while(at >= 0){
        pi cnt;
        for(int i{at}; i >= 0; i--){
            if (a[i] == 1) break;
            cnt.fir++;
        }
 
        at -= cnt.fir;
 
        for(int i{at}; i >= 0; i--){
            if (a[i] == 0) break;
            cnt.sec++;
        }
 
        at -= cnt.sec;
 
        for(int i{}; i < cnt.fir+cnt.sec-1;i++){
            res.pb(0);
        }
        res.pb(cnt.sec);
    }
 
    cout << "YES" << '\n';
    for(auto& i : res) cout << i << ' ';
    cout << '\n' ;
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