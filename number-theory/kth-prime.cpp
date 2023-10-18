#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool prime[90000001];
int n=90000000;
vector<int> v;

void sieve(){
    int limit = sqrt(n*1)+2;
    // run loop for only even
    for(int i=4; i<=n; i += 2) prime[i] = true;
    
    // run loop for only odds
    for(int i=3; i<=n; i += 2){
        // if not prime, no need to do "multiple cutting"
        if(!prime[i]){
            if(i <=limit ){
                // loop through all odd multiples of i
                // greater than i * i
                for(int j = i*i; j<=n; j += i*2){
                    // mark j not prime
                    prime[j] = true;
                }
            }
        }
    }
    
    for(int i=2; i<=n; i++){
        if(!prime[i]) v.push_back(i);
    }
}


int main() {
   
   sieve();
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      cout<<v[n-1]<<endl;
  }
    return 0;
}