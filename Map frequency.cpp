#include <iostream>
#include<map>
#include <bits/stdc++.h> //STL

using namespace std;
int main(){
	
  	int arr[] = {3,5,7,2,7,1,6,9,2,3,4,3};
  	int n = sizeof(arr)/sizeof(arr[0]);
//  	unordered_map<int,int> freq;
		map<int,int> freq;  	
  	for(int i=0; i<n; i++){
  		freq[arr[i]]++;
	  }
	
	for(auto it : freq){
		cout<<it.first<<" "<<it.second<<endl;
		
	}
	return 0;
}