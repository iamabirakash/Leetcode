class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int start = 0;
        int end = n-1;
        int cnt = 0;
        while(start<=end){
            if(people[end]==limit){
                end--;
                cnt++;
            } else {
                int s = people[start]+people[end];
                if(s<=limit){
                    start++;
                    end--;
                } else {
                    end--;
                }
                cnt++;
            }
        }
        return cnt;
    }
};
