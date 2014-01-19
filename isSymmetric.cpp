#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool symmetric(TreeNode *left, TreeNode *right){
	if(left == NULL && right == NULL ){
		return true;
	}else if(left != NULL && right != NULL){
		if(left->val != right ->val){
			return false;
		}else{
			if(symmetric(left->right, right->left) && symmetric(left->left,right->right)){
				return true;
			}else{
				return false;
			}
		}
	}else{
		return false ;
	}
}
bool isSymmetric(TreeNode *root) {
    if(root == NULL){
        return true;
    }
	return symmetric(root->left, root->right);
}

int main(){

}