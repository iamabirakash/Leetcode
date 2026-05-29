class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int i = 0;
        int sum = 0;
        int cnt = 0;
        for(i=0;i<k;i++){
            sum += arr[i];
        }
        int avg = sum/k;
        if(avg>=threshold) cnt++;
        while(i<n){
            sum += arr[i];
            sum -= arr[i-k];
            avg = sum/k;
            if(avg>=threshold) cnt++;
            i++;
        }
        return cnt;
    }
};