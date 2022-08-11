```
Because we can only move two 1s in one direction, so we might as well just interpret any group of 1s as a single 1

Say we got 

0110

We can interpret it as 010, as simply do 3C1, and we will get the answer, this is because no matter where we move the group , 2 of the 1s always stick together

But what do we do with single 1?

Say we got 

1100110100

And let's interpret it as 

10010S00

let's denote the single 1 as 'S' , i.e swapper

Notice that whenever 1 got to S, it can actually swaps position

1S00 <=> 11100 --> 10110 <=> S010

We just swap the position, as if there is nothing there, so with this observation, we can ignore the single 1 everytime, since it only allows us to swap place, it might as well just be nothing

And the final answer is simply

(Number of 0s and groups of 1s) C (groups of 1s)

With a modular arithmetic
```
```cpp
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using pdb = pair<double,double>;
using ll = long long;
using pll = pair<ll,ll>;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MOD = 998244353;

ll modpow(int n, int p){
    if (!p) return 1;
    ll sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;

    if (p%2) return (sq * n) % MOD;
    return sq;
}


ll ncr(int n, int r){
    ll num = 1;
    for(int i{n}; i > n-r; i--){
        num = (num * i) % MOD;
    }

    ll denom = 1;
    for(int i{1}; i <= r; i++){
        denom = (denom * i) % MOD;
    }
    return  (num * modpow(denom, MOD-2)) % MOD;
}

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    //skip alone 1
    //{total number, 1s}
    pi cnt{};
    int i = 0;
    while(i < n){
        if (i < n-1 && s[i] == '1' && s[i+1] == '1'){
            cnt.fir++;
            cnt.sec++;
            i += 2;
        }else if (s[i] == '0'){
            cnt.fir++; 
            i++;
        }else i++;
    }

    cout << ((ncr(cnt.fir, cnt.sec) + MOD) % MOD) << '\n';
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