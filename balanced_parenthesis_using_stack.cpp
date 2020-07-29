#include <iostream>
#include <cstring>
using namespace std;
#include <stack>

bool check(char*a){
    
    int i;
	stack<char> s;
    for( i=0;a[i]!='\0';i++){
    if(a[i]=='(' || a[i]=='['||a[i]=='{'){
        s.push(a[i]);
    }
    else if(a[i]==')'){
        if(s.empty()||s.top()!='('){
         return false;
        }
        s.pop();
        }
     else if(a[i]=='}'){
         if(s.empty()||s.top()!='{'){
         return false;
        }
        s.pop();
    }else if(a[i]==']'){
            if(s.empty()||s.top()!='['){
            return false;
        }
        s.pop();
        }    
    }
    return s.empty();
}
int main() {
    char a[1000];
    cin>>a;
  
   if(check(a))
   cout<<"Yes";
   else
   cout<<"No";
    return 0;
}
