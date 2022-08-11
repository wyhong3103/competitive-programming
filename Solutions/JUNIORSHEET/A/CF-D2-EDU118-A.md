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
        int x1,p1;
        int x2,p2;
        cin >> x1 >> p1;
        cin >> x2 >> p2;
        
        string n1, n2;
        n1 = to_string(x1);
        n2 = to_string(x2);

        ll l1{}, l2{};

        l1 += n1.length();
        l2 += n2.length();
        
        if (l1 + p1 > l2 + p2){
            cout << '>' << '\n';
        }else if (l1 + p1 < l2 + p2){
            cout << '<' << '\n';
        }else{
            while (n1.length() != n2.length()){
                if (n1.length() > n2.length()) {
                    n2 += "0";
                }else{
                    n1 += "0";
                }
            }
            int win{0};
            for(int i{}; i < n1.length(); i++){
                if (n1[i] > n2[i]){
                    win = 1;
                    break;
                }else if (n2[i] > n1[i]){
                    win = 2; 
                    break;
                }
            }
            
            if (win == 0){
                cout << '=';
            }else if (win == 1){
                cout << '>';
            }else{
                cout << '<';
            }
            cout << '\n';

        }
        
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}


```