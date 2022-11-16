```

Initial Approach (TLE)

It is better to OR it to a bigger value!

maximize each single number! (prioritize bigger number)

from biggest value to smallest

for each of the bit, if it's a 0, we grab the smallest possible number of that bit

every bigger number has been fulfilled!

only grab smaller number! to fulfil current

The idea is, a bit would be a greater value in bigger number (after squaring)! So we always prioritize filling the big number! And to basically only do the operation on a pair of number if the sum of square is better than the initial!

The idea is to use a multiset to store all the number, and a 2 dimensional array [i][j] that stores every number j which bit i of it is set. Iterate the big number, if bit x is 0, we take number from bit[x]! And then change the current number to a[i] | a[bit[x][0]], and then remove the number from bit[x], get the new number of it, which is a[i] & a[bit[x][0]] and change everything of it (the bit it belongs to, and the multiset).

Time complexity : O(N log^3 N)

THIS IS TOO SLOW!!!

OPTIMIZED AC

Because of the way we fill the number, it doesn't really matter if we fill a bigger or a smaller because we're just filling the 0s, even if we had a 0, we're just going to try to fill every 0, so there is no need to "prioritize" bigger number with a multiset which is a waste of time! Also no such thing as use the smallest number to fill that bit, a bit is just going to be shared! it doesn't matter who it shares to! The point is, we want as many huge single number as possible.

The idea is similar ,

We iterate through the array, for every a[i], we remove it from the bit[i][j] array (because we're maximizing it right now, and we will not be doing anything on it later!), we fill all its 0 with the number available, and then change the number used to it's new bit!

Time complexity : O(N log^2 N)

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
    vll a; 
    vector<unordered_set<int>> bits(32);

    for(int i{}; i < n; i++){
        ll x;
        cin >> x;
        a.pb(x);
        for(int j{}; j <= 30; j++){
            if ((1LL << j) & x) bits[j].insert(i);
        }
    }

    for(int i{}; i < n; i++){
        ll& cur = a[i];
        for(int j{}; j <= 30; j++){
            if ((1LL << j) & cur){
                bits[j].erase(i);
            }
        }
        for(int j{}; j <= 30; j++){
            if (!((1LL << j) & cur) && sz(bits[j])){
                int index = *bits[j].begin();
                ll val = a[index];
                ll y = cur & val;
                a[index] = y;
                cur |= val;

                //put it into the new bit
                for(int k{}; k <= 30; k++){
                    if ((1LL << k) & val){
                        bits[k].erase(index);
                    }
                }
                for(int k{}; k <= 30; k++){
                    if ((1LL << k) & y){
                        bits[k].insert(index);
                    }
                }
            }
        }
    } 

    ll sm = 0;
    for(auto& i : a){
        sm += i * i;
    }
    cout << sm;
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