#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    vector<vector<int>> ans;
        if(intervals.size() == 0)
        {
            return ans;
        }

        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];

        for(auto it:intervals)
        {
            if(it[0] <= temp[1])
            {
                temp[1] = max(it[1], temp[1]);  // comparing the second number of current interval with the first number of previous interval
            }
            else
            {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
}

int main(){
    vector<vector<int>> v{
        {1,3},{2,4},{2,6},{8,9},{8,10},{8,11},{15,18},{16,17}
    };
    vector<vector<int>> ans = mergeIntervals(v);
    return 0;
}