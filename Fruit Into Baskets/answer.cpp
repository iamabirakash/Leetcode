class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int l=0,r=0;
        int k =2;
        int n = fruits.size();
        int maxlen = 0;
        while(r<n){
            mp[fruits[r]]++;
            if(mp.size()>k){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size()<=k){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;

        // while(r<n){
        //     mp[fruits[r]]++;
        //     while(mp.size()>2){
        //         mp[fruits[l]]--;
        //         if(mp[fruits[l]]==0){
        //             mp.erase(fruits[l]);
        //         }
        //         l++;
        //     }
        //     if(mp.size()<=2){
        //         maxlen = max(maxlen,r-l+1);
        //     }
        //     r++;
        // }
        // return maxlen;
    }
};
