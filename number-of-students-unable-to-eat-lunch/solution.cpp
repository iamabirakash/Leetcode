class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int s : students) q.push(s);
        
        int i = 0; // index for sandwiches
        int attempts = 0;
        int n = students.size();
        
        while(!q.empty() && attempts < q.size()) {
            if(q.front() == sandwiches[i]) {
                q.pop();
                i++;
                attempts = 0; // reset attempts when a sandwich is taken
            } else {
                int student = q.front();
                q.pop();
                q.push(student);
                attempts++;
            }
        }
        
        return q.size(); // students who couldn't get a sandwich
    }
};