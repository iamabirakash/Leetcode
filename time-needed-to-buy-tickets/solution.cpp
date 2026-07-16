class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n  = tickets.size(), time = 0;
        int count = 0;
        queue<int> q;
        for(int i=0;i<n;i++) q.push(i);
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            tickets[idx]--;
            time++;
            if(idx==k && tickets[idx]==0) return time;
            if(tickets[idx]>0) q.push(idx);
        }
        return time;
    }
};