#include<stdio.h>
#include<stdlib.h>

typedef struct CircularLinkedList {
	int value;
	struct CircularLinkedList *next;
} CircularLinkedList;

CircularLinkedList *circular_linked_list_new(){
	CircularLinkedList *last = (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
	last = NULL;

	return last;
}

void circular_linked_list_add_front(CircularLinkedList **last, int n){
	CircularLinkedList *newNode = (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
	newNode->value = n;

	if(*last == NULL){
		*last = newNode;
		(*last)->next = *last;
	}

	newNode->next = (*last)->next;
	(*last)->next = newNode;
}

void circular_linked_list_add_after_node(CircularLinkedList **last, int current, int n){
	CircularLinkedList *newNode = (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
	newNode->value = n;


	if((*last)->value == current){
		newNode->next = (*last)->next;
		(*last)->next = newNode;
		(*last) = newNode;
		return;
	}

	CircularLinkedList *tmp = (*last)->next;
	
	do{
		if(tmp->value == current){
			break;
		}
		tmp = tmp->next;
	}while(tmp != (*last)->next);

	newNode->next = tmp->next;
	tmp->next = newNode;
}

void circular_linked_list_add_last(CircularLinkedList **last, int n){
	if(*last == NULL){
		circular_linked_list_add_front(last, n);
		return;
	}

	CircularLinkedList *newNode = (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
	newNode->value = n;

	newNode->next = (*last)->next;
	(*last)->next = newNode;
	*last = newNode;
}

void circular_linked_list_delete_front(CircularLinkedList **last){
	if(*last == (*last)->next){
		*last = NULL;
		return;
	}

	(*last)->next = (*last)->next->next;
}

void circular_linked_list_delete_after_node(CircularLinkedList **last, int current){
	if((*last)->value == current){
		circular_linked_list_delete_front(last);
		return;
	}

	CircularLinkedList *tmp = (*last)->next;

	do{
		if(tmp->value == current){
			break;
		}

		tmp = tmp->next;
	}while(tmp != (*last)->next);

	if(tmp->next == *last){
		tmp->next = tmp->next->next;
		*last = tmp;
	}

	tmp->next = tmp->next->next;
}

void circular_linked_list_delete_last(CircularLinkedList **last){
	if(*last == (*last)->next){
		*last = NULL;
		return;
	}

	CircularLinkedList *tmp = (*last)->next;

	do{
		tmp = tmp->next;
	}while(tmp->next->next != (*last)->next);

	tmp->next = tmp->next->next;
	*last = tmp;
}

void cl_print(CircularLinkedList *last){
	CircularLinkedList *tmp = last->next;

	do{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}while(tmp != last->next);

	printf("\n");
}

int main(){
	CircularLinkedList *last = circular_linked_list_new();
	for(int i = 1; i <= 10; i++){
		circular_linked_list_add_front(&last, i);
	}

	circular_linked_list_add_after_node(&last, 10, 11);
	circular_linked_list_add_last(&last, 12);

	circular_linked_list_delete_front(&last);
	circular_linked_list_delete_after_node(&last, 1);

	circular_linked_list_add_front(&last, 20);
	circular_linked_list_delete_last(&last);

	cl_print(last);

	return 0;
}