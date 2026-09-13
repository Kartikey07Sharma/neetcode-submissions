class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt = 0;
        int n = people.size();
        int l = 0;
        int r = n-1;
        if(n == 0)return 0;
        sort(people.begin(), people.end());

        while(l <= r)
        {
            int sum = people[l] + people[r];
            if(sum > limit)
            {
                r--;
                cnt++;
            }        
            else{
                cnt++;
                l++;
                r--;
            }
        }
        return cnt;
    }
};