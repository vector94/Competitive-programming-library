class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > result;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 0; i < intervals.size(); i++){
            if (intervals[i][0] <= right){
                right = max(right, intervals[i][1]);
            }
            else{
                result.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        result.push_back({left, right});
        return result;
    }
};
