Explanation:
- Keep track of the occurence of every possible moves at i-th game
- We basically want to look for the 2 that occur the most at 2 segment
```
Using prefix sum array

Input:
5
P
P
H
P
S

	1 2 3 4 5 	
H - 0 0 1 1 1

P - 1 2 2 3 3

S - 0 0 0 0 1

We only want 2 segments from a combinations of 2,

For example, let's choose paper and hoof, we want to get it's sum of occurences at i-th(paper) and after i-th(hoof)

Foward
HHHHH
PHHHH
PPHHH
PPPHH
PPPPH
PPPPP

Reverse
PPPPP
HPPPP
HHPPP
HHHPP
HHHHP
HHHHH

We want to form something like this, note that, the HHHH mean the range of prefix sum we're taking,

This operation only takes O(N)
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
 
void setio(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
}


void solve(){ 
    int n;
    cin >> n;
    map<char,vi> m;
    m['S'].resize(n);
    m['P'].resize(n);
    m['H'].resize(n);

    for(int i{}; i < n; i++){
        char c;
        cin >> c;
        m[c][i]++;
        if (i > 0){
            m['S'][i] = m['S'][i] + m['S'][i-1];
            m['H'][i] = m['H'][i] + m['H'][i-1];
            m['P'][i] = m['P'][i] + m['P'][i-1];
        }
    }

    vector<pair<char,char>> order = {{'P','H'}, {'P','S'}, {'H','S'}};
    
    int ans = 0;
    for(auto& i : order){
        for(int j{}; j < n; j++){
            ans = max(ans, m[i.fir][j]+ (m[i.sec][n-1] - m[i.sec][j]));
            ans = max(ans, m[i.sec][j] + (m[i.fir][n-1] - m[i.fir][j]));
        }
    }
    cout << ans;
}


int main(){
    //setio("hps");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}


```