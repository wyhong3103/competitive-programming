```

Observation

We are to find the sequence that would make the array into a non-decreasing array, we do not have to minimize it!!

Let's look at what the operation does to both elements

b-o s-o -> s-o s-o
s-o b-o -> b-o b-o
b-e s-e -> s-e s-e
s-e b-e -> b-e b-e

b-o s-e -> b-o b-o
s-o b-e -> s-o s-o
b-e s-o -> b-e b-e
s-e b-o -> s-e s-e

Notice that we can always make both the element the same, so we need to come out with a strategy which we can use to make all elements equal.

notice that 

b-o s-e -> b-o b-o
s-o b-o -> b-o b-o

Imagine if we got b-o at both ends of the array, we can essentially use this operation to turn every odd and even element to the same element.

Yes that's the strategy, and that's what we would do. First we make both ends the same, then use the strategy above depends on the parity.

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
 
void setop(int f, int s, vll& a){
    if ((a[f] + a[s]) % 2) a[s] = a[f];
    else a[f] = a[s];
}
 
void solve(){
    int n;
    cin >> n;
 
    vll a(n);
    for(auto& i : a) cin >> i;
 
    vector<pi> moves;
    moves.pb({1, n});
    setop(0, n-1, a);
    
    for(int i{1}; i < n-1; i++){
        if (a[0] % 2){
            if (a[i] % 2){
                moves.pb({i+1, n});
                setop(i, n-1, a);
            }else{
                moves.pb({1, i+1});
                setop(0, i, a);
            }
        }else{
            if (a[i] % 2){
                moves.pb({1, i+1});
                setop(0, i, a);
            }else{
                moves.pb({i+1, n});
                setop(i, n-1, a);
            }
        }
    }
    if (n == 1){
        cout << 0 << '\n';
        return;
    }
    cout << sz(moves) << '\n';
    for(auto& i : moves) cout << i.fir << ' ' << i.sec << '\n';
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