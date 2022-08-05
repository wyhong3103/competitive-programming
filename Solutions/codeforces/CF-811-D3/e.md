```
Every odd number will eventually become an even number.

Only 5 and 0 will not. 5 -> 0 , and is a dead end.

Otherwise, it goes on such a loop

2 --> 4 --> 8 --> 6 --> 2 ...

Notice that one full cycle of this even loop, is a step of 20.

An array can all be equal iff they're in same cycle. That means we can use one minimum element to try and see if every other element are in that cycle.

But we have got to be efficient, since number is  < 10^9, so, to test whether two number can be in a cycle, we can first remove all the steps of 20, bring them as close as possible, and manually test if one can reach another by going through the even steps.
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
    int n;
    cin >> n;
 
    ll mn = INT_MAX;
    vll a(n);
    for(auto& i : a){
        cin >> i;
        if (i % 2){
            i += i % 10;
        }
        mn = min(i, mn);
    }
 
 
    bool ok = 1;
    for(int i{}; i < n; i++){
        bool ok_temp = 0;
        if (a[i]%10 != 0){
            ll steps = (a[i]-mn)/20;
            ll final_dist = (a[i]-mn)-(steps*20);
            ok_temp = (final_dist == 0);
 
            ll first = mn%10;
            ll temp = mn + (steps*20) + (mn % 10);
            while ((temp%10) != first){
                if (temp == a[i]) ok_temp = 1;
                temp += temp%10;
            }
        }else{
            ok_temp = (mn == a[i]);
        }
        if (!ok_temp) ok = 0;
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