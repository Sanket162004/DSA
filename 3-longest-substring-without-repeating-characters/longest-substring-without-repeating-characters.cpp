class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        // brute force approch o(n2)
        // int maxlength=0;

        // for(int i=0;i<n;i++){
        //     unordered_set<char>chars;
        //     for(int j=i;j<n;j++){
        //         if(chars.find(s[j])!=chars.end()){
        //             break;
        //         }
        //         chars.insert(s[j]);

        //         maxlength=max(maxlength,j-i+1);
        //     }
        // }

        // siliding window

        vector<bool>count(256,0);
        int first=0;
        int second=0;
        int maxlen=0;

        while(second< s.size()){

            while(count[s[second]]){ // remove repeating char
                count[s[first]]=0;
                first++;

            }
            count[s[second]]=1;
            maxlen=max(maxlen,second-first+1);
            second++;
        }


        return maxlen;
    }
};