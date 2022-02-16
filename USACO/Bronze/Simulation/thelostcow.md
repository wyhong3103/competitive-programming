I'm literally simulating the entire process of finding the cow, at first, i was literally seeking for good algorithm (w out simluting), but god damn, this topic is about simulation, so i guess im just gon be simulating the rest of the problem...

Link to problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=735

```cpp
	#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
	int x, y;
	cin >> x >> y;
	array <int,1001> road;
	for (size_t i{}; i <= 1000; i++){
		road[i] = i;
		}
	
	int location{x}, movement{}, steps{}, counter{};
	while (location != y){
		if (!movement){
			if (counter % 2 == 0){
				movement = abs(location-x) + pow(2,counter);
				}
			else{
				movement = -(location - x) - pow(2,counter);
				}
			counter++;
		}
		else{
				if (movement > 0){
					movement--;
					location++;
					}
				else{
					movement++;
					location--;
					}
				steps++;
			}
		}
	cout << steps;
	
}

int main(){
	setIO("lostcow");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

```