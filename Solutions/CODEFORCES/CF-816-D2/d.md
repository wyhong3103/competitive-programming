Upsolved with the help of editorial.
```

I failed at the part where we have to figure out the minimal bits. I was trying something like if two of the bits are both probable to be 1, then we should late the later one be 1 and the earlier one be 0, which is in fact wrong, I can sense it, but I didn't have a good enough counter example. 

Anyways, here's the explanation


Notice that we can treat this problem bitwise independently, the reason is that bitwise operation is bitwise independent as well, plus there's only 30 bits, so it's fine to do that.

Next observation is that, the only thing we can guarantee is when both the number has 0 on the bits, or when i == j, and i | j has bit 1. Otherwise, one of the number has to be 1 or the other, or both. With this, we can set all the guaranteed bits to it's corresponding bits.

Now comes the tricky part, to determine the minimal bit, i've overcomplicated this part that's why i couldn't do it. It is in fact very simple, we simply need to bruteforce it and check it. Starting from the smallest number, check if it fulfill the condition if we set it as 0. If yes, then we can set it to 0. Initially, every number has 1. And we do this gradually until we hit the end. And this (very simple way of trial and error) gives us the answer.

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
    int n, q;
    cin >> n >> q;
    vector<vi> res(n, vi (32));

    for(auto& i :res){
        fill(all(i), 1);
    }
    
    vector<vector<pll>> adj(n);
    for(int i{}; i < q; i++){
        ll l, r, x;
        cin >> l >> r >> x;
        l--;r--;
        adj[l].pb({r,x});
        adj[r].pb({l,x});

        for(int i{}; i < 30; i++){
            if (!(x & (1 << i))){
                res[l][i] = 0;
                res[r][i] = 0;
            }
        }
    }
        
        
    for(int i{}; i < 30; i++){
        for(int j{}; j < n; j++){
            bool ok = 1;
            for(auto& k : adj[j]){
                if (k.fir == j && ((k.sec >>i) & 1)) ok = 0;
                else if (res[k.fir][i] != ((k.sec >> i) & 1)) ok = 0;
            }
            if (ok) res[j][i] = 0;
        }
    }

    

    for(auto& i :res){
        ll total = 0;
        for(int j{}; j < 30; j++){
            if (i[j]) total += 1 << j;
        }
        cout << total << ' ';
    }

    
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