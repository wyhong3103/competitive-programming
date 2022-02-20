Well, I honestly don't know why this problem is categorzied into hard section, when it's actually not....
<br>
But, the point is, I solved it :D, it's still the implementation that took most of the time, I gotta be really good with the syntax and all! or else it's just going to cost me more time than it actually does!
<br><br>
Okay so let's cut to the chase, so basically this question is asking us to look for the number of time the banner or something would change
<br>
It only changes when:
- There's different cow has the maximum milk compared to yesterday
<br><br>
The tricky part of this problem is, the first day, not really tricky, but yeah
<br>
Explanation
- alright, so first off, i've created an array of day, which store the changes of the cow's milk measurement, and i'll iterate through every single day and ,do necssary changes to the cow variable i have, and if there are differnt cows on the maximum board, i'll +1 to the ans

```cpp
#include <bits/stdc++.h>


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

struct Day{
	int m{};
	int e{};
	int b{};
	};

struct Cow{
	char name{};
	int milk{};
	};

void solve(){
	int n;
	cin >> n;
	array <Day,1000> days{};
	while (n--){
		int day, change;
		string name;
		cin >> day >> name >> change;
		if(name == "Mildred"){
			days[day-1].m = change;
		}
		else if( name == "Elsie"){
			days[day-1].e = change;
		}
		else{
			days[day-1].b = change;
		}
	}

	
	pair <string,int> best{};

	using cow_arr = array<Cow,3>;
	cow_arr cows{{
		{'m',7},
		{'e',7},
		{'b',7}
		}};
	int ans{};
	int maxMilk{};
	for (int i{}; i < 1000; i++){
		pair <string, int> bestToday{};
		cows[0].milk =max(cows[0].milk + days[i].m, 0);
		cows[1].milk = max(cows[1].milk + days[i].e, 0);
		cows[2].milk = max(cows[2].milk + days[i].b, 0);
		cow_arr::iterator maxMilkIter = max_element(cows.begin(), cows.end(), [](const Cow& a,const Cow& b){return a.milk < b.milk;});
		maxMilk = maxMilkIter->milk;
		bestToday.second = maxMilk;


		for (auto& cow: cows){
			if (cow.milk == maxMilk){
				bestToday.first += cow.name;
				}
			}
		if (!(i == 0 && bestToday.first.length() == 3) && best.first != bestToday.first){
			ans += 1;
			}
		best.first = bestToday.first;
		best.second = bestToday.second;
		}
	cout << ans;
}



int main(){
	setIO("measurement");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
	}

``