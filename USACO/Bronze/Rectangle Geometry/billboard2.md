Link to question:<br>
http://www.usaco.org/index.php?page=viewproblem2&cpid=783

This question is rated as easy, but hell, it took me a few hours to do it, sometimes, this geometry system thingy just had me going crazy....
<br>
But hell yeah, i solved it....
<br>
Explanation: <br>
- First we find the intersection between the board1 and board2( it must be intersection the both side or else, it's not considered as intersection, because we still need to cover the other side with the tarp)
- There's one special case in this question, which is when, it covered both side (whether bottom & up or right & left) , but it's in the middle, if that happens , we still have to cover the entire billboard


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


void solve(){
	Rect b1, b2;
	cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2 >>b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
	int intersection_x, intersection_y;
	intersection_x = intersection(b1.x1, b1.x2, b2.x1, b2.x2);
	intersection_y = intersection(b1.y1, b1.y2, b2.y1, b2.y2);
	
	if (b2.y2 < b1.y2 || b2.y1 > b1.y1){
		intersection_x = 0;
		}
	if (b2.x2 < b1.x2 || b2.x1 > b1.x1){
		intersection_y = 0;
		}
	
	if ((b2.x1 > b1.x1 && b2.x2 < b1.x2) || (b2.y1 > b1.y1 && b2.y2 < b1.y2)){
		intersection_x = 0;
		intersection_y = 0;
		}

	int side_x, side_y;
	side_x = b1.x2 - b1.x1 - intersection_x;
	side_y = b1.y2 - b1.y1 - intersection_y;
	cout << side_x * side_y;

}
int main(){
	setIO("billboard");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

```