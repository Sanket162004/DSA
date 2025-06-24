class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        string s = "";
        for(int i=0;i<words.size();i++){
            string ss=s;
            ss+=words[i];
            if(ss.length()>maxWidth){
                res.push_back(s);
                s=words[i];
            }else{
                s=ss;
            }
            s+=' ';
        }
        res.push_back(s);

        for(int i=0;i<res.size();i++){
            vector<string> vec;
            string ss="";
            int len=0;
            string final="";
            for(int j=0;j<res[i].length();j++){
                if(res[i][j]==' ' && ss.length()>0){
                    vec.push_back(ss);
                    ss="";
                }else if(res[i][j]!=' '){
                    ss+=res[i][j];
                    len++;
                }
            }
            
            int space=maxWidth-len;
            if(i==res.size()-1){
                for(int k=0;k<vec.size()-1;k++){
                    final+=vec[k];
                    final+= ' ';
                    space--;
                }
                final+=vec[vec.size()-1];
                while(final.length()< maxWidth){
                    final+=' ';
                }
                res[res.size()-1]=final;
                continue;
            }
            if(vec.size()==1){
                final += vec[0];
                int k=0;
                while(k<space){
                    final+=' ';
                    k++;
                }
                res[i]=final;
            }else if(vec.size()==2){
                final = vec[0];
                int k=0;
                while(k<space){
                    final+=' ';
                    k++;
                }
                final += vec[1];
                res[i]=final;
            }else{
                vector<int> division;
                int lastspace = space%(vec.size()-1);
                space= space/(vec.size()-1);
                for(int k=0;k<vec.size()-1;k++) {
                    division.push_back(space);
                }
                for(int k=0;k<lastspace;k++){
                    division[k]++;
                }
                for(int k=0;k<vec.size()-1;k++){
                    final += vec[k];
                    int l=0;
                    while(l<division[k]){
                        final+=' ';
                        l++;
                    }
                }
                final += vec[vec.size()-1];
                res[i]=final;
            }
        }
        return res;
    }
};