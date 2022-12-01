```cpp
//For integer l r
ll lo = , hi = ;
while(hi-lo > 3){
    ll m1 = lo + ((hi-lo)/3);
    ll m2 = hi - ((hi-lo)/3);
    
    //depend on what kind of function it is
    if (compute(m1) > compute(m2)) {
        lo = m1; 
    }else{
        hi = m2;
    }
}

for(ll i{lo}; i <= hi; i++){
	//test the value
}


//For floating point l r
double lo = , hi = ;
while (hi-lo > eps) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double f1 = f(m1);      
    double f2 = f(m2);      
    if (f1 < f2)
        l = m1;
    else
        r = m2;
}
return f(l);           

//OR use a for loop to run certain amount of iteration, just like real number binary search!
```