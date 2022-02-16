fml, fml, fml....<br>
I got misleaded by the example, example is shown using the the combination of words, also this is a simulation topic, but nah, it aint at all... Forget it, i was just trying to find excuses, anyway, i've wasted around hours implementing the first solution, and I couldn't solve it, I couldn't think of a solution that would not take big O of exponential , it's definitely unfeasible , I got TLE for that, and then, I went back to thinking how is it possible to not get exponential (since we had to get the combination of words), after hours of no progress, I went to the editorial, which is CERTAINLY POSSIBLE, and I've thought for that solution for a few moment,like getting the maximum frequency kind of thing , but I just thought it wasn't possible if you don't have the combination, how fix-minded i am, fuc....
<br>
Explanation:
- Basically: http://www.usaco.org/current/data/sol_blocks_bronze_dec16.html
- Look for the maximum occurence of a character in each pair of words (the front side and the back side of the board), and then add it to the letter array we got there.
- Do this same process for each pair of words, we will get ourself what we need.


```cpp
#include <bits/stdc++.h>
#include <limits>


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

struct Board{
	string front;
	string back;
	};

int getFrequency(const string& str, char i){
	int freq{};
	for (auto& j: str){
		if (i == j) freq+=1;
		}
	return freq;
	}

void solve(){
	int n;
	cin >> n;
	vector <Board> boards(n);
	for(auto& i: boards){
		cin >> i.front >> i.back;
		}
	//26 = number of letters
	vector <int> letters(26);
	
	for (const auto& i: boards){
		for (char x{'a'}; x <= 'z'; x++){
			if (getFrequency(i.front,x) > getFrequency(i.back, x)){
				letters[x-'a'] += getFrequency(i.front,x);
				}
			else{
				letters[x-'a'] += getFrequency(i.back,x);
				}

			}

	}

	for (const auto& i: letters){
		cout << i << '\n';
		}

}
int main(){
	setIO("blocks");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

```