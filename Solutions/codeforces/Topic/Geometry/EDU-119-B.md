One thing I learned in this problem is that, if the triangle has the same length of base and height, no matter what's the angle, the area is always the same, think of it like a parallelogram. And this problem is about finding the maximum triangle we can given the coordinates, the constraint is, 2 points of the triangle must have a parallel side, we can basically use the length of every side * the length between itself and the opposite side.
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

struct Coord{
    int x,y;
};


void solve(){
    int t;
    cin >> t;
    while(t--){
        int w, h;
        cin >> w >> h;

        vector<ll> l;
        for(int i{}; i < 4; i++){
            int k;
            ll mn = 1000000001, mx = 0;
            cin >> k;
            for(int j{}; j < k; j++){
                ll p;
                cin >> p;
                if (p > mx) mx = p;
                if (p < mn) mn = p;
            }
            l.push_back(abs(mx-mn));
        }

        ll ans = 0;
        for(int i{}; i < 4; i++){
            ll temp;
            if (i < 2){
                temp = l[i] * h;
                if (temp > ans) ans = temp;
            }else{
                temp = l[i] * w;
                if (temp > ans) ans = temp;
            }
        }
        cout << ans << '\n';
    }
}

int main(){
    //setIO("t");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```