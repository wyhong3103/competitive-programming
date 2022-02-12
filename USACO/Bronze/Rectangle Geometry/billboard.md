Billboard problem from Rectangle Geomtry Bronze Topic
http://www.usaco.org/index.php?page=viewproblem2&cpid=759

This technique was inspired by the cow problem, to find the intersection between two rectangle, you can use 

x1 , x2 = beginning and ending coordinate of x
same geos to z

max(min(x1,z2) - max(z1,x2), 0)

If they overlap, it will return value greater than 0, it they don't , that means they are not intersecting , so it return 0



```cpp
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
	int bx1,by1,bx2,by2;
	int b_x1, b_y1, b_x2, b_y2;
	int tx1,ty1,tx2,ty2;
	cin >>  bx1 >> by1 >> bx2 >> by2 >> b_x1 >> b_y1 >> b_x2 >> b_y2 >> tx1 >> ty1 >> tx2 >> ty2;
	int combined_area, intersection, total;
	combined_area = (abs(bx2 - bx1) * abs(by2 - by1) + abs(b_x2 - b_x1) * abs(b_y2 - b_y1));
	intersection = max(min(bx2, tx2) - max(bx1,tx1),0) * max(min(by2,ty2) - max(by1,ty1), 0) + max(min(b_x2, tx2) - max(b_x1,tx1),0) * max(min(b_y2,ty2) - max(b_y1,ty1), 0) ;
	total = combined_area - intersection;
	cout << total;
}
int main(){
	setIO("billboard");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}
```