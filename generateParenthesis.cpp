#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct parenthesisTree{
	string val ;
	int ln ;
	int rn ;
	parenthesisTree *left ;
	parenthesisTree *right ;
	parenthesisTree (string v, int l, int r): val(v), ln(l), rn(r), left(NULL), right(NULL) {}
};

void cons(parenthesisTree *root, int n){
	if(root->ln == root->rn && root->ln == n){
		return ;
	}else if(root->ln == root->rn && root->ln < n) {
		root->left = new parenthesisTree(root->val.substr(0).append("("), root->ln + 1, root->rn) ;
		root->right = NULL ;
		cons(root->left, n) ;
	}else if(root->ln > root->rn && root->ln < n){
		root->left = new parenthesisTree(root->val.substr(0).append("("), root->ln + 1, root->rn) ;
		root->right = new parenthesisTree(root->val.substr(0).append(")"), root->ln, root->rn + 1) ;
		cons(root->left, n) ;
		cons(root->right, n) ;
	}else if(root->ln == n){
		string str(root->ln - root->rn, ')') ;
		root->right = new parenthesisTree(root->val.substr(0).append(str), n, n) ;
		cons(root->right, n) ;
	}
}
void traverse(parenthesisTree *root, vector<string> &out){
	if(root->left == NULL && root->right == NULL){
		out.push_back(root->val) ;
	}else if(root->left == NULL) {
		traverse(root->right, out) ;
	}else if(root->right == NULL) {
		traverse(root->left, out) ;
	}else{
		traverse(root->left, out) ;
		traverse(root->right, out) ;
	}
}
vector<string> generateParenthesis(int n){
	vector<string> ret(0) ;
	if(n == 0){
		ret.push_back("");
	}else if(n == 1){
		ret.push_back("()") ;
	}else{
		parenthesisTree root("(", 1, 0) ;
		cons(&root, n) ;
		traverse(&root, ret) ;
	}
	return ret ;
}

