```

My solution is fairly simple, but I honestly don't know if this considered as cheating or no, because I sort of preprocessed the entire queries instead of answering real time queries.

The idea is

We could store all the functions first, and then get the composite funcions of every suffix.

If we ever need to find an answer for the composite funcs on subarray [i, j], we could just use the suffix[i] * inverse func of suffix[j].

let y = f1(f2(f3(f4....(x)))) 

let z = (f1(f2(f3)))^-1

yz = f4...(x)

Something like above, basically solved it mathematically.

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

const int MOD = 998244353;

ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    if (p % 2) return (sq * n) % MOD;
    else return sq;
}

void solve(){
    int q;
    cin >> q;

    vector<pll> f;
    vector<pll> op;
    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            op.pb({1, 0});
        }else if (t == 2){
            int x;
            cin >> x;
            op.pb({2, x});
        }else{
            int a, b;
            cin >> a >> b;
            f.pb({a, b});
            op.pb({0, 0});
        }
    }

    vector<pll> suffix(sz(f));
    if (sz(suffix)) suffix.back() = {f.back().fir, f.back().sec};

    for(int i{sz(f)-2}; i >= 0; i--){
        suffix[i] = {(suffix[i+1].fir*(f[i].fir)) % MOD, (suffix[i+1].sec + (suffix[i+1].fir*f[i].sec)) % MOD};
    }

    int length = 0;
    int cur = 0;
    for(auto& i : op){
        if (i.fir == 1){
            cur++;
        }else if (i.fir == 0){
            length++;
        }else{
            if (length == cur) cout << i.sec << '\n';
            else{
                pi func = suffix[cur];
                if (length != sz(suffix)){
                    pi inv_func = suffix[length];
                    inv_func = {inv_func.sec, inv_func.fir};
                    func = {(func.fir*modpow(inv_func.sec, MOD-2)) % MOD, ((func.sec-inv_func.fir)*modpow(inv_func.sec, MOD-2)) % MOD};
                }
                cout << ((func.fir * i.sec) + func.sec) % MOD << '\n';
            }
        }
    }
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

```

Real time computation

Coefficient of "x" of the composite function is always divisible by all the "a" included in that composite function, because "x" is multiplied by all of them.

As for the other term, notice that each time you get a new composite function by multiplying the new "a" to all the term and add its "b" at the end

And to remove the func_i (must be the innest func) you simply need to divide the current coefficient by "a_i" , and you get the new coefficient, and then subtract the term that consist of "b_i" which is exactly the (new coefficient * "b_i")

LaTex formula for visual aid

f_2(f_1(x)) = (a_2 \cdot a_1 \cdot x) + (a_2 \cdot b_1) + b_2\\
f_3(f_2(f_1(x))) = (a_3\cdot a_2 \cdot a_1 \cdot x) + a_3((a_2\cdot b_1)) + b_2) +b_3 = (a_3\cdot a_2 \cdot a_1 \cdot x) + (a_3\cdot a_2\cdot b_1) + (a_3 \cdot b_2) + b_3

```
```cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll pow(ll b, ll e) {
  if (e == 0) return 1;
  if (e % 2 == 1) return pow(b, e-1) * b % MOD;
  ll val = pow(b, e/2);
  return val * val % MOD;
}
ll inv(ll x) {
  return pow(x, MOD-2);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  int q; cin >> q;
  queue<ll> coef, con;
  ll m = 1, n = 0;
  for (int i = 0; i < q; i++) {
    int com; cin >> com;
    if (com == 0) {
      ll a, b; cin >> a >> b;
      coef.push(a); con.push(b);
      ll new_m = a * m % MOD;
      ll new_n = (a * n + b) % MOD;
      m = new_m; n = new_n;
    } else if (com == 1) {
      ll a = coef.front(); coef.pop();
      ll b = con.front(); con.pop();
      ll inv_a = inv(a);
      ll new_m = inv_a * m % MOD;
      ll new_n = (n - b * new_m) % MOD;
      m = new_m; n = (new_n >= 0 ? new_n : new_n + MOD);
    } else {
      ll x; cin >> x;
      cout << ((m * x + n) % MOD) << "\n";
    }
  }
}
```
