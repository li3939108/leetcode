#include <iostream>
#include <map>

using namespace std;
/* Balanced Binary Tree Problem
 * with time complexity O(n)
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<TreeNode *, int> m;

int cDepth( TreeNode *root, int d){
    TreeNode *left , *right;
    if(root == NULL){
        return d;
    }else{
        int depth ;
        left= root->left;
        right = root->right;
        depth = max(cDepth(left, d+1), cDepth(right, d+1));
        m[root] = depth - d;
        return depth ;
    }
}
bool traverse(TreeNode *left, TreeNode *right){
    if(left == NULL && right == NULL){
        return true;
    }else if(left != NULL && right != NULL){
        return (m[left] - m[right] <= 1 && m[right] - m[left] <= 1) && traverse(left->left, left->right) && traverse(right->left, right->right);
    }else if(left != NULL){
        return m[left] == 1 && traverse(left->left, left->right) ;
    }else if(right != NULL){
        return m[right] == 1 && traverse(right->left, right->right) ;
    }
}
bool isBalanced(TreeNode *root) {
    cDepth ( root, 0);
    if(root == NULL) {
        return true;
    }else{
        return traverse(root->left, root->right);
    }
    
}
int main(){
    TreeNode r1 (2) ;
    TreeNode r2 (1) ;
    TreeNode r3 (3) ;
    r1.left = &r2 ;
    r1.right = &r3 ;
    cout << "result: " << isBalanced(&r1) << '\n' ;
    return 0;
}