```
You might be tempted to use binary search. A log n algorithm. But log 1e18 ~ 60, we can only make < 50 queries. So..., we're going to bet on probability instead.

Every time we make a query ? a b. We receive one of the length of the path from a to b. (it's a cycle, there's 2 path from a to b, left to right / right to left). There's an equal probability that we will get one of them. But one thing is ? a b, always spits the same value, but ? b a may be different. 

So the idea is to iterate from 2 to inf, let it be i

try ? 1 i and ? i 1, if they spits out diff value, then the answer is simply a + b
else we try the next i. (Because if ? 1 i and ? i 1 spits the same value, they will always spit the same value, no point trying them)

If we ever visit -1, then the answer is i-1.
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
    ll at = 2;
    ll ans = 0;
    while (true){
        cout << "? 1 " << at << '\n';
        cout.flush();
        ll a;
        cin >> a;
        if (a == -1){
            ans = at-1;
            break;
        }
 
        cout << "? " << at << " 1" << '\n';
        cout.flush();
        ll b;
        cin >> b;
        if (a != b){
            ans = a+b;
            break;
        }
        at++;
    }
    cout << "! " << ans;
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