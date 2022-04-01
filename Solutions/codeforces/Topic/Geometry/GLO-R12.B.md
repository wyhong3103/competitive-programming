Overthought a little on this problem, time wasted! Anyways, this problem is just about finding whether there is such a ball which could attract every other balls, because that is the only possible way to make them in the same position

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
        int n, k;
        cin >> n >> k;
        
        vector<Coord> coords(n);
        for(auto& i: coords) cin >> i.x >> i.y;
        

        bool possible = false;
        for(auto& c: coords){
            bool valid = true;
            for(int i{}; i < n; i++){
                if (abs(c.x - coords[i].x) + abs(c.y - coords[i].y) > k){
                    valid = false;
                    break;
                }
            }
            if (valid) {
                possible = true;
                break;
            }
        }
        
    

        cout << (possible? 1 : -1) << '\n';



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