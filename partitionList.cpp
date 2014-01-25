#include <iostream>

using namespace std ;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x) {
	ListNode *lh = NULL, *gh = NULL, *ghead = NULL, *lhead = NULL;
	while(head != NULL){
		if(head->val < x){
			ListNode h(head->val);
			if(lh == NULL){
				lh = &h ;
				lhead = lh ;
			}else{
				lh->next = &h;
				lh = lh->next ;
			}
		}else{
			ListNode h(head->val);
			if(gh == NULL){
				gh = &h ;
				ghead = gh ;
			}else{
				gh->next = &h;
				gh = gh->next ;
			}
		}
		head = head->next ;
	}
	if(lh != NULL){
		lh->next = ghead ;
	}else{
		return ghead ;
	}
	return lhead ;
}
int main(){
	ListNode in(1) ;
	ListNode *r = partition(&in, 0);
	cout << "haha\n" ;
	while(r != NULL){
		int val = r->val ;
		cout << ' ' << '-' ;
		cout << ' ' <<   val << '-' << endl;
		r = r->next ;
	}
	cout << '\n' ;
	return 0 ;
}
