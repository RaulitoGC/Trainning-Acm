/***************************************************************
Algorithm: Classic Sieve of Eratostenes
Type: Sieve of Eratostenes
Author: Raul Guzman
Time Complexity : (n)LogLog(n)
Space Complexity : O(n) using array / O(n/8) using bitset
Description : Marks all the numbers if it is prime or not [0 - upperbound]
****************************************************************/

#include <bits/stdc++.h>
using namespace std;

/******************* Tourist's Template for Debugging **********/
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for(const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

/****************************************************************/
 
bitset<100> bs;
vector<int> primes; 
long long _sieve_size;

void sieve(long long upperbound){

	_sieve_size =  upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i <= _sieve_size; i++){
		if(bs[i]){
			for (long long j = i*i; j <= _sieve_size; j+=i)
				bs[j] = 0;
			
			primes.push_back((int)i);
		}
	}
}


int main (){

	sieve(100);
	int n;
	debug(bs);
	debug(primes);
 	return 0;
 }