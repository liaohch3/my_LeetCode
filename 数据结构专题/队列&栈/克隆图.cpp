#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:

    map<Node*, Node*> m;

    Node* cloneGraph(Node* node) {

        if(node == NULL)
            return node;

        if(m.find(node) != m.end())
            return m[node];

        Node* res = new Node(node->val);

        m[node] = res;

        vector<Node*> resNeighbors;
        for(int i = 0; i < node->neighbors.size(); i++)
        {
            resNeighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        res->neighbors = resNeighbors;
        return res;

    }
};

int main()
{

    return 0;
}