This problem is genuinely tricky, I've try a similar method to the one in the solution. But it doesn't really work, which makes me think that I should check every single cell. I KNEW THAT THE COORDINATES DOESN'T MATTER, BECAUSE LOOK, IF ITS (1, 1) to (1e6, 1e6), it would be tedious to go from 1 to 1 million. My initial thinking was to, create a fence on each corner of a single cow, which is x+1 y+1, x+1 y-1, x-1 y+1, x-1 y-1, but that doesn't really works, but it's close enough to this method. this method is to create a fence at the x+1, and y+1 of every cow. Then iterate through each one of em, and do the checking.
<br><br>
I do not solve this problem.



```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
 
 
using ll = long long;
using namespace std;
 
void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


struct Coord{
	int x,y;
	};


vector<Coord> coords;
int ans;

void balance(int x, int y){
	vector<int> q(4);
	for (auto& i : coords){
		if (i.x < x && i.y < y){
			q[0]++;
		}
		else if (i.x > x && i.y < y){
			q[1]++;
		}
		else if (i.x > x && i.y > y){
			q[2]++;
			}
		else {
			q[3]++;
			}
	}
	
	int maxe = *max_element(all(q));
	if (maxe < ans){
		ans = maxe;
		}
}


void solve(){
	int n, b;
	cin >> n >> b;

	ans = b;
	
	Coord tl{b,b};
	Coord br{0,0};

	vector<int>fences_y;
	vector<int>fences_x;

	for (int i{}; i < n; i++){
		int x,y;
		cin >> x >> y;
		coords.push_back({x,y});
		fences_x.push_back(x+1);
		fences_y.push_back(y+1);
	}

	for(auto& i: fences_x){
		for(auto& j: fences_y){
			balance(i, j);
		}
	}
	
	cout << ans;

	
}
 
int main(){
	setIO("balancing");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}


```