/* 
Problem - https://practice.geeksforgeeks.org/problems/burning-tree/1/
Submission - https://practice.geeksforgeeks.org/viewSol.php?subId=cc4f7918826bbee60dcd43d180b2b57a&pid=702131&user=sayihrudai

*/

//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> parent; 
        unordered_map<Node*, bool> burn;
        queue<Node*> q; 
        struct Node* tar;
        q.push(root); 
        parent[root] = NULL; 
        while(!q.empty()) {
            struct Node* t = q.front(); 
            burn[t] = false;
            if(t->data == target) tar = t;
            q.pop();
            if(t->left) {
                parent[t->left] = t;
                q.push(t->left);
            }
            if(t->right) {
                parent[t->right] = t; 
                q.push(t->right);
            }
        }
        int ans = 0;
        q.push(tar);
        q.push(NULL);
        while(!q.empty()) {
            struct Node* t = q.front();
            q.pop();
            
            if(t == NULL) {
                if(!q.empty()){
                    q.push(NULL);
                    ans += 1;
                } 
            }
            else {
                if(parent[t] != NULL and burn[parent[t]] == false) {
                    q.push(parent[t]);
                    burn[parent[t]] = true;
                }
                if(t->left) {
                    if(burn[t->left] == false) {
                        q.push(t->left);
                        burn[t->left] = true;
                    }
                }
                if(t->right) {
                    if(burn[t->right] == false) {
                        q.push(t->right);
                        burn[t->right] = true;
                    }
                }
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends
