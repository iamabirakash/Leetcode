class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        set<pair<int, int>> ob;
        for (auto& o : obstacles) {
            ob.insert({o[0], o[1]});
        }

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int d = 0;
        int x = 0, y = 0;
        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                d = (d + 1) % 4;
            } else if (cmd == -2) {
                d = (d + 3) % 4;
            } else {
                while (cmd--) {
                    int newX = x + dir[d].first;
                    int newY = y + dir[d].second;

                    if (ob.count({newX, newY})) break;

                    x = newX;
                    y = newY;
                    maxDist = max(maxDist, (x * x) + (y * y));
                }
            }
        }

        return maxDist;
    }
};