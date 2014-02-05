/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7]
  [9,20],
  [3],
]
confused what "{1,#,2,3}" means? 
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxHeight(TreeNode *p) {
	if (!p) return 0;
	int left_height = maxHeight(p->left);
	int right_height = maxHeight(p->right);
	return (left_height > right_height) ? left_height + 1 : right_height + 1;
}

vector<vector<int> > levelOrderBottom(TreeNode *root) {
	vector<vector<int> > r(0);
	queue<TreeNode *> q;
	map<TreeNode *,int> m;
	if(root == NULL){
		return r;
	}else{
		q.push(root);
		m[root] = maxHeight(root)  ;
		r.resize(m[root]) ;
		m[NULL] = 1 ;
		while(!q.empty()){
			TreeNode * left = q.front()->left ;
			TreeNode * right = q.front()->right ;
			if(m[left] && m[right]){
				if(r.size() <= m[root] - m[q.front()]){
					vector<int> t(0);
					t.push_back(q.front()->val);
					r[m[q.front() - 1]] = t;
				}else{
					r[m[q.front()] - 1].push_back(q.front()->val);
				}
				q.pop();
				continue;
			}
			if(m[left] == 0){
				q.push(left);
				m[left] = m[q.front()] - 1;
			}
			if(m[right] ==0){
				q.push(right);
				m[right]=m[q.front()] - 1;
			}
		}
		return r;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

