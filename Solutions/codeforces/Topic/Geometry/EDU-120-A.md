The only two cases for a rectangle to form are when the stick we're going to break has the equal length to the other two, or when the other 2 are equal in length, and our stick is divisible by 2

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


void solve(){
    int t;
    cin >> t;
    while(t--){
        vector<int> l(3);
        for(auto& i: l) cin >> i;
        bool found = false;
        for(int i{}; i < 3; i++){
            int val = 0;
            set<int> s;
            for(int j{}; j < 3; j++){
                if (i != j){
                    val += l[j];
                    s.insert(l[j]);
                }
            }
            if (l[i] == val){
                found = true; 
            }
            if (s.size() == 1 && l[i] % 2 == 0) {
                found = true;
            }
        }
        cout << (found ? "YES" : "NO") << '\n';
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