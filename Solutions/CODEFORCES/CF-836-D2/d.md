```

First let's imagine having an array of 1...n

Obviously we need the sum of the entire array to be x ^ 2, x = n-1 (max - min).

When we have 1....n, the sum is essentially n*(n+1)/2, let's denote it by y.

So apparently we need x^2 - y more in order to let the sum == x^2.

We can distribute the floor((x^2-y)/n) evenly to every n element such that max-min is still the same.

But what do we do with the extra element?? that is < n

Note that no matter how we put it, it's impossible to do it.

Because if we add 1 at i, then a[i] would equal to a[i+1]!

Or if we add 1 at a[n-1], then max-min != x

Notice that at the end, we always got 1/2 extra element we need to feed to each element! And we want to avoid feeding a[0] and a[n-1], because that would disrupt x.

So right now, we want to fill the sum such that no element would be equal and a[n-1]-a[0] is x.

Notice that the maximal sum we needed to add to each element is just 2!

So the idea is fairly simple, we can just set every element as 1 + (3*i)

And then x become 3*n.

Distribute the extra elements evenly, at the end, we could just add 1/2 to all the intermediate element without having them equal to each other!

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
    ll n;
    cin >> n;
 
    if (n == 2){
        cout << 1 << ' ' << 3 << '\n';
        return;
    }
 
    vll a(n);
    for(int i{}; i < n; i++) a[i] = 1 + (3*i);
 
    ll sq = a.back()-1;
    sq *= sq;
    sq -= n + (3 * ((n)*(n-1)/2));
    for(int i{}; i < n; i++) a[i] += (sq)/n;
 
    ll remain = sq - ((sq/n)*n);
 
    for(int i{1}; i < n-1; i++){
        a[i] += remain/(n-2); 
    }
 
    remain -= (remain/(n-2)) * (n-2);  
 
    int at = 1;
    while (remain--){
        a[at++]++;
    }
 
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