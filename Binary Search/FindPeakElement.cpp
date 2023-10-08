#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || nums[0] > nums[1]) return 0;   
        if(nums[n-1] > nums[n-2]) return n-1;
        int high = n - 2, low = 1, mid;
        while(low <= high) {
            mid = (low + high)/2;
            // peak element found
            if(nums[mid]>nums[mid-1] && nums[mid] > nums[mid+1]) 
                return mid;
            //peak element will be to the right of mid in this case
            else if (nums[mid] < nums[mid + 1]){
                low = mid + 1;
            }
            //peak element will be to the left of mid in this case
            else
                high = mid - 1;
        }
        return 0;
    }
};