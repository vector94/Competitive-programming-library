/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)   return "";

        string s = "";
        queue<TreeNode*> myQueue;
        myQueue.push(root);

        while (!myQueue.empty()){
            TreeNode* curNode = myQueue.front();
            myQueue.pop();

            if(curNode == NULL){
                s.append("#,");
            }
            else{
                s.append(to_string(curNode -> val) + ',');
                myQueue.push(curNode -> left);
                myQueue.push(curNode -> right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)   return NULL;

        stringstream s(data);
        string str;

        getline(s, str, ',');

        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> myQueue;
        myQueue.push(root);

        while (!myQueue.empty()){
            TreeNode* curNode = myQueue.front();
            myQueue.pop();

            getline(s, str, ',');

            if (str != "#"){
                TreeNode* leftNode = new TreeNode(stoi(str));
                curNode -> left = leftNode;
                myQueue.push(leftNode);
            }

            getline(s, str, ',');

            if (str != "#"){
                TreeNode* rightNode = new TreeNode(stoi(str));
                curNode -> right = rightNode;
                myQueue.push(rightNode);
            }

        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
