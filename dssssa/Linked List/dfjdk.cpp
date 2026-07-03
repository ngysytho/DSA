#include <algorithm>
#include <iostream>       // cin, cout, input/output cơ bản
#include <iomanip>        // fixed, setprecision, setw
#include <fstream>        // đọc/ghi file: ifstream, ofstream
#include <sstream>        // xử lý chuỗi như stream: stringstream

#include <string>         // string
#include <cstring>        // strlen, strcpy, memset cho char array
#include <cctype>         // isdigit, isalpha, toupper, tolower

#include <vector>         // vector
#include <array>          // array cố định kích thước
#include <deque>          // deque: thêm/xóa nhanh ở đầu và cuối
#include <list>           // linked list 2 chiều
#include <forward_list>   // linked list 1 chiều

#include <stack>          // stack: LIFO
#include <queue>          // queue, priority_queue
#include <set>            // set, multiset: lưu phần tử có thứ tự
#include <unordered_set>  // unordered_set: set dùng hash, nhanh hơn nhưng không có thứ tự
#include <map>            // map, multimap: key-value có thứ tự
#include <unordered_map>  // unordered_map: key-value dùng hash

#include <algorithm>      // sort, reverse, max, min, binary_search, lower_bound
#include <numeric>        // gcd, lcm, accumulate, iota
#include <functional>     // greater, less, function, lambda helper
#include <iterator>       // iterator, begin, end
#include <utility>        // pair, swap, make_pair
#include <tuple>          // tuple, make_tuple

#include <cmath>          // sqrt, pow, abs, ceil, floor
#include <cstdlib>        // rand, srand, abs
#include <ctime>          // time
#include <random>         // random number hiện đại
#include <chrono>         // đo thời gian, seed random

#include <climits>        // INT_MAX, INT_MIN, LLONG_MAX
#include <cfloat>         // DBL_MAX, FLT_MAX
#include <limits>         // numeric_limits

#include <bitset>         // bitset, xử lý bit
#include <cassert>        // assert để debug
#include <memory>         // smart pointer: unique_ptr, shared_ptr
#include <complex> 

using namespace std;
int n, m;
pair<int, int> a[1000006];
map<int, int> mp;

int main()
{
    cin >> n >> m;
    int ans = (n * (n - 1) * (n - 2)) / 6;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= m; i++)
    {
        int ans1 = (a[i].second - a[i].first - 1) + (n - a[i].second) + (a[i].first - 1);
        if (mp[a[i].first] >= 1)
            ans1 -= mp[a[i].first], mp[a[i].first]--;
        if (mp[a[i].second] >= 1)
            ans1 -= mp[a[i].second], mp[a[i].second]--;

        if (ans1 >= 0)
            ans -= ans1;
        mp[a[i].first]++;
        mp[a[i].second]++;
    }
    cout << ans;
}