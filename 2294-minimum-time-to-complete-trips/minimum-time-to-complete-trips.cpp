class Solution {
public:
    bool possible(vector<int>&time,int &totalTrips,long long givenTime){
        long long actualTripsCount=0;

        for(int &t:time){
            actualTripsCount+=(givenTime/t);
        }
        return actualTripsCount>=totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1;
        // Right Bound => Fastest Bus Complete All Trips
        long long r=(long long) *min_element(begin(time),end(time))*totalTrips;

        while(l<r){
            long long mid=l+(r-l)/2;

            if(possible(time,totalTrips,mid)){
                r=mid;
            } else{
                l=mid+1;
            }
        }
        return l;
    }
};