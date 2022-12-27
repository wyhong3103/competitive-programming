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

    void build(string& s){
        N = sz(s);
        pow.resize(N);
        hash.resize(N);

        gen_pow();
        gen_hash(s);
    }
    
    ll getHash(int l, int r){
        ll res = hash[r] - mod_mul((!l ? 0 : hash[l-1]), pow[r-l+1]) % M;
        res = ((res % M) + M) % M;
        return res;
    }
};


bool isEqual(vi& cnt, vi& cur){
    for(int i{}; i < 26; i++){
        if (cnt[i] != cur[i]) return false;
    }
    return true;
}

void solve(){
    string a, b;
    cin >> a >> b;

    if (sz(a) > sz(b)){
        cout << 0;
        return;
    }

    vi cnt(26);
    for(auto& i : a){
        cnt[i-'a']++;
    }

    PolyHash hashing;

    hashing.build(b);

    vi cur(26);

    for(int i{}; i < sz(a); i++){
        cur[b[i]-'a']++;
    }

    set<ll> res;
    if (isEqual(cnt, cur)){
        res.insert(hashing.getHash(0, sz(a)-1));
    }

    for(int i{sz(a)}; i < sz(b); i++){
        cur[b[i-sz(a)]-'a']--;
        cur[b[i]-'a']++;
        if (isEqual(cnt, cur)){
            res.insert(hashing.getHash(i-sz(a)+1, i));
        }
    }

    cout << sz(res);
    
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