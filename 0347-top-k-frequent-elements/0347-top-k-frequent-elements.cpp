class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int>freq;
         for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
         }
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
         for(auto it:freq){
            minHeap.push({it.second,it.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
         }

         vector<int> ans;
         while(!minHeap.empty()){
         ans.push_back(minHeap.top().second);
         minHeap.pop();
         }
         return ans;

    }
};