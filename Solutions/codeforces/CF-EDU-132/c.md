DNS
```
First observation


In order for one bracket sequence to be valid, number of left parenthesis at any prefix must be >= the right parenthesis and prefix at the end must be equal

Another way to count this is to see left parenthesis as 1, and right as -1. The end must be 0, and the sum of prefix at every i must be positive.

We're given a bracket sequence that is always valid, we are to look for whether there is only one unique solution to it.

One solution that will always work is to greedily put '(' at the front, and ')' at the back, this is because if we're to put '(' at any prefix we could, sum will always be positive (say it's a valid sequence), and then only put ')' at the end.

The next solution that will most probably work (the 2nd solution), say we got A left parentehsis, and B right parenthesis, the next most probable solution is where we could inverse the last left parenthesis and the first right parenthesis. This can be proven by math obviously. If this doesn't work, none will work.

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
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    string s;
    cin >> s;
    
    pi lr{};
    int x{};
    for(auto& i : s){
        if (i == '(')  lr.fir++;
        else if (i == ')') lr.sec++;
        else x++;
    }
 
    //{number of l allowed, number of r allowed}
    pi lr_balanced{};
    lr_balanced.sec = (lr.fir+x-lr.sec)/2;
    lr_balanced.fir = x-lr_balanced.sec;
 
    pi index{-1,-1};
    for(int i{}; i < sz(s); i++){
        if (s[i] == '?'){
            if (lr_balanced.fir){
                index.fir = i; 
                s[i] = '(';
                lr_balanced.fir--;
            }else{
                if (index.sec == -1) index.sec = i;
                lr_balanced.sec--;
                s[i] = ')';
            }
        }
    }
 
 
    bool ok = 1;
    if (index.fir != -1 && index.sec != -1){
        ok = 0;
        s[index.fir] = ')';
        s[index.sec] = '(';
 
        int sm = 0;
        for(int i{}; i < sz(s); i++){
            sm += (s[i] == '(' ? 1 : -1);
            if (sm < 0) ok = 1;
        }
        if (sm > 0) ok = 1;
    }
 
 
    cout << (ok ? "YES" : "NO") << '\n';
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