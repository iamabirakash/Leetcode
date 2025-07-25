class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cnt = 0;
        while(target>startValue) {
            if(target % 2 == 0){
                target /= 2;
            } else {
                target++;
            }
            cnt++;
        }
        return cnt+(startValue-target);
        // if(target % startValue == 0) return (target/startValue);
        // int curr = startValue;
        // int cnt = 0;
        // while(curr!=target){
        //     if(curr*2>target){
        //         curr--;
        //         cnt++;
        //     }
        //     curr = curr*2;
        //     cnt++;
        // }
        // return cnt;
    }
};
