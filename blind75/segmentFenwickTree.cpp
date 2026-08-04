#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class RecursiveSegmentTree {
public:
    int n;
    vector<int> tree;

    RecursiveSegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);

        if (n > 0) {
            build(1, 0, n - 1, nums);
        }
    }

    void build(int node, int left, int right, vector<int>& nums) {
        if (left == right) {
            tree[node] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;

        build(node << 1, left, mid, nums);
        build(node << 1 | 1, mid + 1, right, nums);

        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    void update(int index, int value) {
        update(1, 0, n - 1, index, value);
    }

    void update(
        int node,
        int left,
        int right,
        int index,
        int value
    ) {
        if (left == right) {
            tree[node] = value;
            return;
        }

        int mid = left + (right - left) / 2;

        if (index <= mid) {
            update(node << 1, left, mid, index, value);
        } else {
            update(node << 1 | 1, mid + 1, right, index, value);
        }

        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    int query(int queryLeft, int queryRight) {
        if (queryLeft > queryRight) {
            return 0;
        }

        return query(
            1,
            0,
            n - 1,
            queryLeft,
            queryRight
        );
    }

    int query(
        int node,
        int left,
        int right,
        int queryLeft,
        int queryRight
    ) {
        if (right < queryLeft || left > queryRight) {
            return 0;
        }

        if (queryLeft <= left && right <= queryRight) {
            return tree[node];
        }

        int mid = left + (right - left) / 2;

        int leftResult = query(
            node << 1,
            left,
            mid,
            queryLeft,
            queryRight
        );

        int rightResult = query(
            node << 1 | 1,
            mid + 1,
            right,
            queryLeft,
            queryRight
        );

        return leftResult + rightResult;
    }
};

class IterativeSegmentTree {
public:
    int n;
    int originalSize;
    vector<int> tree;

    IterativeSegmentTree(vector<int>& nums) {
        originalSize = nums.size();
        n = 1;

        while (n < originalSize) {
            n <<= 1;
        }

        tree.resize(2 * n, 0);

        for (int i = 0; i < originalSize; i++) {
            tree[n + i] = nums[i];
        }

        for (int i = n - 1; i >= 1; i--) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

    void update(int index, int value) {
        int position = n + index;

        tree[position] = value;
        position >>= 1;

        while (position >= 1) {
            tree[position] =
                tree[position << 1] +
                tree[position << 1 | 1];

            position >>= 1;
        }
    }

    int query(int left, int right) {
        if (left > right) {
            return 0;
        }

        int result = 0;

        left += n;
        right += n + 1;

        while (left < right) {
            if (left & 1) {
                result += tree[left];
                left++;
            }

            if (right & 1) {
                right--;
                result += tree[right];
            }

            left >>= 1;
            right >>= 1;
        }

        return result;
    }
};

class FenwickTree {
public:
    int n;
    vector<int> bit;
    vector<int> nums;

    FenwickTree(vector<int>& arr) {
        n = arr.size();
        nums = arr;
        bit.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            add(i, arr[i]);
        }
    }

    void add(int index, int delta) {
        index++;

        while (index <= n) {
            bit[index] += delta;
            index += index & -index;
        }
    }

    void update(int index, int value) {
        int delta = value - nums[index];

        nums[index] = value;
        add(index, delta);
    }

    int prefixSum(int index) {
        index++;

        int result = 0;

        while (index > 0) {
            result += bit[index];
            index -= index & -index;
        }

        return result;
    }

    int query(int left, int right) {
        if (left > right) {
            return 0;
        }

        return prefixSum(right) - prefixSum(left - 1);
    }
};

class RecursiveFenwickTree {
public:
    int n;
    vector<int> bit;
    vector<int> nums;

    RecursiveFenwickTree(vector<int>& arr) {
        n = arr.size();
        nums = arr;
        bit.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            add(i, arr[i]);
        }
    }

    void addRecursive(int index, int delta) {
        if (index > n) {
            return;
        }

        bit[index] += delta;

        addRecursive(
            index + (index & -index),
            delta
        );
    }

    int prefixSumRecursive(int index) {
        if (index <= 0) {
            return 0;
        }

        return bit[index] +
               prefixSumRecursive(
                   index - (index & -index)
               );
    }

    void add(int index, int delta) {
        addRecursive(index + 1, delta);
    }

    void update(int index, int value) {
        int delta = value - nums[index];

        nums[index] = value;
        add(index, delta);
    }

    int prefixSum(int index) {
        return prefixSumRecursive(index + 1);
    }

    int query(int left, int right) {
        if (left > right) {
            return 0;
        }

        return prefixSum(right) - prefixSum(left - 1);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};

    RecursiveSegmentTree recursiveSegmentTree(nums);
    IterativeSegmentTree iterativeSegmentTree(nums);
    FenwickTree fenwickTree(nums);
    RecursiveFenwickTree recursiveFenwickTree(nums);

    cout << recursiveSegmentTree.query(1, 4) << '\n';
    cout << iterativeSegmentTree.query(1, 4) << '\n';
    cout << fenwickTree.query(1, 4) << '\n';
    cout << recursiveFenwickTree.query(1, 4) << '\n';

    recursiveSegmentTree.update(2, 10);
    iterativeSegmentTree.update(2, 10);
    fenwickTree.update(2, 10);
    recursiveFenwickTree.update(2, 10);

    cout << recursiveSegmentTree.query(1, 4) << '\n';
    cout << iterativeSegmentTree.query(1, 4) << '\n';
    cout << fenwickTree.query(1, 4) << '\n';
    cout << recursiveFenwickTree.query(1, 4) << '\n';

    return 0;
}