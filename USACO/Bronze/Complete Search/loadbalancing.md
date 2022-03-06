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
pair<int, int> ans;

//get max and get min 

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
	if (maxe < ans.first){
		ans.first = maxe;
		ans.second = *min_element(all(q));
		}
}


void solve(){
	int n, b;
	cin >> n >> b;

	ans = {b, 0};
	
	Coord tl{b,b};
	Coord br{0,0};

	for (int i{}; i < n; i++){
		int x,y;
		cin >> x >> y;
		tl.x = min(x, tl.x);
		tl.y = min(y, tl.y);
		br.x = max(x, br.x);
		br.y = max(y, br.y);
		coords.push_back({x,y});

	}
	
	cout << tl.x << ' '  << tl.y << '\n';
	cout << br.x << ' ' << br.y << '\n';

	for (int i{(tl.x)+1}; i < br.x; i+=2){
		for (int j{(tl.y)+1}; i < br.y; i+=2){
			cout << i << ' ' << j << '\n';
			balance(i,j);
			}
		}
	
	cout << ans.second;

	
}
 
int main(){
	//setIO("lifeguards");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
 
	return 0;
	}



```