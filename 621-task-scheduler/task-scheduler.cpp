class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto &ch : tasks){
            freq[ch-'A']++;
        }
        priority_queue<int> pq;
        for(auto &val : freq){
            if(val)pq.push(val);
        }

        int time = 0;
        int rem = accumulate(freq.begin(), freq.end(), 0);

        map<int,vector<int>> mp;
        while(!pq.empty() || !mp.empty()){

            if(!pq.empty()){
                auto tp = pq.top();
                pq.pop();
                rem-=tp;
                // tp-1 after n unit time
                if(tp-1)
                    mp[time+n].push_back(tp-1);
            
            }

            for(auto &val : mp[time]){
                pq.push(val);
                rem += val;
            }
            mp.erase(time);
            // cout<<time<<" "<<rem<<endl;   
            time++;
        }
        return time;

    }
};