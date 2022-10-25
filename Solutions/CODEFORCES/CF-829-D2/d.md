```

This whole thing is a factorial, so that mean, we can sort it and we can always factorize it.


6 4
3 2 2 2 3 3


3*2! + 3*3!

factorize to


2! (3 + 3 * 3)

so our denominator became 3*4

3 + 3 * 3 (this is intially 3 factorial, and now we have a multiple of 3, we need to factor it out!)

Notice that the 3 on the left is just a coincidence because of the fact that we have 3 number of 2!. That's the reason we can factor the 3 out

3(1 + 3) 

denominator became 4

1 + 3, divisible by 4 

done.

Everytime we factor out a number, we need to consider the previous sum left out, it will always be in following form


z + yx

z is the previous sum left out, y is the current factorial we are to deal with, x is all the number in it

In order for the entire equation to be divisible by y, z have to be divisible by y as well, or else it's not going to happen!


Sometime it could be something like this


z + (200!)x

there's no way we would do 200!, but one thing is that z would never be bigger than a certain number, because it's the frequency of previous numbers. So we can just stop verifying if the factorial actually got bigger than z.

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
    ll n, x;
    cin >> n >> x;
 
    vi a(n);
    for(auto& i : a) cin >> i;
    
    vi cnt((5e5)+5);
 
    for(auto& i : a) cnt[i]++;
 
    set<int> remain;
    for(int i{1}; i <= x; i++) remain.insert(i);
 
    int cur = 1;
    bool ok = 1;
    ll sm = 0;
    for(int i{1}; i <= x; i++){
        if (cnt[i]){
            ll fac = 1;
            while (cur != i){
                if (sm) fac *= cur;
                remain.erase(cur++);
                if (fac > sm && sm != 0){
                    ok = 0;
                    break;
                }
            }
            if (sm) fac *= cur;
            remain.erase(cur++);
            if (sm % fac == 0) sm /= fac;
            else ok = 0;
            sm += cnt[i];
            if (!ok) break;
        }
    }
 
    ll fac = 1;
    while (!remain.empty() && ok && sm){
        fac *= *remain.begin();
        remain.erase(remain.begin());
        if (fac > sm && sm != 0){
            ok = 0;
            break;
        }
    }
 
    if (ok && sm % fac == 0){
        cout << "Yes";
    }else cout << "No";
}
    
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```