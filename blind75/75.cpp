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
#include <utility>
#include <map>
#include <cmath>
#include <bitset>
#include <bit>
#include <cstdint>

using namespace std;

#define ll long long

//Selection Sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(nums[i] > nums[j]) swap(nums[i], nums[j]);
            }
        }
    }
};


//Bubble Sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n - 1; i++) {
            bool swapped = false;

            for(int j = 0; j < n - i - 1; j++) {
                if(nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }

            if(!swapped) break;
        }
    }
};




//Insertion Sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        for(int i = 1; i < n; i++) {
            int key = nums[i];
            int j = i - 1;

            while(j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }

            nums[j + 1] = key;
        }
    }
};


//Merge Sort

class Solution {
public:

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;

        int i = left;
        int j = mid + 1;

        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while(i <= mid) {
            temp.push_back(nums[i++]);
        }

        while(j <= right) {
            temp.push_back(nums[j++]);
        }

        for(int k = 0; k < temp.size(); k++) {
            nums[left + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, int left, int right) {
        if(left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }

    void sortColors(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
    }
};


//quickSort
class Solution {
public:

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];

        int i = low - 1;

        for(int j = low; j < high; j++) {
            if(nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i + 1], nums[high]);

        return i + 1;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if(low >= high) return;

        int pivotIndex = partition(nums, low, high);

        quickSort(nums, low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, high);
    }

    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};




//heap sort
class Solution {
public:

    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && nums[left] > nums[largest])
            largest = left;

        if(right < n && nums[right] > nums[largest])
            largest = right;

        if(largest != i) {
            swap(nums[i], nums[largest]);

            heapify(nums, n, largest);
        }
    }

    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        for(int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }
};



//Radix Sort
class Solution {
public:

    void countingSort(vector<int>& nums, int exp) {
        int n = nums.size();

        vector<int> output(n);
        int count[10] = {0};

        for(int num : nums) {
            int digit = (num / exp) % 10;
            count[digit]++;
        }

        for(int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for(int i = n - 1; i >= 0; i--) {
            int digit = (nums[i] / exp) % 10;

            output[count[digit] - 1] = nums[i];
            count[digit]--;
        }

        nums = output;
    }

    void sortColors(vector<int>& nums) {
        int maxNum = 2;

        for(int exp = 1; maxNum / exp > 0; exp *= 10) {
            countingSort(nums, exp);
        }
    }
};



class Solution {
public:
    void sortColors(vector<int>& nums) {
//2,0,2,1,1,0

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high) {

            if(nums[mid] == 0) {

                swap(nums[low], nums[mid]);

                low++;
                mid++;

            } else if(nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);

                high--;
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
