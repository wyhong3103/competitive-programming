One key takeaway from this problem is that, the area we're looking for could be on edge, so, we need to do extra test on the edge case. To avoid this, we could use 1-indexed prefix sum array
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
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}
 

int grid[1000][1000];
int prf[1000][1000];

void solve(){ 
    int n, q;
    cin >> n >> q;

    for(int i{}; i < n; i++){
        string s;
        cin >> s;
        for(int j{}; j < n; j++){
            grid[i][j] = (s[j] == '.' ? 0 : 1);
        }
    }

    //processing prefix 2D sum array
    //horizontally
    for(int i{}; i < n; i++){
        prf[i][0] = grid[i][0];
        for(int j{1}; j < n; j++){
            prf[i][j] = grid[i][j] + prf[i][j-1];
        }
    }

    //vertically
    for(int j{}; j < n; j++){
        for(int i{1}; i < n; i++){
            prf[i][j] += prf[i-1][j];
        }
    }

    for(int i{}; i < q; i++){
    	//tlc = top left col, tlr = top left row
        int tlr, tlc , brr, brc;
        cin >> tlr >> tlc >> brr >> brc;
        tlr--; tlc--; brr--; brc--;
        cout << prf[brr][brc] - (tlc == 0 ? 0 : prf[brr][tlc-1]) - (tlr == 0 ? 0 : prf[tlr-1][brc]) + (tlr == 0 || tlc == 0 ? 0 : prf[tlr-1][tlc-1]) << '\n';
        // D(the entire rect) - B(left rect) - C(upper rect) + A(in case if this piece got minus twice), if tlr is on row 0, then there's no need for C, tlc on row 0, no need for B, if any one of these is true, then there's no need for A
    }
    
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
```