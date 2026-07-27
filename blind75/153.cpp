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
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int middle = (left + right + 1) / 2;
        while(left < right){
            middle = (left + right) / 2;
            if(nums[middle] > nums[right]){
                left = middle + 1;
            }else{
                right = middle;
            }
            //cout << right << " " << left << " "<< middle << endl;
        }
        return nums[left];
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
