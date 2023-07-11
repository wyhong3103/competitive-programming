First it's obvious that none of the adjacent element can be the same, beacause in $1 \text{ x } n$ they will become bad.

Right now, let's look at the first character which is at $(1, 1)$, how many element could be adjacent of it? 

It's not hard to see that potential adjacent character of the first element is simply the elements that has a distance $x$ from it such that $x$ is a factor of $n$.

The same thing applies to every other character.

So how do we construct our string fro this? We can greedily do that.

Starting from the first character, we let the first character to always be $a$, and then for every index $i$ such that $i$ is a sum of current index and a factor, we ban our current letter on that index, so that the letter at the index can never be the same as the current letter. Repeat the operation for every index, the letter that is going to be used on the new index is the first letter in the alphabetical order that is not banned.

Not hard to see why this greedy will always work (if it is always possible to construct under such constraint).

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void setio(string s){
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
 
void solve(){
    int n;
    cin >> n;
 
 
    int temp = n;
    map<int,int> freq;
    for(int i{2}; i * i <= temp; i++){
        while (temp % i == 0){
            temp /= i;
            freq[i]++;
        }
    }
 
    if (temp > 1) freq[temp]++;
 
    vi factors = {1};
    for(auto& i : freq){
        int s = sz(factors);
        ll cur = i.fir;
        while (i.sec--){
            for(int j{}; j < s; j++){
                factors.pb(factors[j]*cur);
            }
            cur *= i.fir;
        }
    }
 
    sort(all(factors));
    
    vi a(n);
    vector<vi> ban(n, vi(26));
 
    for(int i{}; i < n; i++){
        for(int j{}; j < 26; j++){
            if (!ban[i][j]){
                a[i] = j;
                break;
            }
        }    
        for(auto& j : factors){
            if (i + j < n) {
                ban[i+j][a[i]] = 1;
            }else break;
        }
    }
 
    for(auto& i : a){
        cout << (char)('a'+i);
    }
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