#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || nums[0]!= nums[1]) return nums[0];
        if(nums[n-2] != nums[n-1]) return nums[n-1];
        int high = n-2, low = 1, mid;
        while(low <= high) {
            mid = (low+high)/2;
            // element is found only when next element and previous element is not same
            if(nums[mid] != nums[mid-1] && nums[mid]!= nums[mid + 1]) 
                return nums[mid];
            // this is the case when mid is the 1st element of pair of duplicates
            else if(nums[mid] == nums[mid+1]){
                // if odd index
                if(mid % 2 == 1) 
                    high = mid - 1;
                else
                    low = mid + 1;
                }
            // this is the case when mid is the 2nd element of pair of duplicates
            else if(nums[mid] == nums[mid - 1]){
                // if odd index
                if(mid % 2 == 1)
                    low = mid + 1;
                else
                    high = mid - 1;
            }      
            
        }
        return 0;
    }
};