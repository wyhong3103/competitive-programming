```cpp
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

/*

PolyHash hashing;

hashing.build(s);

*/

```