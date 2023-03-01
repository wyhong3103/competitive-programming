```

We want the min of t_max

we can start with the smallest letter, and then use it to place both end

this is always optimal, becuase if either way we flip, we get back the same letter

but if we only have one of that letter, this is when things get a little tricky

say we have

abbcc

You might be tempted to start with

b...b

but this will result with the non optimal one, as the next letter we compare, a and c, the bigger would be c, so the string would become

bc.ab

So let's start with b...a,

notice that whenever we have such a string, we can basically start placing ... with the lexicographically minimal string, bc this will be the optimal, as we cannot flip it anymore.

Here's the trick, sometimes, we might want to sacrifice b...a to make sure we get more bs at the beginning.

Turned out when we have a single a and more than 1 bs, the only optimal situation to do b...b is when there is only b and a exist in the array. Otherwise, it's always better to sacrifice a, this is becase by sacrificing a, we can construct the lexicographically minimal.

If we are to place b..b instead, it is pretty obvious that the bs we can place after the first b will decrease, if there exist another letter that is not a and c. so it's better to just sacrifice


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
    string s;
    cin >> s;
 
    map<char,int> mp;
 
    for(auto& i : s){
        mp[i]++;
    }
 
    vector<char> a(sz(s), 'A');
    
    int n = sz(s);
 
    bool found = 0;
    for(int i{}; i < n/2; i++){
        if (mp.begin()->sec > 1){
            a[i] = mp.begin()->fir;
            a[n-(i+1)] = mp.begin()->fir;
            mp.begin()->sec -= 2;
            if (mp.begin()->sec == 0) mp.erase(mp.begin()->fir);
        }else{
            auto it = mp.begin();
            auto it2 = ++mp.begin();
            if (it2->sec > 1 && sz(mp) == 2){
                a[i] = it2->fir;
                a[n-(i+1)] = it2->fir;
                it2->sec -= 2;
            }else{
                a[i] = it2->fir;
                a[n-(i+1)] = it->fir;
                it->sec--;
                it2->sec--;
                found = 1;
            }
            if (it->sec == 0) mp.erase(it->fir);
            if (it2->sec == 0) mp.erase(it2->fir);
            if (found) break;
        }
    }
 
    if (found){
        for(int i{}; i < n; i++){
            if (a[i] == 'A'){
                a[i] = mp.begin()->fir;
                mp.begin()->sec --;
                if (mp.begin()->sec == 0) mp.erase(mp.begin()->fir);
            }
        } 
    }
    if (!found && n % 2){
        a[n/2] = mp.begin()->fir;
    }
    for(auto& i : a) cout << i;
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