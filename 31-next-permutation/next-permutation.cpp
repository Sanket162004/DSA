class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();

        int pivot=-1;

        

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;

            }
        }

        if(pivot==-1){
             sort(nums.begin(),nums.end());
        }

        else{
            sort(nums.begin()+pivot+1,nums.end());
            // swap(nums[pivot],nums[pivot+1]);

            // find the right most greates element then swap it 

            for(int j=pivot+1;j<n;j++){
                if(nums[j]>nums[pivot]){
                    swap(nums[pivot],nums[j]);
                    break;
                }
            }

            




           // return nums;
        }

        


    }
};