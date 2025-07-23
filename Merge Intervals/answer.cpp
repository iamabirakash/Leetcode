class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> mergeSorted();
        mergeSorted[0] = intervals[0];
        int idx = 0;
        for(int i=0;i<intervals.size()-1;i++){
            if(mergeSorted[idx][1]<=intervals[i][0]){
                mergeSorted[idx][1] = max(mergeSorted[idx][1],intervals[i][1]);
            } else {
                mergeSorted.push_back(intervals[i]);
                idx++;
            }
        }
        return mergeSorted;
    }
};
