
## Abridged Statement

There are $n$ benches, and $m$ cookies sellers, $i$ cookie seller is at bench $m_i$ Petya starts at bench $1$ and walk to the next one every minute, Petya eats cookie under the following conditions:
- Petya has never eaten any cookie before (basically when Petya is at $1$)
- Petya is at one of the $m_i$ (Petya eats cookie when there is a cookie seller)
- The bench that Petya had his/her (I have no idea Petya is a boy or girl) last cookie is $d$ distance away from current bench

Determine the minimum number of cookies Petya had after removing exactly one cookie seller, and the number of different cookie sellers that we can remove which will result in the minimum cookies Petya eat.

## Approach

Let's assume we're currently at bench $i$ where there is a cookie seller, and the next cookie seller is at $j$. We will have a cookie at $i$, and before we reach $j$, we will have $\frac{j-i-1}{d}$ another cookies. As you can see, the number of cookies we have from $i$ to $j$ is not affected by any other cookie sellers.

With the above, we can compute, the number of cookies we will eat if we are to stop at bench $i$ from $1$, let's call it $pf[i]$. And then, also compute the number of cookies we will eat if we stop at bench $n$ from bench $i$, let's call it $sf[i]$.

Okay let's say now we want to remove cookie seller at $m_i$. The total cookies we would have is $pf[i-1] + sf[i+1] + \frac{m_{i+1} - m_{i-1} - 1}{d}$. Special case is for $i = 1$ and $i = n$. But it shouldn't have any trouble.

Now we can try to remove every cookie seller (and count the cookies eaten in $O(1)$), and count the total of them that result in minimum cookies eaten.

(My implementation is very whacky, I made sure there is always a cookie seller ar $1$, so that I can handle the edge case better, but that obviously did not turn out to be useful, but worse. Just use it as a reference)
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}

void solve(){
    ll n, m, d;
    cin >> n >> m >> d;

    vi a = {1};

    for(int i{}; i < m; i++){ 
        int x;
        cin >> x;
        if (x == 1) continue;
        a.pb(x);
    }

    bool changed = m != sz(a);
    m = sz(a);

    vll pf(m);
    vll sf(m);
    pf[0] = 1;
    sf[m-1] = 1+ (n-a[m-1])/d;

    for(int i{1}; i < m; i++){
        pf[i] = pf[i-1] + 1 + (a[i]-a[i-1]-1) / d;
    }
    
    for(int i{m-2}; i >= 0; i--){
        sf[i] = sf[i+1] + 1 + (a[i+1]-a[i]-1) / d;
    }

    int cnt = 1;
    ll res = pf[m-2] + (n - a[m-2]) / d;

    for(int i{}; i < m-2; i++){
        if (res == pf[i] + sf[i+2] + (a[i+2]-a[i]-1) / d){
            cnt++;
        }
        if (res > pf[i] + sf[i+2] + (a[i+2]-a[i]-1) / d) cnt = 1;
        res = min(res, pf[i] + sf[i+2] + (a[i+2]-a[i]-1) / d) ;
    }

    if (!changed){
        cnt += sf[0] == res;
    }
    cout << res << ' ' << cnt << '\n';
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