#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct link{
    int data;
    struct link *next;

}LinkNode;
 /* Link
              n6  <----     n5
               |             |
        n1 -> n2 -> n3 -> n4 |
 	
 */
LinkNode *CreateNode(){
    LinkNode *node1 = (LinkNode *)malloc(sizeof(LinkNode));
    node1->data = 1;
    node1->next = (LinkNode *)malloc(sizeof(LinkNode));
    
    LinkNode *node2 = node1->next;
    node2->data = 2;
    node2->next = (LinkNode *)malloc(sizeof(LinkNode));

    LinkNode *node3 = node2->next;
    node3->data = 3;
    node3->next = (LinkNode *)malloc(sizeof(LinkNode));;

    LinkNode *node4 = node3->next;
    node4->data = 4;
    node4->next = (LinkNode *)malloc(sizeof(LinkNode));;

    LinkNode *node5 = node4->next;
    node5->data = 5;
    node5->next = (LinkNode *)malloc(sizeof(LinkNode));;

    LinkNode *node6 = node5->next;
    node6->data = 6;
    node6->next = node2;

    return node1;
}
LinkNode *detectCycle(LinkNode *head){
    assert((head->next != NULL && head->next->next !=NULL) && "no cycle");
    LinkNode *now = head;
    LinkNode *temp = now->next;
    while(now->next != NULL){
	if(temp->next != head && temp->next != NULL){
	    now->next = head;
	    now = temp;
	    temp = temp->next;
	    
	}
	else if(temp->next == NULL){
	    temp = NULL;
	    printf("no cycle\n");
	    break;
	}
	else{
	    printf("cycle detected!\n"); 
	    break;
	}
    }
    return temp;
}
int main()
{
    LinkNode *head = CreateNode();
    LinkNode *res = detectCycle(head);
    //use print to check the list 
    /*printf("%d->%d->%d->%d->%d->%d->%d\n",head->data,
				    head->next->data,
				    head->next->next->data,
				    head->next->next->next->data,
				    head->next->next->next->next->data,
				    head->next->next->next->next->next->data,
				    head->next->next->next->next->next->next->data);*/
    if (res != NULL)
	printf("result: n%d\n",res->data);
    else
	printf("NULL\n");
    return 0;
}
