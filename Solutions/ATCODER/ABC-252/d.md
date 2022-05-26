A combinatorics problem, (my weakness). Spent quite a number of times to figure out the formula. Anyways, the formula is 
```
initially, let ans = nC3

For every element that has a frequency >= 2

We have to deduct the below

((frequency)C2 * (n - frequency)) + (frequency)C3

(frequency)C2 * (frequency - 2), is the number of triplets that has 2 similar element with another different element

frequencyC3, is simply the number of triples that has 3 similar elements


Combinatorics, it's a little confusing ik, takes time to master it, but that's the idea for this problem
```
```cpp
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
const int MAX = 2e5;
 
ll ncr(int n, int r){
    if (n < r) return 0;
    int num = (n-r)+1;
    ll res = 1;
    for(ll i{n}; i >= num; i--) res = (res * i);
    for(int i{r}; i >= 1; i--) res /= i;
    return res;
}
 
void solve(){
    int n;
    cin >> n;
 
    vi a(n);
    for(auto& i : a) cin>> i;
 
    map<int,int> freq;
    for(auto& i : a){
        if (!freq.count(i)) freq[i] = 0;
        freq[i]++;
    }
 
    ll cur = ncr(n, 3);
    for(auto& i : freq){
        if (i.sec >= 2){
            cur -= ncr(i.sec, 2) * (n-i.sec);
            cur -= ncr(i.sec, 3);
        }
    }
 
    cout << cur;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```