#include<bits/stdc++.h>
using namespace std;

queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    stack<int> s;
    queue<int> dq;
    for(int i=0; i<k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        dq.push(s.top());
        s.pop();
    }
    while(!q.empty())
    {
        dq.push(q.front());
        q.pop();
    }
    return dq;
}


int main()
{
    return 0;
}