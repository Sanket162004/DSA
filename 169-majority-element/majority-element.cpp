#include<bits/stdc++.h>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
      
        
        unordered_map<int ,int>m;

        for(int i=0;i<n;i++){
            if(m.find(nums[i])!=m.end()){
                // if we get just increase the cont ;
                m[nums[i]]++;
            }

            //aagar nahi mila toh dal do map ke aandar 

            else{
                m[nums[i]]=1;
            }
        }




    
       // and jis ka count sab se jada rahewga usko re turn kar dena ;

       for(auto it:m){
        if(it.second>n/2){
            return it.first;
        }
       }
       return -1;
    }
};