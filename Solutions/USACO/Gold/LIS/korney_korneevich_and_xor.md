I've overcomplicated this problem in the beginning.
```
Anyway the idea is pretty simple, since a[i] <= 500, we could LIS-like dp, but our goal is not to find the longest incrasing subsequence

For each a[i], we could literally XOR a[i] with any number prior to i, and is smaller than a[i]. And it would be too dumb to iterate through all subsequence, and since there is only 512 XOR numbers available, we could do somthing faster.

For each a[i], we iterate from 0 to 512, if there exist an XOR of that number, and the holder of that number is smaller than a[i], then we do XOR on it. And we replace the new XOR holder if it's bigger than a[i].
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
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}

 
void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(auto& i : a) cin >> i;

    vector<bool> dp(513);
    vi number(513);
    fill(all(number), INT_MAX);

    dp[0] = 1;
    number[0] = 0;
    for(int i{}; i < n; i++){
        for(int j{}; j <= 512; j++){
            if (dp[j] && a[i] > number[j]){
                dp[j ^ a[i]] = 1;
                number[j ^ a[i]] = min(number[j^a[i]], a[i]);
            }
        }
    }

    set<int> res;
    for(int i{}; i <= 512; i++){
        if (dp[i]) res.insert(i);
    }

    cout << sz(res) << '\n';
    for(auto& i : res) cout << i << ' ';
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