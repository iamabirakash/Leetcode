class Solution {
public:
    string sortVowels(string s) {
        string temp="";
        for(auto it:s){
            if(it=='a'||it=='e'||it=='i'||it=='o'||it=='u'||it=='A'||it=='E'||it=='I'||it=='O'||it=='U')
            temp+=it;
        }
        if(temp.empty())return s;
        sort(temp.begin(),temp.end());
        int a =0;
        // cout<<temp;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
                s[i]=temp[a];
                a++;
            }
        }
        return s;      
    }
};
