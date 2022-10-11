```

We can use a similar method to maximum building I in CSES.

Solve it row by row using histogram-like method.

For each column, we can calculate it's prefix (not really prefix, because we recalculate it if it's a different number) sum (the height of current number).

First let's see how do we count a subrectangle in a historgram first.

3 3 1
3 3 1
2 2 5

First row

3 = 1 (sub rectangle)

3 3 = 2 

(we can set the ending point as the bottom right of the rectangle and then use every point available in the area, which is self and the first number as the top left of the rectangle)

1 = 1

New color, we have to reset it.

First Row Total = 4

Second row

3
3 = 2 (self and above)

3 3
3 3 = 4 (self and the other 3 as top right)

1
1 = 2 (self and above)

Second Row Total = 8

Third row

2 = 1

2 2 = 2

5 = 1

Third Row Total = 4

Total = 4 + 8 + 4 = 16

Let's look at another example!

1 2 2 1
2 2 2 2

First row

1 = 1

2 = 1

2 2 = 2

1 = 1

First Row Total = 5

Second Row

2 = 1 (we don't consider the 1 above, as it is not the same number)

  2
2 2 = 3

  2 2
2 2 2 = 5
 
2 2 2 2 = 4 

(Notice that over here, we cannot count anything higher than the height of current bar!)

So this inspired us to use a monotonic stack!

The idea is we need to keep track of the total cells in the current stack, we will be storing a monotonic stack (small -> big), the current cell has to be the largest, because we cannot take anything larger previously!

How to keep track of cells?

Everytime we add a bar that is smallest than the top of the stack, we pop the top of the stack off, and then subtract (the popped top's index - the new top's index) * top's height, because that's how much it contributed to the total sum.

If the stack gone empty, we don't have new top, we simply need to substract popped top's index by the starting index of the stack! It's not always 0! because the number could vary along the way.
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
    int n, m;
    cin >> n >> m;

    vector<vll> a(n, vll(m));

    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            cin >> a[i][j];
        }
    }

    vector<vll> prefix(n, vll(m));
    
    for(int j{}; j < m; j++){
        for(int i{}; i < n; i++){
            if (!i || a[i][j] == a[i-1][j]){
                prefix[i][j] = (!i ? 0 : prefix[i-1][j]) + 1;
            }else prefix[i][j] = 1;
        }
    }

    ll res = 0;
    for(int i{}; i < n; i++){
        ll temp = 0;
        int start = 0;
        //{at, height}
        stack<pll> s;
        for(int j{}; j < m; j++){
            if (!j || a[i][j] == a[i][j-1]){
                while (!s.empty() && s.top().sec >= prefix[i][j]){
                    pll cur = s.top();
                    s.pop();
                    temp -= (cur.fir - (s.empty() ? (start-1) : s.top().fir)) * cur.sec;
                }
                temp += (j-(s.empty() ? (start-1) : s.top().fir)) * prefix[i][j];
            }else{
                while (!s.empty()) s.pop();
                start = j;
                temp = prefix[i][j];
            }
            s.push({j, prefix[i][j]});
            res += temp;
        }
    }
    cout << res << '\n';
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