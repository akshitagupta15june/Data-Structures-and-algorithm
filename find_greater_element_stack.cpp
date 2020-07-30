#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,j,x;
	cin>>n;
	vector <int> v;
	for(i=0;i<n;++i){
		cin>>x;
		v.push_back(x);
	}
	int ans[n+2];
	stack <int> s;
	s.push(0);
	for(i=1;i<n;++i){
		while(!s.empty() && v[s.top()]<v[i]){
			ans[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}
 
	for(i=0;i<n;++i){
		while(!s.empty() && v[s.top()] < v[i]){
			ans[s.top()] = v[i];
			s.pop();
		}
	}
 
	while(!s.empty()){
		ans[s.top()] = -1;
		s.pop();
	}
 
    for(i=0;i<n;++i){
    	cout<<ans[i]<<" ";
    }
 
}
