#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode *head) {
    ListNode *cur=head,*previous = NULL,*temp,*temp1,*temp2;
    int i = 0,j=0;
            for(i=0;cur != NULL;i++,cur=cur->next);
            cur=head;
            
            for(j=0;j<i;j++){
                if(j >= i / 2 ){ 
                    temp = cur->next;
                    cur->next = previous;
                    previous = cur;
                    cur=temp;
                }else{
                    cur=cur->next;
                }
            }
            cur = head;
            while(previous->next != NULL ){
                temp1=head->next;
                head->next = previous;
                temp2=previous->next;
                previous->next=temp1;
                head = temp1;
                previous=temp2;
            }
            head = cur;
         }
int main(){
    ListNode head = ListNode(1)    ;
    ListNode l2 = ListNode(2);
    ListNode l3 = ListNode(3);
    ListNode l4 = ListNode (4) ;
    ListNode l5 = ListNode (5) ;
    ListNode *cur ;

    head.next = &l2 ;
    l2.next = &l3;
    l3.next = &l4 ;
    l4.next = &l5;
    reorderList(&head);
    cur = &head ;
    while(cur != NULL){
        cout << cur->val << ' ' ;
        cur=cur->next;
    }
}
     
