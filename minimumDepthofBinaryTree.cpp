/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

int minDepth(TreeNode *root){
	queue<TreeNode *> q ;
	map<TreeNode *, int> m ;
	if(root == NULL){
		return 0;
	}else{
		q.push(root) ;
		m[root] = 1 ;
	}
	while(! q.empty()){
		TreeNode *front = q.front() ;
		if(front->left == NULL && front->right == NULL){
			return m[front] ;
		}else if(front->left == NULL){
			q.push(front->right) ;
			m[front->right] = m[front] + 1;
			q.pop() ;
		}else if(front->right == NULL){
			q.push(front->left) ;
			m[front->left] = m[front] + 1;
			q.pop() ;
		}else{
			q.push(front->right) ;
			m[front->right] = m[front] + 1;
			q.push(front->left) ;
			m[front->left] = m[front] + 1;
			q.pop() ;
		}
	}
}
