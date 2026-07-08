class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;

        int prevTime = 0;

        for (string &log : logs) {
            vector<string> parts;
            stringstream ss(log);
            string token;

            while (getline(ss, token, ':'))
                parts.push_back(token);

            int id = stoi(parts[0]);
            string type = parts[1];
            int time = stoi(parts[2]);

            if (type == "start") {
                if (!st.empty())
                    ans[st.top()] += time - prevTime;

                st.push(id);
                prevTime = time;
            } else {
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }

        return ans;
    }
};