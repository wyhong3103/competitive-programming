```


Let's try to minimize MEX, i.e, get rid the smallest number from the array

To get rid of 0, pretty simple, we can just insert a non 0 number between 0, our final array wont have a single 0

0 a 0 b 0 c 0 d 0

SO its easy to see when number of 0 <= ceil(n/2), we can always have MEX = 0

So what if its more than that?

If its more than that, we dont have to spend any of our non 0 to pad 0, so we can just leave 0 aside

a b c d 0 0 0 0

Since we're going to have 0 either way

Okay let's look at the next case where we need to get rid of 1

1 1 1 1 1 0 0 0 0

The above, would give a 1, when we sum 1 and 0 together, so this is obvious, this MEX would be 2.

With the above, it's also became obvious that we just need a non 1 non 0 to make MEX = 1, we could basically just put it between 1 and 0. Which would make the MEX = 1.

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
    int n;
    cin >> n;
 
    map<int,int> mp;
    for(int i{}; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    
    if (mp[0] <= (n+1)/2){
        cout << 0 << '\n';
    }else{
        if (sz(mp) == 2 && mp[1]){
            cout << 2 << '\n'; 
        }else cout << 1 << '\n';
    }
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