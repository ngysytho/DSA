#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;


class Node{
    public:
        int val;
        vector<Node*> neighbors;

        Node() {
            val = 0;
            neighbors = vector<Node*> ();
        }

        Node(int _val){
            val = _val;
            neighbors = vector<Node*> ();
        }

        Node( int _val, vector<Node*> _neighbors){
            val = _val;
            neighbors = _neighbors;
        }
};


Node* inputGraph(){
    int n;
    cin >> n;

    if(n == 0) return NULL;

    vector<Node*> node(n + 1);

    for(int i = 1; i <= n; i++){
        node[i] = new Node(i);
    }

    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;

        for(int j = 0; j < k; j++){
            int neighVal;
            cin >> neighVal;

            node[i] -> neighbors.push_back(node[neighVal]);
        }
    }
    return node[1];
}


class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        
        if(node == NULL) return NULL;

        if(mp.count(node)) return mp[node];

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for(Node* neighbor : node->neighbors){
            clone -> neighbors.push_back(cloneGraph(neighbor));
        }
        return clone;
    }
};


class Solution1 {
public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) // if node is null, then simply return null
        {
            return NULL;
        }
        
        Node* first = new Node(node -> val, {}); // make a copy of first node
        mp[node] = first;
        
        queue<Node*> q; //For bfs, we create queue
        q.push(node); // push into queue
        
        while(q.empty() == false) // until q. empty == false
        {
            Node* curr = q.front(); // extract front node
            q.pop(); // pop that from queue
            
            for(auto adj: curr -> neighbors) // now travel in adjcant
            {
                if(mp.find(adj) == mp.end()) // if not present in map
                {
                    mp[adj] = new Node(adj -> val, {}); // then create copy
                    q.push(adj); // push nto the queue
                    
                }
                
                mp[curr] -> neighbors.push_back(mp[adj]); // in current node push adjcant node
            }
        }
        
        return mp[node];
    }
};

void printGraph(Node* node){
    if(node == NULL){
        cout << "rong";
        return;
    }

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        Node* cur = q.front();
        q.pop();

        cout << cur->val << ": ";

        for(Node* neighbor : cur->neighbors){
            cout << neighbor-> val << " ";

            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }


        cout << endl;

    }
}

int main(){
    Node* original = inputGraph();

    cout << "Original graph:\n";
    printGraph(original);

    Solution sol;

    Node* clone = sol.cloneGraph(original);

    printGraph(clone);
}