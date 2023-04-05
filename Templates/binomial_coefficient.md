```cpp

const int MX = ;

ll C[MX][MX];
//generating a pascal's triangle

void build_pascal(){
    C[0][0] = 1;
    for(int i{}; i < MX; i++){
        C[i][0] = 1; 
        for(int j{1}; j < MX-1; j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
        C[i][i] = 1;
    }
}
```
```cpp
ll ncr(ll n, ll r){
    ll nom = 1;
    for(int i{n-r+1}; i <= n; i++) nom *= i;

    ll denom = 1;
    for(int i{1}; i <= r; i++){
        if (nom % i == 0) nom /= i;
        else denom *= i;
    }
    return nom / denom;
}
```
```cpp
const int MOD = ;
const int MX = ;

ll fact[MX];

ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}

void gen_fact(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i{2}; i < MX; i++){
        fact[i] = (fact[i-1] * i ) %MOD;
    }
}

ll ncr(ll n, ll r){
    ll num = (fact[n] * modpow(fact[n-r], MOD-2)) % MOD;;
    ll denom = fact[r];
    return (num * modpow(denom, MOD-2)) % MOD;
}
```