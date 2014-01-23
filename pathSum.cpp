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

vector<vector<int> > pathSum(TreeNode *root, int sum) {
	vector<vector<int> > ret(0) ;
	stack<int> sums ;
	stack<TreeNode *> addr ;
	vector<int> vallist (0);
	map<TreeNode*, bool> visited ;
	if(root == NULL){
		return ret ;
	}
	addr.push(root);
	sums.push(root->val);
	vallist.push_back(root->val) ;
	visited[root] = true ;
	visited[NULL] = true ;
	while(!addr.empty()){
		TreeNode *root = addr.top() ;
		if(visited[root->left] == true && visited[root->right] == true){
			if(root->left == NULL && root->right == NULL){
				int s = sums.top() ;
				if(s == sum ){
					vector<int> newlist(vallist) ;
					ret.push_back(newlist) ;
				}
			}
			addr.pop() ;
			sums.pop() ;
			vallist.erase(vallist.end() - 1) ;
		}else if(visited[root->left] == true){
			addr.push(root->right) ;
			sums.push(root->right->val + sums.top()); 
			vallist.push_back(root->right->val) ;
			visited[root->right] = true ;
		}else {
			addr.push(root->left) ;
			sums.push(root->left->val + sums.top()); 
			vallist.push_back(root->left->val) ;
			visited[root->left] = true ;
		}
	}
	return ret ;
}