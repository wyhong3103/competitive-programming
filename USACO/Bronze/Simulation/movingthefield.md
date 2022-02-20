First off, this is not a hard problem, basically travelling through a 2D grid, setting the time on every cell, and if it travels through the same cell, we just take the minimum time we can find (basically time - timeOnCell)
<br>
<br>
The only problem I faced in this problem, is , THE 2D ARRAY, I don't know why, using array and vector give me so much error, and i've literally spent like 30 minutes trying to fix that, and idk what's going on, so i just went to use the fixed size traditional 2d array, and i forgot the syntax of it, spent like 10 minutes as well.....
<br>
I got the solution in mind, it's just the implementation that cost me most of the time....
<br>
Also i've messed up the coordinating system, and received an unknown error , a negative status code, which happened because i am trying to access the outer boundary of the array, which is a very goofy mistake... Hell, when i finally got them all solved, this code works!
<br>
Explanation
- First generate the coordinate planes
- Travel through it according to the direction and steps given
- Take the minimum time between the subtraction of current time and time on the cell
- return ans

<br>

Takeaway from this problem:
- Don't mess up the coordinate plan, moving down means adding the row number! I've messed up this one
- Accessing elemetns outside of the array return you a negative status code
- Have to start learning how to implement a multimdimensional array with \<array\> and \<vector\>

```cpp
#include <bits/stdc++.h>
#include <limits>


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


void solve(){
	int n;
	cin >> n;
	vector<pair <char, int>> ds;
	int rightMost{}, leftMost{},upMost{}, bottomMost{};
	int x{}, y{};
	while (n--){
		char D;
		int S;
		cin >> D >> S;
		ds.push_back({D,S});
		switch (D){
			case 'N':
				y += S;
				break;
			case 'E':
				x += S;
				break;
			case 'S':
				y -= S;
				break;
			case 'W':
				x -= S;
				break;
			}
		(y >= 0 ? upMost = max(upMost, y) : bottomMost = min(bottomMost, y));
		(x >= 0 ? rightMost = max(rightMost, x) : leftMost = min(leftMost, x));
		}

	pair <int,int> start {upMost, abs(leftMost)};
	int length{abs(leftMost)+rightMost+1}, height{abs(bottomMost)+upMost+1};

	int plane[height][length]{};	

	int time{1}, ans{length*height+1};
	for (const auto& i: ds){
		for(int j{}; j < i.second; j++){
			switch (i.first){
				case 'N':
					start.first--;
					break;
				case 'E':
					start.second++;
					break;
				case 'S':
					start.first++;
					break;
				case 'W':
					start.second--;
					break;
				}
			if (plane[start.first][start.second] != 0){
				ans = min(time-plane[start.first][start.second], ans);
				}
			plane[start.first][start.second] = time;
			time++;
			}
		}
	if (ans == length*height+1) ans = -1;
	cout << ans;
}

int main(){
	setIO("mowing");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

```