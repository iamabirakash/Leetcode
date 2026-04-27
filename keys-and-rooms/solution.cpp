class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_map<int, bool> mp;
        mp[0] = true;   // start from room 0
        bool changed = true;
        while(changed) {
            changed = false;
            for(int i = 0; i < n; i++) {
                if(mp[i]) {  // if room is visited
                    for(int key : rooms[i]) {
                        if(!mp[key]) {
                            mp[key] = true;
                            changed = true;  // new room discovered
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(!mp[i]) return false;
        }
        return true;
    }
};
