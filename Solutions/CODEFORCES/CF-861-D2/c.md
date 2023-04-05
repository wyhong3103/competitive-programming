```

If l and r is different length, answer is just 999..99 of length sz(r)-1

else

we could find the first differing digit,


let the index of that digit be i,

let y be r[i], x be l[i]

There are 3 type of number we can form from this, and we will prove why this is optimal
....yaaa..a
....zzzz..z
....xbbb..b

first i-1 character is just the same, since we cannot do anything with it

if y and x differ more than two, we can literally just iterate for every z s.t x < z < y

a is the largest integer we can do such. 

b is the minimal integer we could do such.

The reason why this is optimal is it's always best to have as little distinct integer as possible. 

think of it like this, say our max integer is 
yaaac

in this situation, a and c is going to affect our min and max, it might as well just have ycccc, rather than this

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
    string l, r;
    cin >> l >> r;
 
    if (sz(l) != sz(r)){
        for(int i{}; i < sz(r)-1; i++){
            cout << 9;
        }
        cout << '\n';
        return;
    }else{
        string s = r;
        int cur = 0;
        int tempmx = 0, tempmn = INT_MAX;
        for(int i{}; i < sz(r); i++){
            tempmx = max(tempmx, r[i]-'0');
            tempmn = min(tempmn, r[i]-'0');
        }
        cur = tempmx-tempmn;
 
        int mx = -1, mn = INT_MAX;
        for(int i{}; i < sz(r); i++){
            if (l[i] == r[i]) {
                mx = max(mx, r[i]-'0');
                mx = max(mx, l[i]-'0');
                mn = min(mn, r[i]-'0');
                mn = min(mn, l[i]-'0');
            }else{
                if (i+1 < sz(r)){
                    bool ok = 1;
                    int maxs = r[i+1]-'0';
                    for(int j{i+2}; j < sz(r); j++){
                        if ((r[j]-'0') > maxs) break;
                        ok &= (r[j]-'0') >= maxs;
                    }
                    if (!ok) maxs--;
                    for(int j{}; j <= maxs; j++){
                        int tmx = mx, tmn = mn;
                        tmx = max(tmx, r[i]-'0');
                        tmn = min(tmn, r[i]-'0');
                        tmx = max(tmx, j);
                        tmn = min(tmn, j);
                        if (tmx-tmn < cur){
                            string temp;
                            for(int k{}; k < i; k++){
                                temp += r[k];
                            }
                            temp += r[i];
                            for(int k{i+1}; k < sz(r); k++){
                                temp += j+'0';
                            }
                            s = temp;
                            cur = tmx-tmn;
                        }
                    }
                }
 
                int f = l[i]-'0'+(i != sz(r)-1), t = r[i]-'0'-(i != sz(r)-1);
 
                for(int j{f}; j <= t; j++){
                    int tmx = mx, tmn = mn;
                    tmx = max(tmx, j);
                    tmn = min(tmn, j);
                    if (tmx-tmn < cur){
                        string temp;
                        for(int k{}; k < i; k++){
                            temp += r[k];
                        }
                        for(int k{i}; k < sz(r); k++){
                            temp += j+'0';
                        }
                        s = temp;
                        cur = tmx-tmn;
                    }
                }
 
                if (i+1 < sz(r)){
                    bool ok = 1;
                    int mins = l[i+1]-'0';
                    for(int j{i+2}; j < sz(r); j++){
                        if ((l[j]-'0') < mins) break;
                        ok &= (l[j]-'0') <= mins;
                    }
                    if (!ok) mins++;
                    for(int j{mins}; j <= 9; j++){
                        int tmx = mx, tmn = mn;
                        tmx = max(tmx, l[i]-'0');
                        tmn = min(tmn, l[i]-'0');
                        tmx = max(tmx, j);
                        tmn = min(tmn, j);
                        if (tmx-tmn < cur){
                            string temp;
                            for(int k{}; k < i; k++){
                                temp += l[k];
                            }
                            temp += l[i];
                            for(int k{i+1}; k < sz(r); k++){
                                temp += j+'0';
                            }
                            s = temp;
                            cur = tmx-tmn;
                        }
                    }
                }
                break;
            }
        }
        cout << s << '\n';
        return;
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