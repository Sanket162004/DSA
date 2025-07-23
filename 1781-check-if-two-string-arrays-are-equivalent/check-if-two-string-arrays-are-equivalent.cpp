class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string one="";
        string two="";

        for(int i=0;i<word1.size();i++){
            one=one+word1[i];
        }
        for(int i=0;i<word2.size();i++){
            two=two+word2[i];
        }

        if(one.length()<two.length()||two.length()<one.length()){
            return false;
        }

        // same length then also it is not equ
        

        if(one==two){
            return true;
        }

        return false;
    }
};