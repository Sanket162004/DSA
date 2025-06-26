class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        vector<int>count(256,0);

        int first=0;
        int second=0;

        int len=0;

        while(second<n){
            
            
            while(count[s[second]]!=0){
                count[s[first]]=0;
                first++;
            }

            count[s[second]]=1;
            len=max(len,second-first+1);
            second++;
        }

        return len;

    }
};