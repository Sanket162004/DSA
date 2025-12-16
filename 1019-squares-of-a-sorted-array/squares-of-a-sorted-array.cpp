class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;

        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]*nums[i]);
            }
            else{
                pos.push_back(nums[i]*nums[i]);
            }
        }

        reverse(neg.begin(),neg.end());

        int posp=0;
        int negp=0;

        int i=0;

        while(posp<pos.size() && negp<neg.size()){
            if(pos[posp]<=neg[negp]){
                nums[i]=pos[posp];
                posp++;
                i++;
            }
            else{
                nums[i]=neg[negp];
                negp++;
                i++;
            }
        }

        while(posp<pos.size()){
             nums[i]=pos[posp];
                posp++;
                i++;
        }
        while(negp<neg.size()){
             nums[i]=neg[negp];
                negp++;
                i++;
        }


        return nums;
    }
};