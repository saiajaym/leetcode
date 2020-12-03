/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 
 
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        int mx=INT_MIN,i=0;
        vector<int> ans;
        for(i=0;i<k;i++){
            
            //remove elements smaller than the current on left 
            while(!d.empty() && nums[d.back()]<=nums[i]) d.pop_back();
            d.push_back(i);
        }
        ans.push_back(nums[d.front()]);
        
        for(;i<nums.size();i++){
            //remove elements not in window
            while(!d.empty() && d.front()<=i-k) d.pop_front();
            
            //remove elemnts smaller than the current on left
            while(!d.empty() && nums[d.back()]<=nums[i]) d.pop_back();
            
            //add the current element and store answer
            d.push_back(i);
            ans.push_back(nums[d.front()]);
            
        }
        
        
        return ans;
        
        
        
    }
};
