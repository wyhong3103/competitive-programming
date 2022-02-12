link to problem : https://codeforces.com/blog/entry/93389
<br>
Should've think of the simplest case, I mess it up, anyways, here is the explanation to my solution
<br>
Explanation:
<br>
- first, i validate the room, see if the table can fit into the room (by moving the table to the upper right), and compare the remaining horizontal space and vertical space to the table
- second, i calculate how much i need to move it to get the space i need, (say the vertical space is enough for the table, i m going to do a simple calculation which is , if vertical space, x = 3, y= 2, and the table = x=4 ,y=2, im going to add x/y until it fit), after looking at the editorial, i can see that i did a redundant step here, if i chose the vertical space, i can straight up ignore the vertical movement, but I did it anyway
- same goes to the horizontal space
<br>
Editorial: https://codeforces.com/blog/entry/93389

```
#include <bits/stdc++.h>
#include <limits>
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}
 
struct Rect{
	int x1{},y1{},x2{},y2{};
	};
 
 
void solve(){
	int n;
	cin >> n;
	while (n--){
	Rect room, ftable, stable;
	//ftable = first table, stable = second table
	cin >> room.x1 >> room.y1 >> ftable.x1 >> ftable.y1 >> ftable.x2 >> ftable.y2 >> stable.x1 >> stable.y1;
 
	int x_space, y_space;
	double movement_1{std::numeric_limits<double>::max()}, movement_2{std::numeric_limits<double>::max()};
	bool canContain{false};
	if ((room.x1 - (ftable.x2-ftable.x1) >= stable.x1 && room.y1 >= stable.y1)){
		canContain = true;
		movement_1 = 0;
		x_space = max(ftable.x1, room.x1-ftable.x2);
		y_space = room.y1;
		if (x_space < stable.x1){
			movement_1 += stable.x1 - x_space;
		}
		if (y_space < stable.y1){
			movement_1 += stable.y1 - y_space;
			}
 
	}
	if((room.x1 >= stable.x1 && (room.y1-(ftable.y2-ftable.y1)) >= stable.y1)){
		canContain = true;
		movement_2 = 0;
		x_space = room.x1;
		y_space = max(ftable.y1, room.y1-ftable.y2);
		if (x_space < stable.x1){
			movement_2 += stable.x1 - x_space;
		}
		if (y_space < stable.y1){
			movement_2 += stable.y1 - y_space;
			}
	}
	if (canContain){
		cout <<  std::setprecision (9) << min(movement_1,movement_2) << '\n';
	}else{
		cout << -1 << '\n';
	}
	}
}
int main(){
	//setIO("billboard");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}
```