class Solution {
public:

    int findDays(vector<int>& weights , int capacity)
    {
        
        int day = 1;
        int load = 0;
        for(int i=0; i<weights.size(); i++)
        {
            if(load + weights[i] > capacity)
            {
                day = day + 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return day;
    }
   
    int shipWithinDays(vector<int>& weights, int days) {
        int maxDay = INT_MIN;
        int sum = 0;
        int ans ;
        for(int i=0; i<weights.size(); i++)
        {
            maxDay = max(maxDay , weights[i]);
            sum += weights[i];
        }    
        int low = maxDay;
        int high = sum;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int d = findDays(weights , mid);
            if(d <= days)
            {
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};