class Solution {
public:
    bool halvesAreAlike(string s) {
        string a="";
        string b="";

        int n=s.length();

        

        int count1=0;
        int count2=0;

        for(int i=0;i<n/2;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                count1++;
            }
        }
        for(int j=n/2;j<n;j++){
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U'){
                count2++;
            }
        }

        if(count1==count2){
            return true;
        }

        return false;
    }
};