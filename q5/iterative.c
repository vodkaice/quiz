#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
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
#if defined(FLOYD)
LinkNode *detectLoop(LinkNode *head){
    LinkNode *fast, *slow;
    fast = slow = head;
    while( fast && fast->next && fast->next->next){
	fast = fast->next->next;
	slow = slow->next;
	if(fast == slow)
	    return slow;
    }
    return NULL;    //no loop exist
}
LinkNode *detectCycle(LinkNode *head){
    LinkNode *meet_point = detectLoop(head);
    LinkNode *start_head = NULL;    //node start from head
    LinkNode *start_meet = NULL;    //node start from meet point
    
    if(meet_point == NULL)
	return NULL;
    else{ 
	start_head = head;
	start_meet = meet_point;
	while (start_head && start_meet && start_head != start_meet){
	    start_head = start_head->next;
	    start_meet = start_meet->next;
	}
    }
    return start_head; 
}
#endif
#if defined(DESTROY)
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
	    //printf("no cycle\n");
	    break;
	}
	else{
	    //printf("cycle detected!\n"); 
	    break;
	}
    }
    return temp;
}
#endif
static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}
int main()
{
    struct timespec start, end;
    double cpu_time;
    LinkNode *head = CreateNode();
    assert((head->next != NULL && head->next->next !=NULL) && "no cycle");
    clock_gettime(CLOCK_REALTIME, &start);
    LinkNode *res = detectCycle(head);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);
    //use print to check the list 
    /*printf("%d->%d->%d->%d->%d->%d->%d\n",head->data,
				    head->next->data,
				    head->next->next->data,
				    head->next->next->next->data,
				    head->next->next->next->next->data,
				    head->next->next->next->next->next->data,
				    head->next->next->next->next->next->next->data);*/
    if (res != NULL)
	//printf("result: n%d\n",res->data);
	printf("execution time: %.10lf sec\n", cpu_time);
    else
	printf("NULL\n");
    return 0;
}
