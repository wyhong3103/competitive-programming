```

In order for the sequence to be good, for every number in that sequence, let it be p, XOR of number < p in that sequence should be 0. 

We are to form the good sequence, and make sure the sum of every element is equal to m

One obvious case where it's impossible is when n > m. Because a[i] >= 1, so n must <= m

Otherwise, we can just do this one-size fit all solution.


Set every number to 1, but the last number


1 1 1 1 1 .... m-(n-1)

Now this would work when n-1 is an even number (because if its odd, XOR will be 1).

If it's an odd number and m-(n-1) is an odd number as well.

1 1 1 3

We can easily split the last number in half

1 1 2 2

But what if it's an even number at the end?

1 1 1 2

IMPOSSIBLE.
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
    int n, m;
    cin >> n >> m;
    
    if (m < n){
        cout << "NO" << '\n';
        return;
    }
 
    vi a(n, 1);
    a[n-1] = m-(n-1);
    if ((n-1) % 2){
        if ((m-(n-1)) % 2){
            a[n-2] = (m-(n-1)+1)/2;
            a[n-1] = (m-(n-1)+1)/2;
        }else{
            cout << "NO" << '\n';
            return;
        }
    }
 
    cout <<"YES" << '\n';
    for(auto& i : a) cout << i << ' ';
    cout << '\n';
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