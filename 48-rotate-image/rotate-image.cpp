class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int row=nums.size();
        int col=nums[0].size();

        // pehle transpose karte baad mai dekhege

        for(int i=0;i<row;i++){
            for(int j=i+1;j<col;j++){
                swap(nums[i][j],nums[j][i]);
            }
        }

        // ab reverse kar te ha har ek row ko matrix ke 

        for(int i=0;i<row;i++){
            int j=0;
            int k=row-1;

            while(j<k){
                swap(nums[i][j],nums[i][k]);
                j++;
                k--;
            }
       }
    }
};