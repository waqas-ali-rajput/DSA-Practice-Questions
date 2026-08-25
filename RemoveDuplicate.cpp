#include <iostream>
#include <bits/stdc++.h> //STL

using namespace std;
int main(){
	
	vector<int>nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	
	int n = nums.size();
	int i = 0;
	
	for(int j=1; j<n; j++){
		
		if(nums[i] != nums[j]){
			i++;
			
			nums[i]=nums[j];
		}
	}
	
	int k = i + 1;
	
	cout<<"Number of unique elements: "<<k<<endl;	
	cout<<"Array after removing duplicates: "<<endl;	
	
	for(int j=0; j<k; j++){
		
		cout<<nums[j]<<" "<<endl;
	}
	
	return 0;
}