// Sieve of Eratosthenes to find primes
#include <iostream>
#include <string>
#include<vector>
using namespace std;
int main()
{
  vector<int> primes(101,0);
  
  int n = 100;
  
  for(int i = 2; i <= 10; i++){
    if(primes[i] == 0){
        for(int j = 2; j <= n/i; j++){
            primes[j*i] = 1;
        }
    }
  }
  
  for(int i = 1; i < primes.size(); i++){
    if(primes[i] == 0){
        cout<<i<<endl;
    }
  }
}
