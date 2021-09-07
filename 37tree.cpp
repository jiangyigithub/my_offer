#include "head.hpp"
 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int node) : val(node), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)return "[null]";//空指针直接返回
        string ret = "[";
        ret += to_string(root->val);
        queue<TreeNode*> Q;
        Q.push(root);
        //节点入队时，将其值转换为字符串加入结果中
        while (!Q.empty()) {
            int sz = Q.size();
            bool flag = false;//用于判断当前层是否是层序遍历的倒数第二层
            for (int i = 0; i < sz; ++i) {
                auto t = Q.front();
                Q.pop();
                if (t->left) {
                    if (t->left->left || t->left->right)flag = true;//下下层有节点，故当前层不是倒数第二层
                    Q.push(t->left);
                    ret.push_back(',');
                    ret += to_string(t->left->val);
                }
                else {
                    ret += ",null";
                }
                if (t->right) {
                    if (t->right->left || t->right->right)flag = true;//下下层有节点，故当前层不是倒数第二层
                    Q.push(t->right);
                    ret.push_back(',');
                    ret += to_string(t->right->val);
                }
                else {
                    ret += ",null";
                }
            }
            if (flag == false)break;//当前层是倒数第二层，跳出
        }
        ret.push_back(']');
        return ret;
    }
    
        //       1
        //      / \
        //     2   3
        //        / \
        //       4   5
       

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.length();
        int i = 1, j = data.find_first_of(',');
        if (j == -1)return nullptr;
        vector<int> store;//存储节点值
        vector<bool> record;//记录树的层序遍历结构，true为非空节点，false为空节点
        for (; j < len - 1 && i < len - 1; ) {
            if (data[i] == 'n') {
                i += 5;
                record.push_back(false);
                continue;
            }
            record.push_back(true);
            j = i + 1;
            while (j < len && data[j] >= '0' && data[j] <= '9') {
                ++j;
            }
            store.push_back(stoi(data.substr(i, j - i)));
            i = j + 1;
        }
        int index = 0;
        int sz = record.size();
        TreeNode* root = new TreeNode(store[index++]);
        queue<TreeNode*> Q;
        Q.push(root);
        //按照层序遍历的顺序进行“反序列化”
        for (int i = 1; i < sz - 1; i += 2) {
            auto t = Q.front();
            Q.pop();
            if (record[i]) {
                t->left = new TreeNode(store[index++]);
                Q.push(t->left);
            }
            if (record[i + 1]) {
                t->right = new TreeNode(store[index++]);
                Q.push(t->right);
            }
        }
        return root;
    }


};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line = "[1,2,3,null,null,4,5]";
    TreeNode* root = stringToTreeNode(line);

    Codec codec;
    string ret = codec.serialize(root);
    TreeNode* treeRet = codec.deserialize(codec.serialize(root));

    string out = (ret);
    cout << out << endl;
    
    return 0;
}