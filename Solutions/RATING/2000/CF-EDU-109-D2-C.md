```

It's not hard to see that only even will collide with even, and odd with odd.

So we can group them into two arrays and deal with them individually.


For each group,


We can have a stack for robot that is heading to the left and another one for the right that keep tracks of the undestroyed robot.

For a robot that is currently heading to the left, if there is a robot heading to the right that is in the stack (which means it comes before this robot), they will destroy each other.

Otherwise, this robot will collide with the first guy it finds on the left (top of left stack) and collide with it.

If left stack and right stack are currently empty, we push it to the stack, it is to be destroyed later.

For a right robot, we always push it to the stack,

Let's say we have

R R L

Situation, we cannot collide with the second R as the second R will collide with the L. So the idea is we can simply push it to the stack first.

At the end, every pair of robot heading to the right (from the end) will destroy each other. 

Left stack will not have more than 1 robot, because they will always destroy each other.

At the end, if we are left with 1 in left and 1 in right, they will collide with each other.

Do the same thing for even and odd.

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
 
 
int n, m;
 
void findres(vector<pi>& a, vector<char>& d, vi& res){
    stack<pi> l, r;
    
    for(auto& i : a){
        if (d[i.sec] == 'L'){
            if (!r.empty()){
                pi cur = r.top(); r.pop();     
                int t = (i.fir-cur.fir)/2;
                res[i.sec] = t;
                res[cur.sec] = t;
            }else if(!l.empty()){
                pi cur = l.top(); l.pop();     
                int t = cur.fir + (i.fir-cur.fir)/2;
                res[i.sec] = t;
                res[cur.sec] = t;
            }else{
                l.push(i);
            }
        }else{
            r.push(i);
        }
    }
 
    while (sz(r) > 1){
        pi cur = r.top(); r.pop();
        pi cur1 = r.top(); r.pop();
        int t = (m - cur.fir) + (cur.fir - cur1.fir)/2;
        res[cur.sec] = t;
        res[cur1.sec] = t;
    }
    
    if (sz(r) && sz(l)){
        pi cur = r.top(); r.pop();
        pi cur1 = l.top(); l.pop();
        int dist1 = cur1.fir; 
        int dist2 = m-cur.fir;
 
        if (dist1 > dist2) swap(dist1, dist2);
 
        int t = dist2 + (m-(dist2-dist1))/2;
        res[cur.sec] = t;
        res[cur1.sec] = t;
    }
}
 
void solve(){
    cin >> n >> m;
 
    vi a(n);
    vector<char> d(n);
    for(auto& i : a) cin >> i;
    for(auto& i : d) cin >> i;
 
    vector<pi> e;
    vector<pi> o;
 
    for(int i{}; i < n; i++){
        if (a[i] % 2){
            o.pb({a[i], i});
        }else{
            e.pb({a[i], i});
        }
    }
 
    sort(all(e));
    sort(all(o));
 
    vi res(n, -1);
    findres(e, d, res);
    findres(o, d, res);
 
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