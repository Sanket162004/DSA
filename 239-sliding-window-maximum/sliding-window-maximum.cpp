class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            // This while loop is to remove the index which are not part of our window so this we will remove all the indices which are smaller then our first index in the window(i.e i-k)
            while(!dq.empty() and dq.front()<=i-k){
                dq.pop_front();
            }
            // This while loop is to remove smaller element then our current index as from the front we have larger value index so we will remove element from the back and at the start we will always have our maximum value index.
            while(!dq.empty() and nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            // now we will push back our current index
            dq.push_back(i);
            // This if condition this for that when we cross our required window size after that we start storing our max val ans in the answer vector.
            if(i+1>=k){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};