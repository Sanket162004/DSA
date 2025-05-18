class Solution {
public: 
        bool isvowel(char c){
            if(c=='a'|| c=='e'||c=='i'||c=='o'||c=='u'||c=='A'|| c=='E'||c=='I'||c=='O'||c=='U'){
                return true;
            }
            else {
                return false;
            }
        }

    string reverseVowels(string s) {
        int n=s.length();

        int start=0;
        int end=n-1;

        while(start<=end){
            while(start<end && !isvowel(s[start])){
                start++;
            }
            
            while(start<end && !isvowel(s[end])){
                end--;
            }

            swap(s[start],s[end]);
            start++;
            end--;
        }
        return s;
    }
};