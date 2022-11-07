```


Proof on why a and b, either a != b for all bits or a == b for all bits

say we are to flip a[l:r]

b[1:l] b[r:n] got flipped

we go from 0 = 0 to x = !y (x is the inverse of y)

now if we decide to do a[l:r] on anywhere, it is for sure that a[l:r] and b[l:r] at that range is different (assuming previously they are different).

now a[l:r] is going to flip to match b[l:r], the previous l:r on b is going to flip to match the previous a[l:r] and everything else is going to flip back. 


And now they're the same.

So the idea right now is, turn a into 0..000, b is either 1...111 or 0...0000


if it's the first one

we can do the following

(1,1)
(1,n)
(2,n)

This will always work.

If the latter, simply print the answer

It could be done within n/2 + 3 operation (pigeonhole principle, we can do it as a segment)

Messed this up during the contest, got too reckless, i had strings which don't fit the property above, i probably ruined it somewhere, hence i did not realize it.
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
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    
    pi ok {1, 1};
    
    for(int i{}; i < n; i++){
        if (a[i] != b[i]) ok.fir = 0;
        if (a[i] == b[i]) ok.sec = 0;
    }
 
    vector<pi> res;
    //just keep track how many time bit 1 has been flipped
    int cur = b[0] - '0';
    for(int i{}; i < n; i++){
        if (a[i] == '1'){
            res.pb({i+1, i+1});
            if (i) cur = !cur;
        }
    }
 
    if (cur){
        res.pb({1, 1});
        res.pb({1, n});
        res.pb({2, n});
    }
 
    if (ok.fir || ok.sec){
        cout << "YES" << '\n';
        cout << sz(res) << '\n';
        for(auto& i :res){
            cout << i.fir << ' ' << i.sec << '\n';
        }
    }else cout << "NO" << '\n';
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