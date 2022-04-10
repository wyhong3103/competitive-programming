#include <bits/stdc++.h>
#include <limits>
#define all(x) begin(x),end(x)
#define fir first
#define sec second
#define sz(x) x.size()

using namespace std;
using vi = vector<int>;
using ll = long long;

void setIO(string s){
	freopen((s + ".in").c_str(),"r",stdin);
	freopen((s + ".out").c_str(),"w",stdout);
	}

long long C[50][1000] = {0};
//generating a pascal's triangle

void build_pascal(){
    for(int i{}; i < 50; i++){
        for(int j{}; j < 1000; j++){
            if (i == 0){
                C[i][j] = 1;
                break;
            }else{
                C[i][j] = (j == 0 ? 1 : (C[i-1][j] + C[i-1][j-1]));
            }
        }
    }
}

void solve(){
    build_pascal();
    for(int i{}; i < 50; i++){
        for(int j{}; j < 1000; j++){
            if (C[i][j] == 0) break;
            cout << C[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}

