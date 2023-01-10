```

Prime factorize every number, visit every prime factor once. DO BFS

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

 
ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}
bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
            s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {   // ^ count trailing zeroes
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}
ull pollard(ull n) {
    auto f = [n](ull x) { return modmul(x, x, n) + 1; };
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    sort(all(l));
    return l;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<ll,vi, custom_hash> edge;
unordered_set<int> vis;

void solve(){
    int n;
    cin >> n;
    
    vi a(n);
    for(auto& i :a) cin >> i;

    vector<vector<ull>> pf(n);

    for(int i{}; i < n; i++){
        pf[i] = factor(a[i]);
        for(auto& j : pf[i]){
            edge[j].pb(i);
        }
    }

    
    int s, t;
    cin >> s >> t;
    s--;t--;

    if (s == t){
        cout << 1 << '\n';
        cout << s+1;
        return;
    }

    vi prev(n+1, -1);
    vi visited(n+1);
    visited[s] = 1;
    queue<int> q;
    q.push(s);
    
    while (!q.empty()){
        int cur = q.front(); q.pop();
        
        if (cur == t) break;

        for(auto& i : pf[cur]){
            if (vis.count(i)) continue;
            for(auto& j : edge[i]){
                if (j == cur) continue;
                if (!visited[j]){
                    visited[j] = 1;
                    prev[j] = cur;
                    q.push(j);
                }
            }
            vis.insert(i);
        }
    }

    if (prev[t] == -1) {
        cout << -1;
        return;
    }

    vi res;
    int cur = t;
    while(prev[cur] != -1){
        res.pb(cur);
        cur = prev[cur];
    }
    res.pb(s);

    cout << sz(res) << '\n';
    reverse(all(res));
    for(auto& i :res) cout << i+1 << ' ';


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