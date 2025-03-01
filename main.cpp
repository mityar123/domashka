#include <iostream>
#include <vector>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val): value(val), left(nullptr), right(nullptr) {};
    virtual ~Node() {};
};

class BST {
private:
    Node* root;

    std::vector<Node*> v;

    void delete_vse(Node* cur){
        if (!cur) return;
        delete_vse(cur->left);
        delete_vse(cur->right);
        delete cur;
    }

    Node* insertNode(Node* current, int val) {
        if (!current) {
            return new Node(val);
        }
        if (val < current->value) {
            current->left = insertNode(current->left, val);
        } else {
            current->right = insertNode(current->right, val);
        }
        return current;
    }

    void pre_order(Node* cur){
        if (!cur) return;
        v.push_back(cur);
        pre_order(cur->left);
        pre_order(cur->right);
    }

    void in_order(Node* cur){
        if (!cur) return;
        in_order(cur->left);
        v.push_back(cur);
        in_order(cur->right);
    }

    void post_order(Node* cur){
        if (!cur) return;
        post_order(cur->left);
        post_order(cur->right);
        v.push_back(cur);
    }

    Node* max_order(Node* cur){
        if (!cur) return root;
        if (!cur->right) return cur;
        max_order(cur->right);
    }

    Node* min_order(Node* cur){
        if (!cur) return root;
        if (!cur->left) return cur;
        min_order(cur->left);
    }

    bool search_order(Node* cur, int val){
        if (!cur) return false;
        if (val < cur->value){
            search_order(cur->left, val);
        }else if (val > cur->value){
            search_order(cur->right, val);
        }
        return cur;
    }
public:
    void insert(int val) {
        root = insertNode(root, val);
    }

    void display(){
        std::cout << "Choose order:\n" << "1)pre_order\n" << "2)in_order\n" << "3)post_order\n";
        int x;
        std::cin >> x;
        if(x == 1) pre();
        if(x == 2) in();
        if(x == 3) post();
        for(auto u : v){
            std::cout << u->value << " ";
        }
        std::cout << std::endl;
    }

    void pre(){
        v.clear();
        pre_order(root);
    }

    void in(){
        v.clear();
        in_order(root);
    }

    void post(){
        v.clear();
        post_order(root);
    }

    int max(){
        Node* maxx = max_order(root);
        if (maxx != nullptr) std::cout << maxx->value;
        else std::cout << "BST is empty!";
    }

    int min(){
        Node* minn = min_order(root);
        if (minn != nullptr) std::cout << minn->value;
        else std::cout << "BST is empty!";
    }

    BST(): root(nullptr){};
    virtual ~BST() {
        delete_vse(root);
    }
};

int main() {
    BST bst;
    bst.insert(6);
    bst.insert(4);
    bst.insert(7);
    bst.insert(4);
    bst.insert(9);
    bst.insert(1);
    bst.display();
    bst.display();
    bst.display();
}