//CodeStudio code
#include<bits/stdc++.h>
int maximumMeetings(vector<int>& start, vector<int>& end) {
    vector<pair<int, int>> meetings;
    for(int i = 0; i < start.size(); i++) meetings.push_back(make_pair(end[i], start[i]));
    sort(meetings.begin(), meetings.end());
    int count = 0, currentEnd = -1;
    for(int i = 0; i < meetings.size(); i++) {
        if(meetings[i].second > currentEnd) {
            count++;
            currentEnd = meetings[i].first;
        }
    }
    return count;
}
