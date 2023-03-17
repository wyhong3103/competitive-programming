```

For min,

we only need to try our best to make as many '11' to be a room as possible using a room of 2. If we run out of room, or run out of '11', we just need to count the remaining 1s. '10' or '01' is the same as '1' and '0', so it doesn't really matter how we do it.

For max,

We want as many '00'/'01'/'10' to be counted as a pair as possible.

Lemma : It's always better to have as many as possible of the above selected at a prefix, i.e, we can greedily pick any of the above at every i that is unselected.

Proof : If we can get x pairs of the above that ends at i, we won't get more if we are to not take some in the middle, we will show this by some example. Imagine if we have 010, we take 01 first, is just as optimal as we take 10 first, and by taking the earlier one makes sure we have more space for the remaining pairs. We can use the same reasoning for every pair.

(we're just trying to waste as many as possible)

If we ran out of the pairs, we will then have to take '11' pair.

At the end,just choose every 1.

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
    int n, m;
    cin >> n >> m;
 
    vector<string> a(n);
    for(auto& i : a) cin >> i;
 
    int mn = 0, mx = 0;
 
    for(int i{}; i < n; i++){
        //min
        vi used(m);
        int cur = 0;
        int cnt = m/4;
        while (cur < m-1 && cnt){
            if (a[i].substr(cur,2) == "11"){
                used[cur] = 1;        
                used[cur+1] = 1;
                cnt--;
                cur += 2;
                mn++;
            }else cur++;
        }
 
        for(int j{}; j <m; j++){
            mn += !used[j] && a[i][j] == '1';
            used[j] = 0;
        }
 
        //max
        cur = 0;
        cnt = m/4;
        while (cur < m-1 && cnt){
            if (a[i].substr(cur,2) == "10" || a[i].substr(cur, 2) == "01" || a[i].substr(cur, 2) == "00"){
                used[cur] = 1;        
                used[cur+1] = 1;
                cnt--;
                if (a[i].substr(cur, 2) != "00") mx++;
                cur += 2;
            }else cur++;
        }
 
        cur = 0;
        while (cur < m-1 && cnt){
            if (!used[cur] && !used[cur+1] && a[i].substr(cur,2) == "11"){
                used[cur] = 1;        
                used[cur+1] = 1;
                cnt--;
                cur += 2;
                mx++;
            }else cur++;
        }
 
        for(int j{}; j <m; j++){
            mx += !used[j] && a[i][j] == '1';
        }
    } 
 
    cout << mn << ' ' << mx << '\n';
 
    
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