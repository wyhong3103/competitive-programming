Another implementation question, not much to say about it, I wondered if there's a better implementation than this, cus this is terrible xD

```cpp
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()


using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

void solve(){
	//Ox, Tiger, Rabbit, Dragon, Snake, Horse, Goat, Monkey, Rooster, Dog, Pig, Rat, Ox
	int n;
	cin >> n;
	map<string,int> years;
	map<string, string> zodiacs;
	map<string, string> relation;
	map <string, int> zodiacSigns {{"Tiger" , 1},{ "Rabbit" , 2}, {"Dragon" , 3},{"Snake" , 4}, {"Horse" , 5}, {"Goat", 6}, {"Monkey" , 7}, {"Rooster" , 8},{ "Dog" , 9}, {"Pig" , 10}, {"Rat" , 11}, {"Ox" , 12}};

	zodiacs["Bessie"] = "Ox";

	while (n--){
		string name;
		string year;
		string zodiac;
		string from;
		string temp;
		for (int i{}; i < 8; i++){
			if (i == 0) cin >> name;
			else if (i == 3) cin >> year;
			else if (i == 4) cin >> zodiac;
			else if (i == 7) cin >> from;
			else cin >> temp;
			}
		relation[name] = from;	
		zodiacs[name] = zodiac;
		if (year == "previous"){
			if (zodiac == zodiacs[from]) years[name] = -12;
			else if (zodiacSigns[zodiac] > zodiacSigns[zodiacs[from]]) years[name] = -(abs(12 - zodiacSigns[zodiac] + (zodiacSigns[zodiacs[from]])));
			else if (zodiacSigns[zodiac] < zodiacSigns[zodiacs[from]]) years[name] = -(abs(zodiacSigns[zodiac] - zodiacSigns[zodiacs[from]]));
			}
		else if (year == "next"){
			if (zodiac == zodiacs[from]) years[name] = 12;
			else if (zodiacSigns[zodiac] < zodiacSigns[zodiacs[from]]) years[name] =  zodiacSigns[zodiac] + (12-zodiacSigns[zodiacs[from]]);
			else if (zodiacSigns[zodiac] > zodiacSigns[zodiacs[from]]) years[name] = zodiacSigns[zodiac] - zodiacSigns[zodiacs[from]];
			}
		}


		
		string from{"Elsie"};
		string target{};
		int ans{years[from]};
		while (target != "Bessie"){
			target = relation[from];
			from = target;
			ans += years[target];
			}
		cout << abs(ans);


}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();

	return 0;
	}

```