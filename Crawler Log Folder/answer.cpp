class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        string c = "../";
        for(string str : logs){
            if(str == c){
                cnt--;
            } else if(str == "./"){
                continue;
            } else {
                cnt++;
            }
        if(cnt<0 || cnt==0){
            cnt = 0;
        }
        }
        return cnt; 
    }
};
