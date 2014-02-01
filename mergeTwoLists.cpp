// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
	ListNode *t1 = l1, *t2 = l2;
	if(t1 != NULL && t2 != NULL){
		if(t1->val > t2->val){
			t2->next = mergeTwoLists(t1, t2->next) ;
			return t2 ;
		}else{
			t1->next = mergeTwoLists(t2, t1->next) ;
			return t1 ;
		}
	}else if(t1 == NULL){
		return t2 ;
	}else if(t2 == NULL){
		return t1 ;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

