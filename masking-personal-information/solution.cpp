class Solution {
public:
    string maskPII(string s) {
        // Email: contains '@'
        if (s.find('@') != string::npos) {
            // Lowercase everything
            for (char& c : s) c = tolower(c);
            int at = s.find('@');
            // first + ***** + last @ domain
            return s[0] + string("*****") + s[at - 1] + s.substr(at);
        }
        // Phone: extract digits only
        string digits;
        for (char c : s)
            if (isdigit(c)) digits += c;
        // Last 4 digits always shown
        string last4 = digits.substr(digits.size() - 4);
        int extra = digits.size() - 10; // country code digits (0, 1, 2, or 3)
        string local = "***-***-" + last4;
        if (extra == 0) return local;
        string countryCode(extra, '*');
        return "+" + countryCode + "-" + local;
    }
};