class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n =nums.size();
        unordered_map<int,int> mp;
        int result =0;
        int currSum=0;
        mp[0]=1;
        for(int &num:nums){
            currSum+=num;

            int remSum = currSum -goal;
            if(mp.find(remSum)!=mp.end()){
            result+=mp[remSum];
              }
              mp[currSum]++;
        }
        return result;
        
    }
};