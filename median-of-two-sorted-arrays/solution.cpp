class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        vector<int> result(length1 + length2);
        
        for (int i = 0; i < length1; i++) {
            result[i] = nums1[i];
        }
        for (int i = 0; i < length2; i++) {
            result[length1 + i] = nums2[i];
        }
        
        sort(result.begin(), result.end());
        
        int start = 0;
        int end = result.size();
        int mid = start + (end - start) / 2;
        
        if (result.size() % 2 == 0) {
            double ans = (result[mid] + result[mid - 1]) / 2.0;
            return ans;
        }
        return result[mid];
    }
};