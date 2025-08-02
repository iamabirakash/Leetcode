class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(int i=0;i<n;i++){
            mp1[basket1[i]]++;
            mp2[basket2[i]]++;
        }
        map<int,int> total;
        for(auto it : mp1) total[it.first] += it.second;
        for(auto it : mp2) total[it.first] += it.second;
        for(auto it : total) {
            if(it.second%2!=0) return -1;
        }
        vector<int> a,b;
        for(auto it : total){
            int diff = mp1[it.first]-(it.second/2);
            if(diff>0) a.insert(a.end(),diff,it.first);
            else if(diff<0) b.insert(b.end(),-diff,it.first);
        }
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        int all_min = min(*min_element(basket1.begin(),basket1.end()),*min_element(basket2.begin(),basket2.end()));
        long long ans = 0;
        for(int i=0;i<a.size();i++){
            ans += min((long long)min(a[i],b[i]),2LL*all_min);
        }
        return ans;
    }
};
