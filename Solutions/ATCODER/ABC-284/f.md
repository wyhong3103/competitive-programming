```

String Hashing problem

The idea is to search every substring of length N in string T. And we need to compare the hash value of that susbtring with the outer one. (concantenation of front and back)

Our polynomial hash stores prefix of hash value s.t last character of that prefix has power of 0.

So to combine front and back, let's first look at how front and back is going to look like

front [0:i] : s[0] * p^k + ... + s[i] * p^0

back [j : n-1] : s[j] * p^k + ... + s[n-1] * p^0

To concatenate them, we simply multiple hash value of front by p^length of j.

s[0] * p^k+x + ... + s[i] * p^k+1 + s[j] * p^k + ... + s[n-1] * p^0

Now the reverse part!

We can get the reversed hash value simply by letting end of character of a prefix be the largest power, that way it's equivalent of reversing the string with its hash value.

How do we compare them? Notice that to get the hash of reversed substring, we can just do prefix sum, and get a sum that's start with p^i, instead of 0. To compare them, we can simply multiply the concatenated hash by p^i, to match them at the same location.


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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
struct PolyHash{
    
    ll M = (1LL << 61) - 1;
    ll P = uniform_int_distribution<ll>(0, M - 1)(rng);
    int N;
    vll pow;
    vll hash;
    vll hash_rev;
 
	__int128 mul(ll a, ll b) { return (__int128) a * b; }
	ll mod_mul(ll a, ll b) { return mul(a, b) % M; }
 
    void gen_pow(){
        pow[0] = 1;
        for(int i{1}; i < N; i++){
            pow[i] = mod_mul(P, pow[i-1]);
        }
    }
    
    void gen_hash(string& s){
        hash[0] = s[0]-'a'+1;
        for(int i{1}; i < N; i++){
            hash[i] = (mod_mul(hash[i-1], P) + (s[i]-'a'+1)) % M;
        }
    }
 
    void gen_hash_rev(string& s){
        hash_rev[0] = s[0]-'a'+1;
        for(int i{1}; i < N; i++){
            hash_rev[i] = (hash_rev[i-1] + mod_mul(s[i]-'a'+1, pow[i])) % M;
        }
    }
 
    void build(string& s){
        N = sz(s);
        pow.resize(N);
        hash.resize(N);
        hash_rev.resize(N);
 
        gen_pow();
        gen_hash(s);
        gen_hash_rev(s);
    }
    
    ll getHash(int l, int r){
        ll res = hash[r] - mod_mul((!l ? 0 : hash[l-1]), pow[r-l+1]) % M;
        res = ((res % M) + M) % M;
        return res;
    }
 
    ll getHashRev(int l, int r){
        ll res = hash_rev[r] - (!l ? 0 :hash_rev[l-1]) % M;
        res = ((res % M) + M) % M;
        return res;
    }
};
 
void solve(){
    int n;
    cin >> n;
    string t;
    cin >> t;
    
    PolyHash hashing;
    hashing.build(t);
 
    for(int i{}; i <= n; i++){
        ll hash_s = hashing.getHashRev(i, i+n-1);
 
        //Front 
        ll hash_fb = hashing.mod_mul((!i ? 0 : hashing.getHash(0, i-1)), hashing.pow[(2*n-1) - (i+n) + 1]);
 
        //Back
        hash_fb = (hash_fb + (i+n-1 == 2*n-1 ? 0 : hashing.getHash(i+n, 2*n-1))) % hashing.M;
 
        hash_fb = hashing.mod_mul(hash_fb, hashing.pow[i]);
 
        if (hash_s == hash_fb){
            string res = t.substr(i, n);
            reverse(all(res));
            cout << res << '\n';
            cout << i << '\n';
            return;
        }
    }
    cout << -1;
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