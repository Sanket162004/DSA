class Solution {
public:
   
    int bs(vector<int>& nums,int start,int end,int target){
        
       while(start<=end){
          int mid=start+(end-start)/2;
          if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]>target){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
      }
      return -1;
        
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int l=0;

        int r=n-1;

        while(l<r){
            int mid=l+(r-l)/2;

            
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }

        int pivote=r;



        int first_half=bs(nums,0,pivote-1,target);
        int second_half=bs(nums,pivote,n-1,target);


        if(first_half!=-1){
            return first_half;
        }
        else{
            return second_half;
        }
            


    }
};