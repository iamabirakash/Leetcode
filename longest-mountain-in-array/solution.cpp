class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;
        
        int maxLength = 0, i = 0;
        bool uphill = false, downhill = false;
        
        while (i < n - 1) {
            if (arr[i] < arr[i + 1]) {
                int start = i;
                
                // Climb up (strictly increasing)
                while (i < n - 1 && arr[i] < arr[i + 1]) {
                    i++;
                    uphill = true;
                }
                
                // Climb down (strictly decreasing)
                while (i < n - 1 && arr[i] > arr[i + 1]) {
                    i++;
                    downhill = true;
                }
                
                // If both uphill and downhill happened, we found a mountain
                if (uphill && downhill) {
                    maxLength = max(maxLength, i - start + 1);
                }
                
                // Reset flags for next potential mountain
                uphill = false;
                downhill = false;
            } else {
                i++;
            }
        }
        return maxLength;
    }
};