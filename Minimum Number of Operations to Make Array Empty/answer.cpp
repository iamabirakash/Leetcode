class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num : nums) freq[num]++;
        
        int operations = 0;
        for(auto& p : freq){
            int count = p.second;
            if(count == 1) return -1;
            if(count % 3 == 0) {
                operations += count / 3;
            } else if(count % 3 == 1) {
                if(count < 4) return -1;
                operations += (count / 3) - 1 + 2; 
            } else {
                operations += count / 3 + 1;
            }
        }
        return operations;
    }
};
