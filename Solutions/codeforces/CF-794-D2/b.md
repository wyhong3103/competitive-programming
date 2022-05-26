Okay this takes a little while to prove that my solution works.
```
So firstly, number of inversion is basically the number of element that is smaller than the i-th element, that has a greater index than i

We want to the number of odd subarray be the maximum, so it's kind of greedy

It's always optimal to just split the array if we found one element that is smaller than i-th element

And then move on to the next element

For example

4 3 2 1

First we start with 4 , we immediately found 3, which is smaller than us, so we would split

4 3 | 2 1

Now we move on to 2, we ignore 3 because it has already been splitted

Then 2 1, now that's the answer
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
 
void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        for(auto& i : a) cin >> i;
 
        int res = 0;
        int i = 0;
        while (i < n-1){
            if (a[i] > a[i+1]){
                res++; 
                i += 2;
            }else i++;
        }
 
        cout << res << '\n';
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    solve();
	return 0;
}
```