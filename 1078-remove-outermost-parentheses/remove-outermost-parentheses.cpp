class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int start=0;
        stack<char>st;

        for(int i=0;i<s.length();i++){
            
                if(s[i]=='('){
                    st.push(s[i]);
                }
                else{
                    st.pop();

                    
                }

                if(st.empty()==1){
                    ans=ans+s.substr(start+1,i-start-1);
                    start=i+1;
                }

                
            
               
        }

        return ans;
    }
};