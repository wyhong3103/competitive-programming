```


product(a[i]....a[n]) % 2^n == 0

if and only if there exist an integer x such that

product(a[i]...a[n]) = 2 * 2 * 2 * 2 * 2..... * 2 * x


Notice that we could move 2 to the other side, so that it became


a[i]/2 * a[i+1]/2 ..... a[n]/2 = x

One operation, we could multiply i, i+1, i+2 ... n, to one of the number (just multiply it by the product basically)

notice that we want 

a[i]/2 * a[i+1]/2 ..... a[n]/2 

to be an integer

even number can easily get rid of the /2, 

1/2 * 4/2 -> 1/2 * 2 -> 1

If a number is even even after dividing, we can still use it to help other term

So basically, before using the operation

If number of odd <= number of times we can divide a[i] by 2 for all a[i] that is even (this is not log!)

then number of operation = 0,

Else we can greedily use the number from the most divisible by 2 (the number of time it can be divided by 2), to least.

Use the number until we outscore the number of odd.

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
 
void solve(){
    int n;
    cin >> n;
 
    vll a(n);
    for(auto& i : a) cin >> i;
 
    int cnt = 0;
    for(auto& i : a){
        cnt += i % 2;
        if (i % 2 == 0) i /= 2;
        while (i % 2 == 0){
            i /= 2;
            cnt--;
        }
    }
 
    map<ll,int> freq;
    for(int i{n}; i >= 1; i--){
        if (i % 2 == 0) {
            int total = 0;
            ll temp = i;
            while (temp % 2 == 0){
                temp /= 2;
                total++;
            }
            freq[total]++;
        } 
    }
 
    int res = 0;
    if (sz(freq)){
        bool canBreak = 0;
        auto it = --freq.end();
        while (!canBreak){
            if (it == freq.begin()){
                canBreak = 1;
            }
            while (it->sec && cnt > 0){
                cnt -= it->fir;
                it->sec--;
                res++;
            }
            if (cnt <= 0){
                break;
            }
            it--;
        }
    }
 
    if (cnt > 0){
        cout << -1 << '\n';
    }else cout << res << '\n';
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