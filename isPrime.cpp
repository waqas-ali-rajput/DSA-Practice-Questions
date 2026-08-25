#include <iostream>
#include <bits/stdc++.h> //STL

bool isPrime(int n){
	if (n<2) return false;
	
	for(int i=2; i<n; i++){
		if(n%i==0) return false;
	}
	return true;
}

using namespace std;
int main(){
	
	cout<<isPrime(17)<<endl;
	cout<<isPrime(170)<<endl;
	cout<<isPrime(9)<<endl;
	
	return 0;
}