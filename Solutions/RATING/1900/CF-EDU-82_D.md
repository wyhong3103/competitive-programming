```
abridged statement


we have m numbers, each is 2^x, x >= 0

we need to be able to sum some numbers up s.t the sum is exactly n

one operation we can divide 2^x to 2^x-1, 2^x-1


Solution

starting from the smallest bit

if the bit is on in n, and we have available we take it, subtract 1,

and then combine the rest move on to the next bit, if its an odd number, 1 is gonna stay there the rest move up (divide by 2).

if n is on, but we do not have it,

two options 
- break larger chunk to fill the cur bit 
- break larger chunk to combine with previous leftout bits 

first option is better in terms of minimal move

Theorem : We do not need to combine with previosu bits at all!

Proof

If there always a bigger bit for us to divide, then we should always do it so that it fits us. if there isn't one, its simply impossible.
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
    ll n, m;
    cin >> n >> m;

    vll cnt(100);
    set<ll> s;

    ll total = 0;
    for(int i{}; i < m; i++){
        ll x;
        cin >> x;
        cnt[__builtin_ctzll(x)]++;
        s.insert(x);
        total += x;
    }

    if (total < n){
        cout << -1 << '\n';
        return;
    }

    ll res = 0;
    for(int i{}; i <= 60; i++){
        if ((1LL << i) & n){
            if (!cnt[i]){
                //get bigger chunk
                ll cur = *s.lower_bound(1LL << i);
                while (cur != (1LL << i)){
                    int pos = __builtin_ctzll(cur);
                    cnt[pos]--;
                    if (!cnt[pos]) s.erase(cur);
                    cnt[pos-1] += 2;
                    s.insert(cur/2);
                    cur /= 2;
                    res++;
                }
            }
            cnt[i]--;
        }

        if (cnt[i] >= 2){
            cnt[i+1] += cnt[i]/2;
            cnt[i] %= 2;
            s.insert((1LL << (i+1)));
        }
        if (!cnt[i]) s.erase(1LL << i);
    }

    cout << res << '\n';
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