```

There are N baskets , N <= 1e5

each basket contains a[i] <= 1e12 apples

takashi is going to eat k <= 1e12 apples in total, find the remaining apples in each basket after takashi finish eating K apples.

takashi start eating from basket 1, each time he eats one apple of the basket (if there exist an apple) then move on (with or without eating).


Bruteforcing wouldn't work as the constraint is too big.

The idea is to use a ordered map, find the minimal key of the ordered map (value : frequency)

The minimal value represent how much can we take on that round from each basket.

Minimal value * Available baskets = total apples we can take on that round,

Because of the fact that we can't do range query (I don't know how). We can keep track of the apples taken for each round, and that will apply to the subsequent minimal value.

So it became

(Minimal Value - Taken) * (Available Baskets),

Then

Taken - (minimal value - taken).

It is guaranteed that taken is always smaller than the current minimal value.

Available basket starts from N, as the above process go on, we subtract the frequency of the minimal value each time.

We repeat the above process, until we cannot take all for one round, as that will exceed K. And then, we manually take the apple, as it's the last round.

Having the last minimal value, do not mean that it's the last round. We can still pick the apples for some rounds, but the amount < minimal value-taken.

So we can binary search that value, until we found the it. And do the same thing, subtract taken.

And now we iterate through the N baskets, let a[i] = max(0, a[i] - taken)

Then we manually do the last round until we hit K.
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
    ll n, k;
    cin >> n >> k;

    map<ll, int> freq;

    vll a(n);
    for(auto& i : a){
        cin >> i;
        freq[i]++;
    }

    ll taken = 0;
    ll available = n;
    ll temp_k = k;
    while (sz(freq) && temp_k - ((((freq.begin())->fir)-taken) * available) >= 0){
        temp_k -= ((freq.begin())->fir-taken) * available;
        available -= freq.begin()->sec;
        taken += (freq.begin()->fir-taken);
        freq.erase(freq.begin()->fir);
    }

    ll lo = taken, hi = freq.begin()->fir;
    while (hi > lo){
        ll mid = lo + (hi-lo+1)/2;
        if (temp_k - ((mid-taken)*available) >= 0) lo = mid;
        else hi = mid-1;
    }

    temp_k -= (lo-taken)*available;
    taken += (lo-taken);

    for(int i{}; i < n; i++){
        a[i] = max(0LL, a[i]-taken);
    }

    for(int i{}; i < n; i++){
        if (!temp_k) break;
        if (a[i]){
            a[i]--;
            temp_k--;
        }
    }

    for(auto& i : a) cout << i << ' ';
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