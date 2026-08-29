#include <iostream>
#include <bits/stdc++.h> //STL

using namespace std;
int main(){
	
	set<int>s;
	
	s.insert(5);
	s.insert(3);
	s.insert(5);
	s.insert(1);
	s.insert(2);
	
	for(int x : s){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<"Size of Set: "<<s.size()<<endl;
	cout<<"Find 3: "<<(s.find(3) != s.end()? " Found" : "Not Found") << endl;
	s.erase(3);
	cout<<"Size after Erasing 3: "<<s.size()<<endl;
	
	return 0;
}
