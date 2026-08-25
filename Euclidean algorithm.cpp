#include <iostream>
#include <bits/stdc++.h> //STL

using namespace std;

int GCD(int a, int b){
	//base case
	if(b==0) return a;
	// recursive case
	return GCD(b,a%b);
}

int LCM(int a, int b){
	return (a*b)/GCD(b, a%b);
}
int main(){
	
	cout<<GCD(12,20)<<" ";
	cout<<LCM(12,20);
	
	return 0;
}