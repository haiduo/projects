#include <iostream>
#include <vector>
#include <stack> 
using namespace std;

typedef char ElemType;
//定义一个链表节点
struct Node {
    ElemType data;
    Node* left, * right, * parent;
    Node(ElemType value) {
        data = value;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};
//先序构造二叉树
Node* CreateBiTree() {
    Node* current = NULL;
    ElemType value;
    cin >> value;//输入键值
    if (value == '#') {//标识当前子树为空，转向下一节点
        return NULL;
    }
    else {   //递归的创建左右子树
        current = new Node(value);
        current->left = CreateBiTree();
        if (current->left != NULL) {
            current->left->parent = current;
        }
        current->right = CreateBiTree();
        if (current->right != NULL) {
            current->right->parent = current;
        }
        return current;
    }
}
//中序遍历 递归
void midOrder(Node* root) {
    if (root == NULL)
        return;
    else {
        midOrder(root->left);				 //遍历左子树
        cout << root->data << "  -->  ";     //打印根节点
        midOrder(root->right);				 //遍历右子树
    }
}
//求取当前节点最左的孩子
Node* getLeftMost(Node* node) {
    if (node == NULL) {
        return node;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
//返回当前节点的后继节点（中序）
Node* getSuccessorNode(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->right != NULL) {
        return getLeftMost(node->right);
    }
    else {//无右子树
        Node* parentnode = node->parent;
        while (parentnode != NULL && parentnode->right == node) {//当前节点是其父节点的右孩子
            node = parentnode;
            parentnode = node->parent;
        }
        return parentnode;
    }
}

int main(void) {
    Node* root = NULL, * curnode = NULL, * nextnode = NULL;
    cout << "按前序遍历方式创建树" << endl;
    //"ABDG##H###CE#I##F##";
    root = CreateBiTree();
    midOrder(root);			//中序遍历 递归
    cout << endl;
    curnode = root->left->left->right;//H节点
    nextnode = getSuccessorNode(curnode);
    cout << nextnode->data << endl;
    return 0;
}