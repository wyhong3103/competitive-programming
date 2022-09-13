```

There's probably a better way in doing this....

Notice that it doesn't matter how long the string s is. we only need at max 18 substrings of length w from it, that is every two v(x) % 9 from 0 to 8

Because there might be times when we need two same number.

After computing that, for each query, we only need to find the multiplier and then bruteforce every pair from 0 to 8, if it yields the correct answer we will take the minimal one.

But here comes the problem, how do we compute v(l:r) in a non-linear time?? We might be able to compute all the substring of length w in O(N). Simple arithmetic will do. Everytime we iterate through the next number, we subtract the biggest number , add the new number. (Sliding window)

But that isn't the case for [l:r] as the lenght varies.

The solution to this is by using prefix(suffix actually) sum and some number theories.


Starting from the suffix, we compute the modulo 9 residue for each suffix, for example,

1003004

4 - 4 % 9 = 4
04 - 4 % 9 = 4
004 - 4 % 9 = 4
3004 - 3004 % 9 = 7
03004 - 3004 % 9 = 7
003004 - 3004 % 9 = 7
1003004 - 1003004 % 9 = 8

Of course the number could get arbitarily large. So we can modulo it each time we iterate through it.

Say we want to find 100300, (1:6)

we can simply suffix[1]-suffix[7] = 1003000, notice we have an extra 0 over here. So, we can divide it by 10^x (x = 1 in this case)!

But that's not it, we need the modulo inverse of it, so we cannot simply divide it by 10^x as we've been dealing with modulo arithmetic the entire time.

And good thing is 10 and 9 are coprime, so the inverse of 10^x is simply (10^x)^phi(9)-1

phi(9)-1 is 5, 

prime factorization of 9 = 3^2

phi(9) = 3^(2-1) * (3-1) = 6

phi(9)-1 = 6-1 = 5

And that's it, with this we can compute the modulo inverse in log of n.
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
 
ll modpow(ll n, ll p){
    if (!p) return 1;
    ll sq = modpow(n,p/2);
    sq = (sq*sq)%9;
    if (p%2) return (sq * n) % 9;
    else return sq;
}
 
void solve(){
    string s;
    cin >> s;
 
    int w, m;
    cin >> w >> m;
 
 
    vector<pi> a(9, {-1,-1});
    
    int n = sz(s);
    int cur = 0;
    int p = 1;
 
    vi sm(sz(s));
    for(int i{sz(s)-1}; i >= 0; i--){
        cur += (int)(s[i]-'0') * p;
        cur %= 9;
        sm[i] = cur;
        if (i){
            p *= 10;
            p %= 9;
        }
    }
 
    cur =sm[sz(s)-w];
    a[cur].fir = sz(s)-w;
    for(int i{sz(s)-2}; i >= w-1; i--){
        cur = (((sm[i-w+1]-sm[i+1]+9)%9)*modpow(modpow(10,w-1),5)) % 9;

        //Let cur.fir goes to cur.sec, and let the new value be on top. this is always optimal, because i-w+1 is only getting smaller
        a[cur].sec = a[cur].fir;
        a[cur].fir = i-w+1;
    }
 
 
 
 	//Unnecessary memoization
    vector<vector<pi>> resa(10, vector<pi>(10, {-2,-2}));
    while (m--){
        int l, r, k;
        cin >> l >> r >> k;
        l--;r--;
 
        int mul = (((sm[l]-(r == sz(s)-1 ? 0 : sm[r+1])+9)%9)*modpow(modpow(10,r-l),5)) % 9;
 
        if (resa[mul][k].fir == -2){
            pi& res = resa[mul][k];
            res = {INT_MAX,INT_MAX};
 
            for(int i{}; i < 9; i++){
                if (a[i].fir == -1) continue;
                for(int j{}; j < 9; j++){
                    if (i == j && a[j].sec == -1) continue;
                    else if (a[j].fir == -1) continue;
                    if (((i * mul) + j) % 9 == k) {
                        pi temp = {a[i].fir,(i == j ? a[i].sec : a[j].fir)};
                        res = min(temp, res);
                    }
                }
            }
 
            if (res.fir == INT_MAX){
                res = {-1,-1};
            }else{
                res = {res.fir+1, res.sec+1};
            }
            cout << res.fir << ' ' << res.sec << '\n';
        }else cout << resa[mul][k].fir << ' ' << resa[mul][k].sec << '\n';
    }
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