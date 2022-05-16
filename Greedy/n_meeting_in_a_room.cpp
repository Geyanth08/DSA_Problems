// GeeksForGeeks Link - https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// Maximum number of meeting that can be accommodated in the meeting room

#include <bits/stdc++.h>
using namespace std;

// Sorting according to End time -> Time Complexity - O(NlogN), Space Complexity - O(N)
class Solution
{
public:
    int maxMeetings(int start[], int end[], int n)
    {
        int count_meeting = 1, end_limit = 0;
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back(make_pair(end[i], start[i]));
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            if (v[end_limit].first < v[i].second)
            {
                end_limit = i;
                count_meeting++;
            }
        }

        return count_meeting;
    }
};