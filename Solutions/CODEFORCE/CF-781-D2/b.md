The goal is to form an array of n elements with same number. We can either clone an array(for us to swap), or swap any elements from two arrays from any position.
<br>
My approach:
<br>
- Select the element with the most frequency
- Notice that ,every time we clone an array and swap it, the element we got will be doubled every time.
```
0 1 3 3 7 0

Most frequency : 0

Clone - 0 1 3 3 7 0

So now we have two array
0 1 3 3 7 0
0 1 3 3 7 0

Swap it

1 1 3 3 7 3
0 0 0 3 7 0

3 operations in total - clone 1, swap 2

1 1 3 3 7 3 (we can ignore this, since we don't need it anymore)

Clone - 0 1 3 3 7 0
0 0 0 3 7 0

Swap twice
0 0 0 0 0 0
```
- After observing, it tells us that, we don't actually deal with the array. But the number of occurences of element. Say we got 6 element, and the frequency of the most frequent element is 2, in order to make 2 to 6. We can double 2 to 4, this operation takes 1 + (number before double). + 1 because of the cloning. Then we repeat the same, but this time, note that if we take the number before double we get 8, so it's not always optimal to do that. The best way to do it, is to take 1 + min(number before double, n - number before double). n - number before double is exactly what we need.

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
 
using namespace std;
using vi = vector<int>;
using ll = long long;
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}
 
void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        map<int,int> m;
        int mx = 0;
        for(auto& i : a){
            cin >> i;
            if (!m.count(i)) m[i] = 0;
            m[i]++;
            mx = max(m[i], mx);
        }
 
        int ans = 0;
        while (mx < n){
            ans += (1 + min(n-mx, mx));
            mx *= 2;
        }
        cout << ans << '\n';
    }
}
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```