#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <climits>

using namespace std;

#define ll long long

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target) return i;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right + 1)/2;

            if(nums[mid] > nums[left]){
                left = mid;
            }else{
                right = mid - 1;
            }
        }
        int mid = left;
        if(target >= nums[0]){
            left = 0;
            right = mid;
        }
        else{
            left++;
            right = nums.size() - 1;
        }

        while(left <= right){
            mid = left + (right - left)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
