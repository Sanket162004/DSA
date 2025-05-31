class Solution {
public:
    int maxProfit(vector<int>& arr) {


        int n=arr.size();
        if(n==1){
            return 0;
        }
        // tu right se check kartehue aa 
        int maxright=arr[n-1];
        int maxprofit=INT_MIN;
        for(int i=n-2;i>=0;i--){
            int curr=arr[i];
            maxright=max(maxright,curr);
            maxprofit=max(maxprofit,maxright-curr);

        }
        
        return maxprofit;

        
    }
};