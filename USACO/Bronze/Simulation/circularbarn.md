This problem is fun, and it's easy! like real easy comapred to the past few problems....It's straight and simple. You know what I think most of the time , the reasons I wasn't able to think of a solution, is because I don't understand the problem, once I understood it, there's this algorithm I could think of, but understanding the problem takes a little long, sometimes.
<br>
Explantion:
- Essentially just simulate from the entire room, with two nested loop, a little array arithmetic but fine
<br>
Link to problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=616

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
	vector <int> roomCapacity(n);
	for(auto&i : roomCapacity){
		cin >> i;
		}	

	int distance{numeric_limits<int>::max()};
	for (int i{}; i < size(roomCapacity); i++){
		int temp_dist{};
		for (int j{i+1}; j < i+n ; j++){
			temp_dist += (j-i)*(roomCapacity[j%n]);
			}
		distance = min(temp_dist,distance);
	}
	cout << distance;
	}

int main(){
	setIO("cbarn");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

```

