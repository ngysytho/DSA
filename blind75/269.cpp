#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution1 {
private:
    bool isValid(const string& perm, const vector<string>& words) {
        unordered_map<char, int> order_map;
        for (int i = 0; i < perm.length(); ++i) {
            order_map[perm[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());
            
            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    if (order_map[w1[j]] > order_map[w2[j]]) {
                        return false;
                    }
                    break;
                }
            }
        }
        return true;
    }

    bool generatePermutations(string& current_perm, vector<bool>& used, const string& unique_chars, const vector<string>& words, string& result) {
        if (current_perm.length() == unique_chars.length()) {
            if (isValid(current_perm, words)) {
                result = current_perm;
                return true; 
            }
            return false;
        }

        for (int i = 0; i < unique_chars.length(); ++i) {
            if (!used[i]) {
                used[i] = true;
                current_perm.push_back(unique_chars[i]);
                
                if (generatePermutations(current_perm, used, unique_chars, words, result)) {
                    return true;
                }
                
                current_perm.pop_back();
                used[i] = false;
            }
        }
        return false;
    }

public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> char_set;
        for (const string& w : words) {
            for (char c : w) char_set.insert(c);
        }

        string unique_chars = "";
        for (char c : char_set) unique_chars += c;

        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return ""; 
            }
        }

        string current_perm = "";
        string result = "";
        vector<bool> used(unique_chars.length(), false);

        generatePermutations(current_perm, used, unique_chars, words, result);

        return result; 
    }     
};


class Solution2 {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> unique_chars;
        for (const string& w : words) {
            for (char c : w) unique_chars.insert(c);
        }

        string perm = "";
        for (char c : unique_chars) perm += c;
        // Bắt buộc phải sort để hàm next_permutation duyệt từ hoán vị đầu tiên
        sort(perm.begin(), perm.end()); 

        // Kiểm tra nhanh bẫy tiền tố để tránh chạy hoán vị tốn thời gian vô ích
        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return ""; 
            }
        }

        // Vét cạn tất cả các hoán vị
        do {
            unordered_map<char, int> order_map;
            for (int i = 0; i < perm.length(); ++i) order_map[perm[i]] = i;

            bool isValid = true;
            for (int i = 0; i < words.size() - 1; ++i) {
                string w1 = words[i], w2 = words[i + 1];
                int minLen = min(w1.length(), w2.length());
                
                for (int j = 0; j < minLen; ++j) {
                    if (w1[j] != w2[j]) {
                        // Nếu chữ ở w1 lại bị xếp sau chữ ở w2 trong hoán vị này -> Sai
                        if (order_map[w1[j]] > order_map[w2[j]]) {
                            isValid = false;
                        }
                        break; 
                    }
                }
                if (!isValid) break;
            }
            if (isValid) return perm; // Tìm thấy hoán vị đúng

        } while (next_permutation(perm.begin(), perm.end()));

        return ""; // Thử hết mọi cách vẫn không có -> Vô nghiệm
    }
};


class Solution{
public:
    string foreignDictionary(vector<string>& words) {
    }
};


class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // Khởi tạo tất cả chữ cái có indegree = 0
        for (const string& w : words) {
            for (char c : w) {
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());
            
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) return "";
            
            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    // Nếu cạnh chưa có mặt trong đồ thị thì mới đếm, tránh đếm lặp
                    if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for (auto& pair : indegree) {
            if (pair.second == 0) q.push(pair.first);
        }

        string result = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Kiểm tra xem có bị kẹt vòng lặp vô hạn không
        return result.length() == indegree.size() ? result : "";
    }
};

class Solution {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> state; // 0: chưa thăm, 1: đang thăm, 2: đã thăm xong
    string result = "";

    bool dfs(char curr) {
        if (state[curr] == 1) return false; // Đâm đầu vào node đang thăm -> Chu trình (Lỗi)
        if (state[curr] == 2) return true;  // Đã thăm xong an toàn từ trước -> Bỏ qua

        state[curr] = 1; // Đánh dấu đang đi trên nhánh này
        for (char neighbor : adj[curr]) {
            if (!dfs(neighbor)) return false;
        }
        
        state[curr] = 2; // Nhánh này an toàn tuyệt đối
        result += curr;  // Thêm vào kết quả (đây là post-order)
        return true;
    }

public:
    string foreignDictionary(vector<string>& words) {
        // Khởi tạo đồ thị
        for (const string& w : words) {
            for (char c : w) {
                adj[c] = unordered_set<char>();
                state[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());
            
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) return "";
            
            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        // Chạy DFS cho từng chữ cái có trong bản đồ
        for (auto& pair : adj) {
            if (state[pair.first] == 0) {
                if (!dfs(pair.first)) return ""; // Nếu trả về false nghĩa là có chu trình
            }
        }

        // Đảo ngược chuỗi vì post-order DFS ghi nhận các phần tử cuối đồ thị trước
        reverse(result.begin(), result.end());
        return result;
    }
};


class Solution{
public:
    string foreignDictionary(vector<string>& words) {
        bool present[26] = {false};
        bool adj[26][26] = {false};

        for(string x : words){
            for(auto j : x){
                present[j - 'a'] = true;
            }
        }
        int n = words.size();
        
        for(int i = 0; i < n - 1; i++){
            string s = words[i], x = words[i + 1];

            int len = min(s.size(), x.size());
            if(s.size() > x.size() && s.substr(0, len) == x) return "";

            for(int j = 0; j < len; j++){
                if(s[j] != x[j]){
                    adj[s[j] - 'a'][x[j] - 'a'] = true;
                    break;
                }
            }
        }

        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(adj[i][k] && adj[k][j]){
                        adj[i][j] = true;
                    }
                }
            }
        }

        for(int i = 0; i < 26; i++){
            if(adj[i][i]) return "";
        }



        string result = "";
        for(int i = 0; i < 26; i++){
            if(present[i]) result += char(i + 'a');
        }

        int outdegree[26] = {0};

        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                if(adj[i][j]) outdegree[i]++;
            }
        }

        sort(result.begin(), result.end(), [&](char a, char b){
            return outdegree[a - 'a'] > outdegree[b - 'a'];
        });

        return result;
    }
};


class Solution{

private:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> state;
    string result = "";

    bool dfs(char curr){
        if(state[curr] == 1) return false;
        if(state[curr] == 2) return true;

        state[curr] = 1;

        for(auto x : adj[curr]){
            if(!dfs(x)) return false;
        }
        state[curr] = 2;
        result += curr;
        return true;
    }

public:
    string foreignDictionary(vector<string>& words){
        for(string s : words){
            for(char x : s){
                adj[x] = unordered_set<char>();
                state[x] = 0;
            }
        }

        int n = words.size();
        for(int i = 0 ; i < n - 1; i++){
            string s = words[i];
            string x = words[i + 1];

            int len = min(s.size(), x.size());

            if(s.size() > x.size() && s.substr(0, len) == x) return "";

            for(int j = 0; j < len; j++){
                if(s[j] != x[j]){
                    adj[s[j]].insert(x[j]);
                    break;
                }
            }
        }

        for(auto pair : adj){
            if(!dfs(pair.first)) return "";
        }
        reverse(result.begin(), result.end());
        return result;
    }
};