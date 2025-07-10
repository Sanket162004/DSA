class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        vector<int>leftmax(n);
        vector<int>rightmax(n);

        leftmax[0]=0;

        for(int i=1;i<n;i++){
            leftmax[i]= max(leftmax[i-1],height[i-1]);
        }

        rightmax[n-1]=0;

        for(int i=n-2;i>=0;i--){
            rightmax[i]=max(rightmax[i+1],height[i+1]);
        }

        // leftmax and rightmax mai se minimum lege or usko axcctual height mai se minus karege

        int water=0;

        for(int i=0;i<n;i++){
            int miniheight=min(leftmax[i],rightmax[i]);

            if(miniheight-height[i]>=0){
                water=water+miniheight-height[i];
            }
        }

        return water;
    }
};