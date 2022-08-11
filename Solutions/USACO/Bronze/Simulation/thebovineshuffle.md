bruh, fuck me, i was tripping so hard while doing this question, the shuffling should've been i to a.i, but DANG, for the past hour, i kept thinking that it was a is where cow[i] should've been
<br>
If you have no clue what I was talking about this is a demonstration
<br>
3 2 5 4 1 : a1 a2 a3 a4 a5
<br>
CORRECT WAY OF SHUFFLING : i be in ai, first cow be at the third position, second cow be at the second position, third cow be at the fifth position.
<br>
Instead of seeing it as a shuffling instruction, i saw it as a shuffled sequence , what i thought was first cow should've be in the fifth position,second cow should've be in the 2nd,  third cow should've been in the first, forth cow be at the forth position, fifth be at first
<br>
Jesus fuck! 2 hours wasted , man fuck me for being reckless.....This implementation could be further optimized , but neh, im exhausted wit this question, i was doing the right thing, implementing the correct thing, but only this logic thing had me dead....

```cpp
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
	int n;
	cin >> n;
	vector<int> order(n);
	vector <int> cows(n);
	vector <int> sorted_cow(n);
	for (auto& i: order){
		cin >> i;
		}
	for (auto& i: cows){
		cin >> i;
		}



	for (int i{}; i < n; i++){
		sorted_cow[i] = cows[order[i]-1];
		}

	for (int i{}; i < n; i++){
		cows[i] = sorted_cow[order[i]-1];
		}
	for (int i{}; i < n; i++){
		sorted_cow[i] = cows[order[i]-1];
		}


	for (auto& i : sorted_cow){
		cout << i << '\n';
		}
	
}

int main(){
setIO("shuffle");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

```