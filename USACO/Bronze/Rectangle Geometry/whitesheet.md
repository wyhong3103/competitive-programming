This problem is quite fun, it's doable, and it's within my range. I have tackle the case that I hate the most, wooyeah
<br>
Afterthoughts:
- Should've been more cautios to the corner cases, and all those special cases
- This question is mostly about implementation , I would say, geometry side is alright.

<br>
Solution:

- Checking on whether one of the black sheet covered the entire white sheet
- If it wasn't , we do checking on the black sheets , check if it's a valid black sheet that can cover the entire white sheet (it must be covering the entire a portion of the white sheet (fully covered one of the axis), or else one of the black sheet must be covering the entire white sheet, which would be evaluated in the first conditional statement)
- Special case in this situation, the black sheet could cover a portion of the white sheet, but it could be covering the middle portion of the white sheet (that means 2 side of the white sheet is the remaining area)
- After that , we shrink the size of the whitesheet to the remaining side that is not covered, and check if another blacksheet covered it, and that's it


Link to the problem:
https://codeforces.com/contest/1216/problem/C

```cpp
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

struct Rect{
	int x1,y1,x2,y2;
	};

int intersection(int s1,int e1,int s2,int e2){
	return max(min(e1, e2)- max(s1,s2),0);
}


char valid(const Rect& w,const Rect& b){
	if (intersection(w.y1,w.y2,b.y1,b.y2)== (w.y2-w.y1)){
		if (b.x1 > w.x1 && b.x2 < w.x2) return '\0';
		else return 'y';
	}
	else if (intersection(w.x1,w.x2,b.x1,b.x2) == (w.x2-w.x1)){
		if (b.y1 > w.y1 && b.y2 < w.y2) return '\0';
		else return 'x';
	}
	return '\0';
	
}

bool covered(const Rect& w, const Rect& b){
	if (intersection(w.y1,w.y2,b.y1,b.y2)== (w.y2-w.y1) && intersection(w.x1,w.x2,b.x1,b.x2) == (w.x2-w.x1)){
		return true;
	}
	return false;
	}

void solve(){
	Rect w, b1, b2;
	cin >> w.x1>> w.y1 >> w.x2 >> w.y2 >>b1.x1 >> b1.y1 >> b1.x2 >> b1.y2 >>b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
	if (covered(w,b1) || covered(w,b2)) cout << "NO";
	else if (!(valid(w,b1) && valid(w,b2))) cout << "YES";
	else{
		if (valid(w,b1) == 'y'){
			if (b1.x2 >= w.x2) w.x2 = b1.x1;
			else w.x1 = b1.x2;
			if (covered(w,b2)) cout << "NO";
			else cout << "YES";
			}
		else if (valid(w,b1) == 'x'){
			if (b1.y2 >= w.y2) w.y2 = b1.y1;
			else w.y1 = b1.y2;
			if (covered(w,b2)) cout << "NO";
			else cout << "YES";
			}
		else if (valid(w,b2) == 'y'){
			if (b2.x2 >= w.x2) w.x2 = b2.x1;
			else w.x1 = b2.x2;
			if (covered(w,b1)) cout << "NO";
			else cout << "YES";
			}
		else if (valid(w,b2) == 'x'){
			if (b2.y2 >= w.y2) w.y2 = b2.y1;
			else w.y1 = b2.y2;
			if (covered(w,b1)) cout << "NO";
			else cout << "YES";
			}
		}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}
```
