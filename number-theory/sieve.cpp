// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int prime[300000], nPrime;
// int if prime 0, not prime 1
int mark[1000002];

void sieve(int n){
    int i, j, limit = sqrt(n*1)+2;
    
    // 1 is not prime. you can also mark 0
    mark[1] = 1;
    // almost the evens are not prime
    for(int i = 4; i<=n; i += 2) mark[i] = 1;
    prime[nPrime++] = 2;
    
    // run loop for only odds
    for(int i=3; i<=n; i += 2){
        // if not prime, no need to do "multiple cutting"
        if(!mark[i]){
            // i is prime
            prime[nPrime++]=i;
            
            // if we don't do it, following 
            // i*i may overflow
            if(i <=limit ){
                // loop through all odd multiples of i
                // greater than i * i
                for(int j = i*i; j<=n; j += i*2){
                    // mark j not prime
                    mark[j] = 1;
                }
            }
        }
    }
}

int main() {
    
    int n;
    cin>>n;
    sieve(n);
    
    for(int i=0; i<=n; i++){
        if(mark[i]==0) cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}