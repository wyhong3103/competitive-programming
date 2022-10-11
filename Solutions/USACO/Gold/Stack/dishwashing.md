```

We want the clean stack to go from small to big (bottom to top), and we want as much element as possible in the prefix to be in the correct order!

The idea is to greedily distribute the plate onto the stacks.

At any moment,

If the current (new) plate is like bigger than every stacks's bottom most plate, then we create a new stack.

Else we look for the first stack of plates such that it's bottommost is bigger than the current plate, we put it on top of the stack if it is smaller than the current top of the stack, but this is not always the case, sometimes we might need to put it in the middle.


If we ever need to put it in the middle, we need to pop everything before it (including the stacks that came before it), until we can put it in the middle!

This is necessary because we want as many plates in the prefix to get into the right position! Everytime we pop a plate, by adding it to the clean stack, we basically set a new minimal, any plates comes after that has smaller number than the new minimal basically can't be placed correctly, that's when we end the prefix.

We basically have a monotonic stacks of monotonic stack. We can even binary search to find the corresponding stack.

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

    int cnt = 0;
    int cur = 0;
    int at = 0;

    //{bottom most number, the stack}
    vector< pair<int, stack<int>> > stacks;

    for(int i{}; i < n; i++){
        if (a[i] < cur) break;

        int lo = at, hi = sz(stacks)-1;
        while (hi > lo){
            int mid = lo + (hi-lo)/2;
            if (stacks[mid].fir > a[i]) hi = mid;
            else lo = mid+1;
        }

        if (stacks.empty() || stacks[lo].fir < a[i]){
            stack<int> temp;
            temp.push(a[i]);
            stacks.pb({a[i], temp});
        }else{
            if (stacks[lo].sec.top() > a[i]) stacks[lo].sec.push(a[i]);
            else{
                //start popping!
                for(int j{at}; j <= lo; j++){
                    while (!stacks[j].sec.empty() && stacks[j].sec.top() < a[i]){
                        cur = stacks[j].sec.top();
                        stacks[j].sec.pop();
                    }  
                    if (j == lo){
                        stacks[j].sec.push(a[i]);
                    }else{
                        at++;
                    }
                }
            }
        }
        cnt++;
    }
    cout << cnt;
}
 
int main(){
    setio("dishes");
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}

```