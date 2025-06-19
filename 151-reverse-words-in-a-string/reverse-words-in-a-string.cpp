class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s); // ye aapan ko string thod thod ke de ga words mai

        string token="";

        string result="";

        while(ss>>token){
            result=token+" "+result;
        }

        result.pop_back();

        return result;
    }
};