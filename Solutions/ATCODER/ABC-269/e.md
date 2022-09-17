```
There are already N-1 rooks on the board.

The only way to place N rooks in such a way (each row/col one). Is they're placed diagonally. (Doesn't exactly have to place in such way, could be the permutation of it)

We can basically binary search the row first, picture the board as 1 dimensional straight line, and we need to find the spot where there's one missing.

Same goes for column.

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

    pi res;
    int lo = 1, hi = n;
    while (hi > lo){
        int mid = lo + (hi-lo)/2;
        cout << "? " << 1 << ' ' << mid << ' ' << 1 << ' ' << n << '\n';
        cout.flush();
        int amount;
        cin >> amount;
        cout.flush();
        if (amount >= mid){
            lo = mid+1;
        }else hi = mid;
    }
    res.fir = lo;
    
    lo = 1, hi = n;
    while (hi > lo){
        int mid = lo + (hi-lo)/2;
        cout << "? " << 1 << ' ' << n << ' ' << 1 << ' ' << mid << '\n';
        cout.flush();
        int amount;
        cout.flush();
        cin >> amount;
        if (amount >= mid){
            lo = mid+1;
        }else hi = mid;
    }
    res.sec = lo;

    
    cout << "! " << res.fir << ' ' << res.sec;
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