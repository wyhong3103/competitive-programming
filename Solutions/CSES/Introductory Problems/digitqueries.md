This problem is essentially about finding the i-th integer at a string like this '12345678910111213141516171819202122232425',from 1 to inf, essentially. To get the i-th number, first , we have to know that every 10 * n number , has n digits, 0 to 9, (10 * 1), has only 1 digit, 10 to 99 has 2 digits (10 * 2), and it goes on and on. The key observation here is to know that from 1 to 9 we have 9 numbers, 10 to 99, we have 90 numbers, and there's a pattern right here. As our number goes arbitarily large, number of 0 beside 9 is just going to increase. From 1000 to 9999 there will be 9000 numbers. With this, we can determine which range the number we're looking for is in. And in order to find it, first we got the input , if input > (9 * 1), then input - (9 * 1), 9 * = 10, 1++, if input > (90 * 2), we do the same thing, until it become smaller than the upperbound. Once we got into the range all we have to do is, find the i-th number using ceil(input / n)(number of 0), and use (10 ** n) - 1(because remember we're not including the final number, 100, 1000 etc, we only reach 99 , 999), with that i-th number now we have to decide the position of that number we're looking at, we can simply get it by using (input mod n).
<br>
I failed this twice, because I wasn't using double for ceiling, and second time , I realized that double is not enough , I need long double instead.

```cpp
#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
 
using ll = long long;
using namespace std;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}


void solve(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        int d{1};
        ll upper{9};
        while(n > (d * upper)){
            n -= (upper * d);
            d++;
            upper *= 10;
        }

        ll i = ceil((long double)n/d);
        ll start{1};
        for(int j{1}; j < d; j++){
            start *= 10;
        }
        
        ll num = (start-1) + i;
        string s = to_string(num);

        int pos = n % d;
        if (pos == 0){
            cout << s[s.length()-1] << '\n';
        }
        else {
            cout << s[pos-1] << '\n';
        }
    }

}

int main(){
//   setIO("reduce");
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

```