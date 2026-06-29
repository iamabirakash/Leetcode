class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        int pop[101] = {0};

        for(auto &log : logs){
            pop[log[0] - 1950]++;
            pop[log[1] - 1950]--;
        }

        int maxPop = 0;
        int year = 1950;
        int curr = 0;

        for(int i = 0; i < 101; i++){
            curr += pop[i];

            if(curr > maxPop){
                maxPop = curr;
                year = 1950 + i;
            }
        }

        return year;
    }
};