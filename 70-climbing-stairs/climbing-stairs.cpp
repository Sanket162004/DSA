// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n == 0 || n == 1) {
//             return 1;
//         }
//         return climbStairs(n-1) + climbStairs(n-2);
//     }
// };


// we wil solve it by the for loop and dp

class Solution {
public:
    int climbStairs(int n) {
        if(n==1|n==0){
            return 1;
        }
        int prev=1;
        int curr=1;
    
        for(int i=2;i<=n;i++){
           int temp= curr;
           curr=prev +temp;
           prev=temp;
        }
        return curr;
    }
};