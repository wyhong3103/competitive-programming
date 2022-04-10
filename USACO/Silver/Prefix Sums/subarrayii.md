I had it in the first half, then got led astray, and solved it 30 minutes later. The problem is quite straight foward, only the algorithm is tricky.
<br>
Explanation:
- First off, it's impossible to do every combinations of a and b, to calculate the sum of subarray. So, very obvious, we need hash map here.
- Just like those really simple hash map problem, say you got x + y = z, in order to find such a pair, we get x , and subtract by z, and use hash map to detect the presence of y.
- Applying in here is quite tricky. So first off, we need to talk about finind the value.
```
5 7
2 -1 3 5 -2

Let's say we find want to find sum of subarray with 7

Prefix array :
2 1 4 9 7

In order to find the sum, we can iterate through the array

First, we got 2

In order to get 7, we need 9 - 2, and we got 9 in our array, note that we only consider the element after i-th, this is the only way we could find subarray, or else it will violate the rule.

2 1 4 9

i j j j

i is the element, we at, j is the subarray

Then not until we iterate through the last element,there's no subarray of 7, until the last element itself.

So the answer will be 2.
```
- So, some key points on implementation is, we need to shadow the elemnts before i, we need to consider i-th itself, we need to consider how many x+i element there is, consider an array of 0 0 0 0 0, and we want to get the sum of 0, we can basically form 0 with any other zero after us.

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){ 
    int n, x;
    cin >> n >> x;
    
    vi a(n);
    for(auto& i : a) cin >> i;
 
 	//Hash map
    map<ll, int> m;
    vector<ll> prf(n);
    prf[0] = a[0];
    m[prf[0]] = 1;
    for(int i{1}; i < n; i++){
        prf[i] = a[i] + prf[i-1];
        if (!m.count(prf[0])){
            m[prf[i]] = 0;
        }   
        m[prf[i]]++;
    }

    ll ans = 0;
    for(int i{}; i < n; i++){
        if (prf[i] == x){
            ans++;
        }
        //shadow the element
        m[prf[i]]--;
        if (m.count((prf[i] + x))) ans += m[prf[i]+x];
    }

    cout << ans;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```