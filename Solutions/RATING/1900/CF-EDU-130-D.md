```

It's pretty obvious that we have to identify all the element group first, which element has the same character etc, because we only have 26 queries.

How do we identify the groups? Also notice that we only have 6000 queries, that hinted that each element we can only do 6 queries, which is 2^5 ~ 32, which also hinted that we might need to do binary search on the distinct letters, but how does it work?

lets say we at i, and assume that we have already identified the group of every letters from 0 to i-1

there is at most 26 distinct group,

from an index j to i-1, we can count how many distinct group there is, let the number of groups be y

let answer for the query from j to i be x

if y < x, that means character i do not fall into the group from j to i-1,
x == y, means found the distinct letter in the group

how do we limit ourself to only binary searching on 26 js? The idea is to store the last occurence of each distinct letter, because we're binary searching from the back, so the moment we saw the last (first in this sense) occurence of a distinct letter we should start counting it.

We used 5 queries to find the critical point, we use another query to truly identify the current element.

j supposedly should point to the last element (from the back), s.t j-1 is character i.

But we have some edge case, which is when j = 0, and j = i-1, so we will have to use the extra query to identify these letters

After identifying all the groups,

simply use query 1 to identify all the letters


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

bool query(int l, int r, vi& group){
    set<int> s;
    for(int i{l}; i <= r; i++){
        s.insert(group[i]);
    }

    cout << "? 2 " << l+1 << ' ' << r+2 << '\n';
    cout.flush();
    int x;
    cin >> x;

    return sz(s) == x;
}
 
void solve(){
    int n;
    cin >> n;

    int cnt = 1;
    vi last(26, -1);
    vi group(n, -1);
    group[0] = 0;
    last[0] = 0;
    for(int i{1}; i < n; i++){
        vi dist;
        for(auto& j : last){
            if (j != -1){
                dist.pb(j);
            }
        }
        sort(all(dist));

        int lo = 0, hi = sz(dist)-1;
        while (hi > lo){
            int mid = lo + (hi-lo)/2;
            if (query(dist[mid], i-1, group)){
                lo = mid+1;
            }else hi = mid;
        }

        if (lo){
            if (query(dist[lo], i-1 ,group)){
                last[group[dist[lo]]] = i;
                group[i] = group[dist[lo]];
            }else{
                last[group[dist[lo-1]]] = i;
                group[i] = group[dist[lo-1]];
            }
        }else{
            if (query(dist[lo], i-1, group)){
                last[group[dist[lo]]] = i;
                group[i] = group[dist[lo]];
            }else{
                last[cnt] = i;
                group[i] = cnt;
                cnt++;
            }
        }
    }

    vi mp(26);
    
    for(int i{}; i < 26; i++){
        if (last[i] != -1){
            cout << "? 1 " << last[i]+1 << '\n';
            cout.flush();
            char x;
            cin >> x;
            mp[i] = x;
        }
    }
    cout << "! ";
    for(auto& i : group){
        cout << (char)mp[i];
    }
    cout.flush();
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