class Solution {
private:
    bool isInvalid(long long n) {
        for (int i = 2; i < 10; i++) {
            while (n % i == 0) {
                n /= i;
            }
        }
        return n != 1;
    }

    int minDigitsNeeded(long long t) {
        if (t <= 1) {
            return 0;
        }

        int count = 0;

        for (int d = 9; d >= 2; d--) {
            while (t % d == 0) {
                count++;
                t /= d;
            }
        }

        return count;
    }

    string getMore(long long t) {
        string sol = "";

        while (t != 1) {
            int curr = 9;

            while (curr > 1 && (t % curr != 0)) {
                curr--;
            }

            sol.push_back(char(curr + '0'));
            t /= curr;
        }

        reverse(sol.begin(), sol.end());
        return sol;
    }

    long long reduceT(long long t, int d) {
        for (int f = 9; f >= 2; f--) {
            while (d % f == 0 && t % f == 0) {
                t /= f;
                d /= f;
            }
        }

        return t;
    }

public:
    string smallestNumber(string num, long long t) {
        int n = num.size();

        if (isInvalid(t)) {
            return "-1";
        }

        int zeroIdx = -1;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                zeroIdx = i;
                break;
            }
        }

        if (zeroIdx == -1) {
            long long tempT = t;

            for (char c : num) {
                tempT = reduceT(tempT, c - '0');
            }

            if (tempT == 1) {
                return num;
            }
        }

        int maxPrefix = (zeroIdx == -1) ? n : zeroIdx;

        vector<long long> prefixT(n + 1, t);

        for (int i = 0; i < maxPrefix; i++) {
            prefixT[i + 1] = reduceT(prefixT[i], num[i] - '0');
        }

        for (int i = maxPrefix - 1; i >= 0; i--) {
            int remainingLen = n - 1 - i;
            int startDigit = (num[i] - '0') + 1;

            for (int d = startDigit; d <= 9; d++) {
                long long remT = reduceT(prefixT[i], d);

                if (minDigitsNeeded(remT) <= remainingLen) {
                    string sol = num.substr(0, i);
                    sol.push_back(char(d + '0'));

                    string suffix = getMore(remT);

                    while ((int)suffix.size() < remainingLen) {
                        suffix = "1" + suffix;
                    }

                    return sol + suffix;
                }
            }
        }

        int reqLen = max(n + 1, minDigitsNeeded(t));

        string sol = getMore(t);

        while ((int)sol.size() < reqLen) {
            sol = "1" + sol;
        }

        return sol;
    }
};