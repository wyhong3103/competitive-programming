```cpp

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

long long ncr(ll n, ll r){
    ll nom = 1;
    for(int i{n-r+1}; i <= n; i++) nom *= i;

    ll denom = 1;
    for(int i{1}; i <= r; i++){
        if (nom % i == 0) nom /= i;
        else denom *= i;
    }
    return nom / denom;
}

```
