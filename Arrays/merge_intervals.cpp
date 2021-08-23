// Merge Overlappping Intervals

#include <bits/stdc++.h>
using namespace std;

// Function Declaration
vector<vector<int>> merge(vector<vector<int>> &intervals); 

// Main Function
int main(){
    int n;
    cin >> n;

    vector<vector<int>> givenIntervals;
    
    for(int i=0;i<n;i++){
        vector<int> interval;
        int a,b;
        cin >> a >> b;

        interval.push_back(a);
        interval.push_back(b);
        
        givenIntervals.push_back(interval);
    }
    
    vector<vector<int>> finalIntervals = merge(givenIntervals);

    for(int i=0;i<finalIntervals.size();i++){
            cout << "[" << finalIntervals[i][0] << "," << finalIntervals[i][1] << "] ";
    }

    return 0;
}

// Using sort and traversal approach -> Time Complexity - O(nlogn), Space Complexity - O(n)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
    vector<vector<int>> mergedIntervals;
        
    if(intervals.size() == 0){
        return mergedIntervals;
    }
        
    sort(intervals.begin(),intervals.end());
    
    vector<int> tempInterval = intervals.front();
        
    for(auto it : intervals){
        if(it[0] <= tempInterval[1]){
            tempInterval[1] = max(it[1],tempInterval[1]);
        }else{
            mergedIntervals.push_back(tempInterval);
            tempInterval = it;
        }
    }
    mergedIntervals.push_back(tempInterval);
        
    return mergedIntervals;
}