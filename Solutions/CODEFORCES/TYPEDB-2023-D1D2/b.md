```

I finish this problem slightly slower, cus I forgot the naive way to prime factorize a number.

Let's prove our greedy

say we have

prime factor of n = a1^p1 * a2^p2

when p1 > 1 and p2 > 1, it's always better to do a1*a2 rather than having a power of 2 on them

Proof

Say we have

a^2 * b^2

the value F will be a*2 + b*2 = (a+a) + (b+b), and we know that any a_i >= 2,

So if we are to extract one of the b and combine it with a, we wouldn't lose anything in fact we would get a bigger sum, the reason is because each individual b in b^2 (which would become (b+b)) only contributes b. If we are to combine it in a product, it would just contribute more, since an individual a_i >= 2, so a_i * b will always be bigger than just b.

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
    ll n;
    cin >> n;
    
    map<int,int> pf;
    for(int i{2}; i * i <= n; i++){
        while (n % i == 0){
            pf[i]++;
            n/=i;
        }
    }
    if (n > 1) pf[n]++;
 
    ll res = 0;
 
    while (sz(pf)){
        ll product = 1;
        for(auto& i : pf){
            product *= i.fir;
            i.sec--;
        } 
        auto it = pf.begin();
        while (it != pf.end()){
            if (!it->sec){
                pi temp = *it;
                it++;
                pf.erase(temp.fir);
            }else{
                it++;
            }
        }
        res += product;
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