#include <iostream>
#include<queue>
using namespace std;
int main(int argc, char **argv)
{
	queue<char> q;
    int freq[27]={0};
    char ch;
    cin>>ch;
    while(ch!='.')
    {
        q.push(ch);
        freq[ch-'a']++;
        while(!q.empty())
        {
            int idx=q.front()-'a';
            if(freq[idx]>1)
            {
                q.pop();
            }
            else
            {
                cout<<q.front()<<endl;
                break;
            }
        }
        if(q.empty())
        {
            cout<<"-1"<<endl;
        }
        cin>>ch;
    }
	return 0;
}
