```

The idea is try to solve,

-1, -1, -1, ..., -1

first,

let's try to solve 2^3,

if you are to view it as a tree that has 3+1 levels, at the bottom-most level, 5, 6, 7, 8 need to end there, at the 3rd level, 3, 4, need to go, 2nd level, 2 need to go, finally 1 will win the game

Not hard to see that, at the bottom most level,

we can basically permute 5,6,7,8 at each of the pairs, if you are view them pair by pair, s.t

none of them forms a pair, and they either be at the first position of the pair or the second

total way to arrange that is

2^4 * 4!

The idea is, each element can either be the first or second in the pair, so 2^4, and 4! because we can switch between them.

Now we have determined the number of ways to arrange 5,6,7,8

Let's move on to the next level,

at this level, we can do the same thing for 3,4, we can then multiply the value by the previous result, this is equivalent to arranging them in the seed, since for each way, there is exactly one way to place them s.t they will arranged in such way (ignoring other elements) 

We can do the same thing for each level!

Now let's introduce the fixed element,

With fixed element, the only thing that changes is that

we need to validate whether the fix position will fulfill the condition, and modify the number of ways we can arrange.

3
-1 -1 -1 -1 2 -1 -1 -1

Let's look at this particular example,

At first level, now instead of 2^4 * 4!,

we have 2^3 * 4!

3 pairs we can switch between, (2 is fixed in the third pair, so we cannot switch between), and we can do permutation among the elements

To generalize this,

For each level that has 2^x elements, let cnt1 = number of pairs that are fixed (that has >= 1 fixed elements), cnt2 = number of pairs that has the element that was supposed to go at this level

res *=  2^((2^(x-2))-cnt1) * fact[2^(x-2)-cnt2]

Then, we can place the elements to a new array for the next level,

if the current pair has -1, -1, just promote -1

if the current pair has -1, x 
	if x is the one that has to go, we promote -1
	else we promote x

if the current pair has x, y
	promote the one that doesn't have to go at this level


```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
#define int long long int
 
 
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
 
/*
 
the goal is to try not to let certain team match up early in the tournament
 
team 1 will always win regardless of the seed
 
 
for 2^x, if all is -1
 
ans is 
 
for all x from n-1 to 0
 
sm += 2^(x) * (x!)
 
make sure the fixed guy land at its own position
 
if fixed guy is in the correct position, let number of fixed guy at that level be y
 
sm += 2^(x-y) * (x-y)!
 
*/
 
const int MOD =  998244353;
const int MX = 1 << 20;
ll fact[MX];
 
void gen_fact(){
    fact[0] = 1;
    fact[1] = 1;
    for(ll i{2}; i < MX; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
}
 
ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) %MOD;
    return (p % 2 ? n * sq : sq) %MOD;
}
 
//between
bool bet(int f, int t, int val){
    return (val >= f && val <= t);
}
 
void solve(){
    int n;
    cin >> n;
    
    gen_fact();
 
    //team ai has seed i
    vi a(1 << n);
    for(auto& i : a) cin >> i;
 
 
    bool ok = 1;
    ll res = 1;
    for(int i{n-1}; i >= 0; i--){
        vi temp(1 << i, -1);
        ll cnt1 = 0;
        ll cnt2 = 0;
        for(int j{}; j < (1 << (i+1)); j+=2){
            //make sure not at the same level
            ok &= !(bet((1 << i) + 1, 1 << (i+1), a[j]) && bet((1 << i)+1, 1 << (i+1), a[j+1]));
            ok &= !(a[j] != -1 && a[j+1] != -1 && !bet((1 << i) + 1, 1 << (i+1), a[j]) && !bet((1 << i)+1, 1 << (i+1), a[j+1]));
            if (!ok){
                cout << 0 << '\n';
                return;
            }
            cnt1 += a[j] != -1 || a[j+1] != -1;
            cnt2 += bet((1 << i)+1, 1 << (i+1), a[j]) || bet((1 << i)+1, 1 << (i+1), a[j+1]);
 
            if ((a[j] == -1 && !bet((1<<i)+1, 1<<(i+1), a[j+1])) || bet((1<<i)+1, 1 << (i+1), a[j])){
                temp[j/2] = a[j+1];
            }else{
                temp[j/2] = a[j];
            }
        }
 
 
        res = (res * ((modpow(2, (1LL<<i)-cnt1) * fact[(1LL<<i)-cnt2]) % MOD)) % MOD;
        /*
        cout << cnt1 << ' ' << cnt2 << '\n';
        cout << modpow(2, (1<<i)-cnt1) << ' ' << fact[(1<<i)-cnt2] <<'\n';
        cout << res << '\n';*/
        swap(temp, a);
    }
 
    cout << res << '\n';
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
```