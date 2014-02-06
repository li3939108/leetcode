/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
#include <iostream>
#include <stack>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode *root, int sum) {
	stack<int> sums ;
	stack<TreeNode *> addr ;
	map<TreeNode*, bool> visited ;
	if(root == NULL){
		return false ;
	}
	addr.push(root);
	sums.push(root->val);
	visited[root] = true ;
	visited[NULL] = true ;
	while(!addr.empty()){
		TreeNode *root = addr.top() ;
		if(visited[root->left] == true && visited[root->right] == true){
			if(root->left == NULL && root->right == NULL){
				int s = sums.top() ;
				if(s == sum ){
					return true ;
				}
			}
			addr.pop() ;
			sums.pop() ;
		}else if(visited[root->left] == true){
			addr.push(root->right) ;
			sums.push(root->right->val + sums.top()); 
			visited[root->right] = true ;
		}else {
			addr.push(root->left) ;
			sums.push(root->left->val + sums.top()); 
			visited[root->left] = true ;
		}
	}
	return false ;
}
int main(){
	TreeNode root(1) ;
	TreeNode left (2) ;
	root.left = &left ;
	cout << ' ' << hasPathSum(&root, 0) << '\n' ;
	return 0;
}
