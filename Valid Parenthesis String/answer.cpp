class Solution {
public:
    bool checkValidString(string s) {

        //optimal approach - using 2 var/range
        //tc = O(N) sc = O(1)
        int min = 0; //min = The smallest number of open ( we could have, if we treat * as ) wherever possible.
        int max = 0; // maximum number of '(' that *could* still be open [The largest number of open ( we could have, if we treat * as ( wherever possible ]
        int n = s.size();
        if(s[0] == ')') return false;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){ 
                min++;
                max++;
            }
            else if( s[i] == ')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(min < 0) min = 0;
            if(max < 0) return false;
        }
        return (min == 0);
    }
};
