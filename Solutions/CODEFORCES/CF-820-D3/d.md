```

We can create a new array of diff between x and y. (y-x).

Notice that there will be some number of people who would have a negative diff value. And people with positive value.

We only team up a team >= 2 people. 

In fact, we only need to team up 2 people, needless more than that.

Positive + Positive is always optimal.

But if we could team up with negative that's better.

Basically we could sort the diff value in non decreasing order.

And then start processing from the first positive value, and find another pair in the negative range that has value >= -(first positive value). Then pair them up together, if it doesn't exist we pair with the next positive value. (Greedy, because the next value is either going to pair up with a negative value or a positive value, so we essentially just filled it up.)
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
    int n;
    cin >> n;
 
    vi a(n);
    for(auto& i : a) cin >> i;
    vi b(n);
    for(auto& i : b) cin >> i;
 
    
    map<int,int> mp;
    for(int i{}; i < n; i++){
        mp[b[i]-a[i]]++;;
    }
 
    int cnt = 0;
    while (mp.lower_bound(0) != mp.end()){
        auto it = mp.lower_bound(0);
        auto it2 = mp.lower_bound(-(it->fir));
        if (it2->fir != it->fir){
            it2->sec--;
            it->sec--;
            if (it2->sec == 0) mp.erase(it2->fir);
            if (it->sec == 0) mp.erase(it->fir);
            cnt++;
        }else if (it->sec >= 2){
            it->sec-=2;
            if (it->sec == 0) mp.erase(it->fir);
            cnt++;
        }else if (it != --mp.end()){
            auto it3 = ++it;
            it--;
            it->sec--;
            it3->sec--;
            if (it->sec == 0) mp.erase(it->fir);
            if (it3->sec == 0) mp.erase(it3->fir);
            cnt++;
        }else mp.erase(it->fir);
    }
    cout << cnt << '\n';
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