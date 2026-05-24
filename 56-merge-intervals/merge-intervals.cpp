class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // int n = intervals.size();

        // sort(intervals.begin(), intervals.end());

        // vector<vector<int>> ans;

        // for(int i = 0; i < n; i++) {

        //     int start = intervals[i][0];
        //     int end = intervals[i][1];

        //     // already merged
        //     if(!ans.empty() && end <= ans.back()[1]) {
        //         continue;
        //     }

        //     for(int j = i + 1; j < n; j++) {

        //         // overlapping
        //         if(intervals[j][0] <= end) {
        //             end = max(end, intervals[j][1]);
        //         }
        //         else {
        //             break;
        //         }
        //     }

        //     ans.push_back({start, end});
        // }

        // return ans;

        
        // sort intervals based on starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i = 0; i < intervals.size(); i++) {

            // if ans empty OR no overlap
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {

                ans.push_back(intervals[i]);
            }
            else {

                // merge overlapping intervals
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;

    }
};