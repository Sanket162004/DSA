class Solution {
public:
    vector<vector<int>> generate(int n) {
        

        vector<vector<int>>ans(n);

        for(int i=0;i<n;i++){
            vector<int>temp(i+1,1);

            for(int j=1;j<i;j++){
                int add=ans[i-1][j]+ans[i-1][j-1];
                temp[j]=add;
            }

            ans[i]=temp;
            temp.clear();
        }


        return ans;
    }
};