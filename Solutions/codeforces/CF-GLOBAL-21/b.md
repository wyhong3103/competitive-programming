Apparently, other than counting the segment of non zeros, a faster way is just 2 way
```
Imagine if we have


0 1 1 0 1 1 0 1 1

If we were to count the number of non zeros segment, we would've got 3 but

if we were to turn everything into the mex, the current mex in the array is 2

2 2 2 2 2 2 2 2 2

Then the the next mex is just 0, so it's just 2
```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;
 
    int res = 0;
    bool in = 0;
    for(auto& i : a){
        if (!in && i){
            in = 1;
        }else if (in && !i){
            res++;
            in = 0;
        }
    }
    res += in;
 
    cout << min(res, 2) << '\n';
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