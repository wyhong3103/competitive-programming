```
p is basically the array of arrangement

q starts with 1,2,3,4...

And then keep on reordering according to p

So you can sort of think of it as a functional graph, where there is cycles and all.

Let's observe the below sequence, and get our answer from within

p = 4 2 1 3

q = 1 2 3 4
q = 4 2 1 3
q = 3 2 4 1
q = 1 2 3 4

Notice that,

The first number goes from 1 -> 4 -> 3 -> 1,

The moment it goes back to 1 again is when it finishes its cycle, and that's where we should stop.

1 -> 4 -> 3

This sequence is basically our answer,

In order for 4 to replace 1, p[4] must equal to 1, similarly in order for 3 to replace q[1], it must first go to q[4] and then q[1],which basically mean

p[1] = 4
p[4] = 3
p[3] = 1

Now the other thing to note is that even though we got the cycle sequence that's not going to tell us anything but the order, unless we identify one of the element's original placement. Which we can easily identify, because, q is initially 1,2,3,4....

So we query a sequence, find the starting point (based on the index), and then reorder them, and that's the answer.
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

    vi res(n);

    for(int i{}; i < n; i++){
        if (!res[i]){
            cout << "? " << i+1 << '\n';
            cout.flush();

            int cur;
            cin >> cur;

            vi cycle;
            cycle.pb(cur);
            cur = 0;
            while (cur != cycle[0]){
                cout << "? " << i+1 << '\n';
                cout.flush();

                cin >> cur;
                if (cur != cycle[0]) cycle.pb(cur);
            }

            int start = 0;
            for(int j{}; j < sz(cycle); j++){
                if (cycle[j] == i+1){
                    start = j;
                    break;
                }
            }
            cur = i;
            for(int j{start+1}; j < sz(cycle); j++){
                res[cur] = cycle[j];
                cur = cycle[j]-1;
            }
            for(int j{}; j < start; j++){
                res[cur] = cycle[j];
                cur = cycle[j]-1;
            }
            res[cur] = i+1;
        }
    }

    cout << "! ";
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