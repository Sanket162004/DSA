class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char,int>first;
        unordered_map<char,int>second;

        int n=s.length();

        for(int i=0;i<n;i++){

            if(first.find(s[i])==first.end()){
                first[s[i]]=i;
            }
            if(second.find(t[i])==second.end()){
                second[t[i]]=i;
            }

            if(first[s[i]]!=second[t[i]]){
                return  false;
            }
        }

        return true;

        
    }
};