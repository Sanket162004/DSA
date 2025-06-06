class Solution {
public:
    int reverse(int x) {
        int rem=0;
        int ans=0;

        while(x){
            rem=x%10;
            
            if((ans<INT_MIN/10)||(ans>INT_MAX/10)){
                return 0;
            }
            ans=ans*10+rem;
            x=x/10;
        }
        return ans;
    }
};