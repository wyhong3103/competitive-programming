This question is essentially about finding the longest side 
http://www.usaco.org/index.php?page=viewproblem2&cpid=663

```cpp
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
	int x1,y1,x2,y2;
	int x3,y3,x4,y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	int right{}, left{}, top{}, bottom{}, side{};
	right = max(x2,x4);
	left = min(x1,x3);
	top = max(y2,y4);
	bottom = min(y1,y3);
	side = max(right-left, top-bottom);
	cout << side * side;
}
int main(){
	setIO("square");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

```