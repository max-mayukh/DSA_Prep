#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n -1;
        int mid, target = nums[0], minElement = 5001;
        while(low<=high) {
            mid = (low + high) / 2;
            if(nums[low] <= nums[mid]){
                minElement = min(nums[low], minElement);
                low = mid + 1;
            }
            else{
                minElement = min(nums[mid], minElement);
                high = mid - 1;
            }
        }
        return minElement;
    }
};