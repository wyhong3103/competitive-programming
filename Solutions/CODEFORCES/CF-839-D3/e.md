```

Let x = position for player 1 that is in favored before the game starts
Let y = position for player 2 that is in favored before the game starts

Notice that if player z was to turn a red cell that nobody is in favor to blue, it would favor both, as it has became free, and can be rearrange right away in the arrangement operation

So an optimal move, is to turn opponents' favored position that is red into blue! So they dont get benefit from it.

We simulate the process of the above, only start taking unfavored position of both when we have taken all of it.

If both player is tied and favored position of both players have all turned to blue, then it's going to be a tie. Not hard to see!

else we see who is the first to get all the position on his side.

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
 
    pi cnt;
    for(int i{}; i < n; i++){
        if (a[i] == i+1) cnt.fir++;
    }
    for(int i{n-1}; i >=0; i--){
        if (a[i] == n-i) cnt.sec++;
    }
    
    bool found = 0;
    if (n % 2 == 1 && a[n/2] == (n/2)+1){
        cnt.fir--;
        cnt.sec--;
        found = 1;
    }
 
    pi cur = cnt;
    int turn = 0;
    while (cur.fir < n-found && cur.sec < n-found){
        if (turn){
            if (cnt.fir){
                cur.sec++;
                cnt.fir--;
            }
            else{
                cur.fir++;cur.sec++;
            }
        }else{
            if (cnt.sec){
                cur.fir++;
                cnt.sec--;
            }
            else{
                cur.fir++;cur.sec++;
            }
        }
 
        if (cur.fir == cur.sec && !cnt.fir && !cnt.sec){
            break;
        }
        turn++;
        turn %= 2;
    }
 
    if (cur.fir > cur.sec){
        cout << "First" << '\n';
    }else if (cur.fir < cur.sec){
        cout << "Second" << '\n';
    }else cout << "Tie" << '\n';
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