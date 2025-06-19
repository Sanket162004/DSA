class Solution {
public:
    string largestOddNumber(string s) {
        // kohi bhi odd number ka 0th place 1 3 5 7 9 ho sakta hai confrim
        int n=s.size();

        for(int j=n-1;j>=0;j--){
            if(s[j]=='1' || s[j]=='3'||s[j]=='5'||s[j]=='7'||s[j]=='9'){
                return s.substr(0,j+1);
            }
          
        } 

        return "";
    }
};