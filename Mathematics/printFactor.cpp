#include <iostream>
#include <bits/stdc++.h> //STL

using namespace std;

void printFactor(int n){
	for(int i=1; i<=sqrt(n); i++){
		if(n%i==0){
			cout<<i<<" ";
		if(i!=n/i) cout<<n/i<<" ";
		}
	}
	cout<<endl; 
}

int main(){
	
	printFactor(24);
	printFactor(14);
	printFactor(20);
	
	return 0;
}
