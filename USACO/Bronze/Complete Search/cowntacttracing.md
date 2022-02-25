At first i thought this question was tedious, i was doing complete search at the very first time, but i messed it up, I didn't think of assuming every k (0 < k <= T) as well, I was just assuming every possible infected cow as the patient zero, that's when i fell of, i tried looking for k , using bunch of conditional statements, but i realised that it's just too tedious to literally look for every corner and special cases. My solution got half of them right, but it turned out (after I took a glance at the editorial). And I saw it's saying assuming every cow and k, that's when i knew , i've gone so wrong, and i straight up went to rewrite the solution, and finally got it done!
<br>
Key Takeaway:
- Pay more attention to the input size, optimize it, in this case, I just didn't thought of assuming every k, even though, when i decided to assume every cow, i still have a lot of extra time i could use...

```cpp
#include <bits/stdc++.h>
#include <limits>


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


struct Ts{
	int t, x, y;
	};

void solve(){
	int N, T;
	cin >> N >> T;
	string states;
	cin >> states;

	vector <Ts> timestamps(T);
	for (auto& i : timestamps){
		cin >> i.t >> i.x >> i.y;
		}
	
	sort(timestamps.begin(), timestamps.end(), [](Ts a, Ts b){
		return a.t < b.t;
		});
	
	int x{};
	vector <int> possible_k{};

	for (int i{}; i < N; i++){
		if (states[i] == '1'){
			bool valid{false};
			for(int k{}; k <= T; k++){
				string infected;
				vector<int> k_tracker(N);
				for (int x{}; x < N; x++){
					if (x == i) infected += '1';
					else infected += '0';
					}
				for (auto& t: timestamps){
					if (infected[t.x-1] != '1' && infected[t.y-1] == '1') {
						int temp = t.y;
						t.y = t.x;
						t.x = temp;
						}
					if (infected[t.x-1] == '1'){
						if (infected[t.y-1] == '1'){
						  	if(k_tracker[t.x-1] < k){
								k_tracker[t.x-1]++;
								}
							if (k_tracker[t.y-1] < k){
								k_tracker[t.y-1]++;
								}
							}
						else if (infected[t.y-1] == '0' && k_tracker[t.x-1] < k){
							infected[t.y-1] = '1';
							k_tracker[t.x-1]++;
							}
						}
					}
				if (infected == states){
					valid = true;
					possible_k.push_back(k);
					}
				}
				if (valid) x++;
			}
		}
	
	cout << x << ' ';
	int y{300}, z{};
	for (auto& i: possible_k){
		if (i < y) y = i;
		if (i > z) z = i;
		}
	cout << y << ' ' ;
	if (z == T) cout << "Infinity";
	else cout << z;
	

}

int main(){
	setIO("tracing");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}
```