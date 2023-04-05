```

Basically notice that for number i, every palindrome it involves in, its opposite character have the same parity and they are all 1 number apart!

SO the idea is we could store every number index in a 2d array.

And then for every number in the array, ai, we check how many ai is between its first opposite number and the last opposite number. And then simply subtract the total of opposites by this number, is how many time we need to replace it with new number.

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
using ull = unsigned long long;
const double EPS = (1e-6);
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n, k;
    cin >> n >> k;
 
    vi a(n);
    for(auto& i : a) cin >> i;
 
    vector<vi> even(2e5 + 5);
    vector<vi> odd(2e5 + 5);
 
    for(int i{}; i < n; i++){
        if (i % 2) odd[a[i]].pb(i);
        else even[a[i]].pb(i);
    }
 
    ll total = 0;
    //find range
    for(int i{}; i < n; i++){
        //how many position can i be in, the left, except middle
        
        int from = i + ((k+1)/2 - min(k/2, i+1)) * 2;
        int to = i + ((k+1)/2 - max(1, i-(n-k)+1)) * 2;
        if (from > to) continue;
        if (i % 2){
            total += ((to-from)/2 + 1) - (int)(upper_bound(all(odd[a[i]]), to) - lower_bound(all(odd[a[i]]), from));
        }else{
            total += ((to-from)/2 + 1) - (int)(upper_bound(all(even[a[i]]), to) - lower_bound(all(even[a[i]]), from));
        }
    }
    cout << total;
    
 
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