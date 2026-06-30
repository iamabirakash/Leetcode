class Solution {
public:
    bool isCovered(vector<vector<int>>& intervals, int left, int right) {
        for(int num = left; num <= right; num++) {
            bool covered = false;
            for(auto& interval : intervals) {
                if(interval[0] <= num && num <= interval[1]) {
                    covered = true;
                    break;
                }
            }
            if(!covered) return false;
        }
        return true;
    }
};
// class Solution {
// public:
//     bool isCovered(vector<vector<int>>& arr, int left, int right) {
//         int n = arr.size();
//         bool leftCheck = false;
//         bool rightCheck = false;
//         for(int i=0;i<n;i++){
//             if(arr[i][0]<=left) leftCheck = true;
//             if(arr[i][1]>=right) {
//                 if(leftCheck) rightCheck = true;
//             }
//         }
//         if(leftCheck && rightCheck) return true;
//         return false;
//     }
// };