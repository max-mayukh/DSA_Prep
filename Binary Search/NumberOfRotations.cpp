#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &nums){
    int n = nums.size();
        int low = 0, high = n -1;
        int mid, minElement = INT_MAX, index = 0;
        while(low<=high) {
            mid = (low + high) / 2;
            if(nums[low] <= nums[mid]){
                if(minElement > nums[low]) {
                    minElement = nums[low];
                    index = low;
                }
                low = mid + 1;
            }
            else{
                if(minElement > nums[mid]) {
                    minElement = nums[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }
        return index;   
}