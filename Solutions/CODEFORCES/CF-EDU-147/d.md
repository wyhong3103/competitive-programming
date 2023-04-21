```
Let's prove only segment of length 1 is harmful

For a segment of 2 or bigger,

notice that,

each segment it takes 2 shift (hold and release) to take all of them.

If we are to take a segemnt of 2 during walk A, and not take a segment of 2 during another walk B.


walk B will be 2 moves ahead of walk A, but walk A already has 2 black cells, walk B with 0.

For a segment C of black cells, walk B need to walk 2 more moves to get what A has. When that happens, walk A and walk B will have the same amount of moves with same amount of black cells, but walk A is before walk B and it can take more black cells ahead, which is more optimal.

The idea is basically we used 2 moves, to get >= 2 black cells, for a walk to recover from this it needs to do >= 2 moves to get back what we already got.

But this is not the case for a segment of 1!

So the idea to solve this problem is

We can first take all prefix segment, just to fulfill k.

If after that we can take more, we try to take, as we take the new segments, we remove as many previous 1 we have taken as possible. We get the minimum of everyone of them.

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
    int n, k;
    cin >> n >> k;
 
    vi l(n);
    vi r(n);
    for(auto& i : l) cin >> i;
    for(auto& i : r) cin >> i;
 
 	//number of 1 taken
    int cnt = 0;
    ll res = LONG_LONG_MAX;
    //number of shift moves used
    ll moves = 0;
    //number of black cells
    ll sm = 0;
    for(int i{}; i < n; i++){
        if (sm + r[i]-l[i]+1 >= k){
            int mn = 0;
            if (sm >= k){
                mn = min(cnt, r[i]-l[i]+1);
                res = min(res, moves - (mn * 2) + 2 + l[i] + mn - 1);
            }else{
                int remain = (r[i]-l[i]+1)-(k-sm);
                mn = min(remain, cnt);
                res = min(res, moves+2+l[i]+(k-sm-1));
                res = min(res, moves-(mn*2)+2+l[i]+(k-sm-1)+mn);
            }
            cnt += r[i]==l[i];
            moves += 2; 
            sm += r[i]-l[i]+1;
 
            cnt -= mn;
            sm -= mn;
            moves -= mn * 2;
        }else{
            cnt += r[i] == l[i];
            moves += 2;
            sm += r[i]-l[i]+1;
        }
        if (res != LONG_LONG_MAX && !cnt) break;
    }
 
    cout << (res == LONG_LONG_MAX ? -1 : res) << '\n';
 
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