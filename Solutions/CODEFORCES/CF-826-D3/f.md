```

Quite an interesting problem I must say, it's a little difficult and annoying :|


First of all, notice that at anywhere of the axis, we only need to know whether there exist two different color on a certain point, so one general strategy we can do is, store two different color that is at point i that has the furthest r. (l doesn't have to be i in order to be the point, it just have to pass through i)

So now, let's declare a sorted map that stores l as the key , and another map that stores c (color) as the key and r as the value!

Sort all segment according to l in increasing order.

Set mp[l][c] = max(mp[l][c], r)

Also, there exist some situation where

  Y Y Y   Z Z Z
X X X X X X X X X 

X might be part of the segment!

So we also need to check the previous l and see if there's any color that came through!

Finally, if the total segments that passed through l > 2, remove all the color, except for the further 2. (we only need 2 different color!) (It's best to only leave 2, that's better for everything, there could be cases where an L could contain all the color, which might caused n^2)

Okay now we have an almost optimal sorted map that could tell us what is the closest L with different color now!

But we're still missing something.


X X X  |  X X X  |  X X X 

Notice the above situation could happen! where all the 3 different L is storing the same color!

So one way to tackle is to iterate through all the Ls in the map, if the L has more than 2 color add it to a diff array, if the previous L has a different color than the current L's color, also add it to the diff array!

Okay now it's almost done.

To find an answer for a segment, we simply need to check the current L, if the current L has more than 2 colors, the answer is simply 0.

Or else we're going to find the closest different color on the left and on the right! And be careful with the implementation! It is a little implementation heavy.

Basically, 

To find the previous closest different seg, we simply need to find the segment in diff array that we belong, find the L. And then use the sorted map to find the key before that L. (it is definitely a different color, because of the fact that L is a changing point)

To find the next closest different seg, simply find the next diff point! And that is the L that are closest to our R. so simply L - R , sometime the current segment might intersect with the segment on L you dk that, so you could do max(L-R, 0). 

And the answer is the minimum of previous and next.
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

struct Segment{
    ll l, r, c, id;
    bool operator<(const Segment& y){
        return y.l > l;
    }
};

void solve(){
    int n;
    cin >> n;

    vector<Segment> a(n);
    for(int i{}; i < n; i++){
        cin >> a[i].l >> a[i].r >> a[i].c;
        a[i].id = i;
    }
    
    map<ll, map<int,ll>> ox;

    sort(all(a));
    for(auto& i : a) {
        ox[i.l][i.c] = max(ox[i.l][i.c], i.r);
        if (ox.lower_bound(i.l) != ox.begin()){
            auto prev = --ox.lower_bound(i.l);
            for(auto& j : prev->sec){
                if (j.sec >= i.l){
                    ox[i.l][j.fir] = max(j.sec, ox[i.l][j.fir]);
                }
            }
        }
        set<pll, greater<pll>> bst;
        if (sz(ox[i.l]) > 2){
            for(auto j : ox[i.l]){
                bst.insert({j.sec, j.fir});
            }
        }
        int cnt = 0;
        for(auto& j : bst){
            if (cnt >= 2) ox[i.l].erase(j.sec);
            cnt++;
        }
    }
    
    set<ll> diff;
    for(auto& i : ox){
        if (i.fir == ox.begin()->fir) diff.insert(i.fir);
        if (sz(i.sec) >= 2) diff.insert(i.fir);
        else{
            auto prev = --ox.lower_bound(i.fir);
            if (sz(prev->sec) >= 2){
                diff.insert(i.fir);
            }if (sz(prev->sec) == 1 && prev->sec.begin()->fir != i.sec.begin()->fir){
                diff.insert(i.fir);
            }
        }
    }
    
    vll res(n, LONG_LONG_MAX);
    for(int i{}; i < n; i++){
        auto at = --ox.upper_bound(a[i].l);
        if (sz(at->sec) >= 2) {
            res[a[i].id] = 0;
        }else{
            ll mn = LONG_LONG_MAX;
            //prev 
            auto prev = --diff.upper_bound(a[i].l);
            if (prev != diff.begin()){
                auto prev1 =  (--ox.lower_bound(*prev))->fir;
                for(auto& j : ox[prev1]){
                    if (j.fir != a[i].c) mn = min(mn, a[i].l - j.sec);
                }
            }
            //next
            auto nxt = diff.upper_bound(a[i].l);
            if (nxt != diff.end()){
                mn = min(mn, max((*nxt) - a[i].r, 0LL));
            }
            res[a[i].id] = min(res[a[i].id], mn);
        }
    }
    for(auto& i : res) cout << i << ' ';
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