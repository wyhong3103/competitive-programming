This is a pretty good problem! Absolutely love it. So it's about finding the first painted number.
<br>
Explanation:
- Basically, there's a few criteria to become the first painted rectangle:
	- First , it cannot cover other rectangles, it can only either be covered or not covered, but cannot cover others, that's pretty much it , frankly
- So the implementation goes as follow:
	- First, we iterate through the entire art cells, if the number on the cell has not been search, we will search it with following steps:
		- Get it's maximum x,y and it's minimum x,y coordinates, because that determines its upper left and bottom right corner
		- After that, we can iterate through the art again but this time from the upper left to bottom right, any non i-th characters found will be considered as got covered, and we are going to insert covered character into a set, so that we can exclude it as a first character
	- Finally, we look for elements that isn't in the set

Link to problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=737
<br>
Solution:
```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) (x).begin(),(x).end()


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

vector<string> art;
set<char> cover;
set<char> found;
int n{};

void findCovered(pair<int,int> tl, pair<int,int> br, char c){
	for (int i{tl.first}; i <= br.first; i++){
		for (int j{tl.second}; j <= br.second; j++){
			if (art[i][j] != c){
				cover.insert(art[i][j]);
				}
			}
		}
}


void searchArea(char c){
	pair<int,int> tl{11,11}, br{};
	for (int i{}; i < n; i++){
		for (int j{}; j < n; j++){
			if (art[i][j] == c){
				tl.first = min(tl.first, i);
				tl.second = min(tl.second, j);
				br.first = max(br.first, i);
				br.second = max(br.second, j);
			}
		}
	}
	findCovered(tl, br, c);
	found.insert(c);
}


void solve(){
	cin >> n;
	art.resize(n);
	for(auto& i: art) cin >> i;

	
	for(int i{}; i < n; i++){
		for (int j{}; j < n; j++){
			if (art[i][j] != '0' && !found.count(art[i][j])){
				searchArea(art[i][j]);
				}
			}
		}
	
	int ans{};
	for (auto& i: found){
		if (!cover.count(i)) ans++;
	}
	cout << ans;
}


int main(){
	setIO("art");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}


```
