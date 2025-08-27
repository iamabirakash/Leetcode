class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();

        //step 1: find the max length of alternating diagonal of 0 and 2 
        vector<vector<int>> b1(n, vector<int>(m)); //diagonal from right-top to center
        vector<vector<int>> b2(n, vector<int>(m)); //diagonal from left-bottom to center
        vector<vector<int>> c1(n, vector<int>(m)); //diagonal from left-top to center
        vector<vector<int>> c2(n, vector<int>(m)); //diagonal from right-bottom to center
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] == 2){
                    int cnt = 0;
                    int k = i, l = j;
                    while(k>=0 && l<m && ((cnt%2 == 0 && a[k][l] == 2) || (cnt%2 == 1 && a[k][l] == 0))){
                        cnt++;
                        k--;
                        l++;
                    }
                    b1[i][j] = cnt;

                    cnt = 0;
                    k = i, l = j;
                    while(k<n && l>=0 && ((cnt%2 == 0 && a[k][l] == 2) || (cnt%2 == 1 && a[k][l] == 0))){
                        cnt++;
                        k++;
                        l--;
                    }
                    b2[i][j] = cnt;

                    cnt = 0;
                    k = i, l = j;
                    while(k>=0 && l>=0 && ((cnt%2 == 0 && a[k][l] == 2) || (cnt%2 == 1 && a[k][l] == 0))){
                        cnt++;
                        k--;
                        l--;
                    }
                    c1[i][j] = cnt;

                    cnt = 0;
                    k = i, l = j;
                    while(k<n && l<m && ((cnt%2 == 0 && a[k][l] == 2) || (cnt%2 == 1 && a[k][l] == 0))){
                        cnt++;
                        k++;
                        l++;
                    }
                    c2[i][j] = cnt;
                }
                else{
                    int cnt = 0;
                    int k = i, l = j;
                    while(k>=0 && l<m && ((cnt%2 == 0 && a[k][l] == 0) || (cnt%2 == 1 && a[k][l] == 2))){
                        cnt++;
                        k--;
                        l++;
                    }
                    b1[i][j] = cnt;

                    cnt = 0;
                    k = i, l = j;
                    while(k<n && l>=0 && ((cnt%2 == 0 && a[k][l] == 0) || (cnt%2 == 1 && a[k][l] == 2))){
                        cnt++;
                        k++;
                        l--;
                    }
                    b2[i][j] = cnt;

                    cnt = 0;
                    k = i, l = j;
                    while(k>=0 && l>=0 && ((cnt%2 == 0 && a[k][l] == 0) || (cnt%2 == 1 && a[k][l] == 2))){
                        cnt++;
                        k--;
                        l--;
                    }
                    c1[i][j] = cnt;

                    cnt = 0;
                    k = i, l = j;
                    while(k<n && l<m && ((cnt%2 == 0 && a[k][l] == 0) || (cnt%2 == 1 && a[k][l] == 2))){
                        cnt++;
                        k++;
                        l++;
                    }
                    c2[i][j] = cnt;
                }
            }
        }

        //step 2
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] == 1){
                    int cnt = 1;
                    int k = i, l = j;
                    while(k-1>=0 && l+1<m && ((cnt%2 == 1 && a[k-1][l+1] == 2) || (cnt%2 == 0 && a[k-1][l+1] == 0))){
                        ans = max(ans, cnt + c2[k-1][l+1]);
                        cnt++;
                        k--;
                        l++;
                    }
                    cnt = 1;
                    k = i, l = j;
                    while(k+1<n && l-1>=0 && ((cnt%2 == 1 && a[k+1][l-1] == 2) || (cnt%2 == 0 && a[k+1][l-1] == 0))){
                        ans = max(ans, cnt + c1[k+1][l-1]);
                        cnt++;
                        k++;
                        l--;
                    }

                    cnt = 1;
                    k = i, l = j;
                    while(k-1>=0 && l-1>=0 && ((cnt%2 == 1 && a[k-1][l-1] == 2) || (cnt%2 == 0 && a[k-1][l-1] == 0))){
                        ans = max(ans, cnt + b1[k-1][l-1]);
                        cnt++;
                        k--;
                        l--;
                    }

                    cnt = 1;
                    k = i, l = j;
                    while(k+1<n && l+1<m && ((cnt%2 == 1 && a[k+1][l+1] == 2) || (cnt%2 == 0 && a[k+1][l+1] == 0))){
                        ans = max(ans, cnt + b2[k+1][l+1]);
                        cnt++;
                        k++;
                        l++;
                    }
                    ans = max(ans, cnt);
                }
            }
        }

        return ans;
    }
};
