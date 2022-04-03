Nothing much about this problem, it's just about finding a triangle with parallel sides to x and y axis, which is when 3 coordinates of the triangle have common x, and y between any 2 of them. I wondered if there's a better solution than using bunch of if statements.


```cpp
#include <bits/stdc++.h>
#include <limits>
 
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

struct Coord{
	int x,y;
	};

ll getArea(const Coord& c1, const Coord& c2, const Coord& c3){
	ll length, width;
	if (c1.y == c2.y){
		width = abs(c1.x - c2.x);
		}
	else if(c1.y == c3.y){
		width = abs(c1.x - c3.x);
		}
	else{
		width = abs(c2.x - c3.x);
		}
	
	if (c1.x == c2.x){
		length = abs(c1.y - c2.y);
		}
	else if(c1.x == c3.x){
		length = abs(c1.y - c3.y);
		}
	else{
		length = abs(c2.y - c3.y);
		}
	
	return (width * length);
}


void solve(){
	int n;
	cin >> n;
	vector<Coord> c(n);

	for(auto& i: c) cin >> i.x >> i.y;

	ll ans{};

	for (int i{}; i < n; i++){
		for(int j{i+1}; j < n; j++){
			for (int k{j+1}; k < n; k++){
				if ((c[k].x == c[i].x || c[k].x == c[j].x || c[i].x == c[j].x) && !(c[i].x == c[j].x && c[i].x == c[k].x) && (c[k].y == c[i].y || c[k].y == c[j].y || c[i].y == c[j].y ) && !(c[i].y == c[j].y && c[i].y == c[k].y )){
					ans = max(ans, getArea(c[i], c[j], c[k]));
					}
				}
			}
	
		}
	
	cout << ans;
	
}
 
int main(){
	setIO("triangles");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}

```
After looking at the solutions:
<br>
YES THERE'S A WAY, since we're already using 3 for loop, one way to use less if statments, is to actually get the permutation, of the coordinates, and only do checking on a the specific coordinates.
<br>

```cpp
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 105;

int main() {
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	int n; cin >> n;
	int x[MAX_N];
	int y[MAX_N];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				// Check to see if both points are parallel to the X and Y axis
				if (y[i] == y[j] && x[i] == x[k]) {
					int area = abs((x[j] - x[i]) * (y[k] - y[i]));
					ans = max(ans, area);
				}
			}
		}
	}
	cout << ans << endl;
}


```

