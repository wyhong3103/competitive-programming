```

Problem statement is a little misleading.

Basically,

We initially have a huge rectangle of size h * w, we can cut this rectangle into two, s.t both have positive area, and put another one aside, the one that been put aside, cannot be cut anymore! we will repeat this process N times. Find the possible original rectangles given the size of every rectangles.


Observation

1. One of the piece that has the longest width / height will be the actual length/width of the original rectangle, because the first cut of the rectangle, will leave one half of the rectangle (either keep width or length).

How to construct a solution from this?

WLOG, let's just focus on the rectangle with the longest width, so we will first just assume that it is the width of the rectangle, so every rectangle that has the same width will be added first. And then the height of them will also be summed.

So currently we have a rectangle of size h*w, s.t h = sum(rect[i].h), and w = width of the rectangles

When this occur, it is basically equivalent to doing horizontal cut first on the original rectangle.

At one point we will start cutting vertically, and the first rectangle that has been vertical cut, determine the final height and width of our rectangle. It is because of the same reason why we could determine the width of our rectangle. How to find the first vertical cut? Notice that at this point, every rectangles left will not have the same width as the max, so we will look at the rectangle with the most height, let it be hv, so if this rectangle is valid, the final size of our rectangle will be (h+hv)*w.

How do we know if its possible to construct the rectangle of that size?

Well once, we have determined our final rectangular size, we know the area of the remaining size that are yet to be filled, so we can simulate placing blocks of rectangle into it, we will select the one that has width = remaining area width and subtract the height it has to our remaining area, same goes to the one with same height.

At the end, the final remaning area should be zero.

Claim : there will be at most 2 rectangles that fit

Proof:

there will be one block with the most heght, one with the most width

worst case sceanrio is they both fit the rectangle

so only two possible rectangles can exist

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
    vector<pi> a(n);
    for(auto& i : a) cin >> i.fir >> i.sec;

    //construct this rectangle as if longest height is the base block
    //we need first 2 block to determine height and width, and then just try to match the height and width with the remaining block

    set<pi,greater<pi>> r, c;
    for(int i{}; i < n; i++){
        r.insert({a[i].fir, i});
        c.insert({a[i].sec, i});
    }


    set<pll> res;
    
    {
        //fixed row
        set<pi, greater<pi>> rt = r, ct = c;
        

        //find consecutive blocks first
        ll mx = rt.begin()->fir;
        pll rect {mx, 0};
        while(sz(rt) && rt.begin()->fir == mx){
            rect.sec += a[rt.begin()->sec].sec;
            ct.erase({a[rt.begin()->sec].sec,rt.begin()->sec});
            rt.erase(rt.begin());
        }
    
        if (!sz(ct)){
            res.insert(rect);
        }else{
        	//find the first block that has different cut
            bool ok = 1;
            //determine the final size
            rect.sec += ct.begin()->fir;   
            pll temp = {rect.fir, ct.begin()->fir};
            while (sz(rt)){
                if (rt.begin()->fir == temp.fir){
                    temp.sec -= a[rt.begin()->sec].sec;
                    ct.erase({a[rt.begin()->sec].sec,rt.begin()->sec});
                    rt.erase(rt.begin());
                }else if (ct.begin()->fir == temp.sec){
                    temp.fir -= a[ct.begin()->sec].fir;
                    rt.erase({a[ct.begin()->sec].fir ,ct.begin()->sec});
                    ct.erase(ct.begin());
                }else{
                    ok = 0;
                    break;
                }
            }

            ok &= !sz(rt) && (temp.fir == 0 || temp.sec == 0);
            if (ok) {
                res.insert(rect);
            }
        }
    }


    {
        //fixed col
        set<pi, greater<pi>> rt = r, ct = c;

        ll mx = ct.begin()->fir;
        pll rect {0, mx};
        while(sz(ct) && ct.begin()->fir == mx){
            rect.fir += a[ct.begin()->sec].fir;
            rt.erase({a[ct.begin()->sec].fir, ct.begin()->sec});
            ct.erase(ct.begin());
        }
    
        if (!sz(ct)){
            res.insert(rect);
        }else{
            bool ok = 1;
            rect.fir += rt.begin()->fir;   
            pll temp = {rt.begin()->fir, rect.sec};
            while (sz(rt)){
                if (rt.begin()->fir == temp.fir){
                    temp.sec -= a[rt.begin()->sec].sec;
                    ct.erase({a[rt.begin()->sec].sec,rt.begin()->sec});
                    rt.erase(rt.begin());
                }else if (ct.begin()->fir == temp.sec){
                    temp.fir -= a[ct.begin()->sec].fir;
                    rt.erase({a[ct.begin()->sec].fir ,ct.begin()->sec});
                    ct.erase(ct.begin());
                }else{
                    ok = 0;
                    break;
                }
            }

            ok &= !sz(rt) && (temp.fir == 0 || temp.sec == 0);
            if (ok){
                res.insert(rect);
            }
        }
    }

    cout << sz(res) << '\n';
    for(auto& i : res){
        cout << i.fir << ' ' << i.sec << '\n';
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