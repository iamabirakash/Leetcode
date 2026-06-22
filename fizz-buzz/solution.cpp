class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int it=1;it<=n;it++){
            string s = to_string(it);
            if(it%3==0 && it%5==0) res.push_back("FizzBuzz");
            else if(it%3==0) res.push_back("Fizz");
            else if(it%5==0) res.push_back("Buzz");
            else res.push_back(s);
        }
        return res;
    }
};