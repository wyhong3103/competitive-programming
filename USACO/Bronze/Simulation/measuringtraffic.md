first time ever, integer overflow.. I spent at least 1 hour 30 minutes on this problem,most of the time have contributed to understanding the problem and thinking it,i got the algorithm, i implemented it. AND another 20 minutes+ to look for the error, integer overflow it is.... fuck it dude, how careless i am, anyway, here is the solution and it's explanation
<br>
Explanation:
- First, we iterate through the array of sensors, start with the first actual road, not off ramp or on ramp, we ignore them if we saw them before a road, because we don't know the exact number of people yet.
- If we found the first actual road, we start adding and subtracting if we saw off/on ramp, wit a simple arithmetic to get the best possible range of traffic flow. Same thing goes for the next segment of road, if we saw any, we take the interception of them, because that's the more concise range.Everytime we got a concise range, we assign the new range to the current range, so that it helps when we're backtracking
- And if we reached the end, we have our end sensor value then, now we need to backtrack, inverse the algorithm between on/off ramp, and take interception between roads, and whenever you reached the beginnning you got it.
<br>
Takeaway:
- Integer Overflow (on the size_t array, also the integer i've used)

```cpp
#include <bits/stdc++.h>
#include <limits>


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

struct Sensor{
	char road;
	int lower;
	int upper;
	};

void solve(){
	int n;
	cin >> n;
	vector <Sensor> sensors(n);
	for (auto& i : sensors){
		string str;
		cin >> str >> i.lower >> i.upper;
		i.road = str[str.length()-1];
		}
	
	pair <int,int> best_range{numeric_limits<int>::min(), numeric_limits<int>::max()}, start{}, end{};
	bool first_road{};
	for (size_t i{}; i < size(sensors); i++){
			if (sensors[i].road == 'e'){
				best_range.first = max(best_range.first, sensors[i].lower);
				best_range.second = min(best_range.second, sensors[i].upper);

				//make them as concise as possible , so that when i traceback it still works fine
				sensors[i].lower = best_range.first;
				sensors[i].upper = best_range.second;
				first_road = true;
				}
			else if (first_road && sensors[i].road == 'f'){
				best_range.first -= sensors[i].upper;
				best_range.second -= sensors[i].lower;
				}
			else if (first_road && sensors[i].road == 'n'){
				best_range.first += sensors[i].lower;
				best_range.second += sensors[i].upper;
				}
			best_range.first = max(best_range.first, 0);
		}
	end.first = best_range.first; end.second = best_range.second;
	
	for (int i{static_cast<int>(size(sensors)-1)}; i >= 0; i--){
			if (sensors[i].road == 'e'){
				best_range.first = max(best_range.first, sensors[i].lower);
				best_range.second = min(best_range.second, sensors[i].upper);
				}
			else if (sensors[i].road == 'f'){
				best_range.first += sensors[i].lower;
				best_range.second += sensors[i].upper;
				}
			else if (sensors[i].road == 'n'){
				best_range.first -= sensors[i].upper;
				best_range.second -= sensors[i].lower;
				}
			best_range.first = max(best_range.first, 0);
		}
	start.first = best_range.first; start.second = best_range.second;
	cout << start.first << ' ' << start.second << '\n' << end.first << ' ' << end.second;


	}

int main(){
	setIO("traffic");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

```