The idea of this problem is pretty simple, basically, we have to distrubute the R evenly, but with an elegant way of distributing it, instead of simply divde a / b+1 to distribute them.
```
The idea is to think of it as b+1 boxes, to distribute them evenly, we could insert them 1 by 1 into one box and another

Eg b = 2 (2 splitter),
|     |      |     |

a = 4

| x |    |    |

| x | x |   |

| x | x | x |
| x x | x | x |

Done

``` 
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()
#define pb push_back
 
using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
using ll = long long;
const double EPS = (1e-7);
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 
 
void solve(){
    int t;
    cin >>t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
 
        string s = "";
        vi arr(b+1);
        int x = 0;
        while(a--){
            arr[x]++; 
            x = (x + 1) % (b+1);
        }
        for(auto& i : arr){
            for(int x{}; x < i; x++){
                s += 'R';
            }
            if (b--) s += 'B';
        }
        cout << s << '\n';
    }
}
 
    
 
 
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;


```