#include <iostream>
#include <bits/stdc++.h> //STL

using namespace std;

	
	class Solution {
public:
    bool isPowerOfTwo(int n) {
    	if (n<=0){
    		return false;
		}
        while(n%2==0){
            n/=2;
        }

        return n==1;
    }
};
	
int main(){
	
	Solution s;
	
	cout<<s.isPowerOfTwo(20)<<endl;
	cout<<s.isPowerOfTwo(-32)<<endl;
	
	return 0;
}
