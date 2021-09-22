#include<stdio.h>
#include<stdlib.h>


typedef struct DoublyCircularLinkedList {
	int value;
	struct DoublyCircularLinkedList *next;
	struct DoublyCircularLinkedList *prev;
} DoublyCircularLinkedList;

DoublyCircularLinkedList *doubly_circular_linked_list_new(){
	DoublyCircularLinkedList *last = (DoublyCircularLinkedList *)malloc(sizeof(DoublyCircularLinkedList));
	last = NULL;
	return last;
}

void doubly_circular_linked_list_add_front(DoublyCircularLinkedList **last, int n){
	DoublyCircularLinkedList *newNode = (DoublyCircularLinkedList *)malloc(sizeof(DoublyCircularLinkedList));
	newNode->value = n;

	if(*last == NULL){
		*last = newNode;
		(*last)->next = *last;
		(*last)->prev = *last;
		return;
	}

	newNode->next = (*last)->next;
	newNode->prev = *last;

	(*last)->next->prev = newNode;
	(*last)->next = newNode;
}

void doubly_circular_linked_list_add_last(DoublyCircularLinkedList **last, int n){
	if(*last == NULL){
		doubly_circular_linked_list_add_front(last, n);
		return;
	}
	DoublyCircularLinkedList *newNode = (DoublyCircularLinkedList *)malloc(sizeof(DoublyCircularLinkedList));
	newNode->value = n;

	newNode->next = (*last)->next;
	newNode->prev = *last;

	(*last)->next->prev = newNode;
	(*last)->next = newNode;

	*last = newNode;
}

void doubly_circular_linked_list_add_after_node(DoublyCircularLinkedList **last, int current, int n){
	DoublyCircularLinkedList *newNode = (DoublyCircularLinkedList *)malloc(sizeof(DoublyCircularLinkedList));
	newNode->value = n;

	if((*last)->value == current){
		doubly_circular_linked_list_add_last(last, n);
		return;
	}
	
	DoublyCircularLinkedList *tmp = (*last)->next;

	do{
		if(tmp->value == current){
			break;
		}

		tmp = tmp->next;
	}while(tmp != (*last)->next);

	newNode->next = tmp->next;
	newNode->prev = tmp;

	tmp->next->prev = newNode;
	tmp->next = newNode;
}

void doubly_circular_linked_list_delete_front(DoublyCircularLinkedList **last){
	(*last)->next->next->prev = *last;
	(*last)->next = (*last)->next->next;
}

void doubly_circular_linked_list_delete_last(DoublyCircularLinkedList **last){
	*last = (*last)->prev;

	(*last)->next->next->prev = *last;
	(*last)->next = (*last)->next->next;
}

void doubly_circular_linked_list_delete_after_node(DoublyCircularLinkedList **last, int current){
	if((*last)->value == current){
		doubly_circular_linked_list_delete_last(last);
		return;
	}

	DoublyCircularLinkedList *tmp = (*last)->next;

	do{
		if(tmp->value == current){
			break;
		}

		tmp = tmp->next;
	}while(tmp != (*last)->next);

	tmp->next->next->prev = tmp;
	tmp->next = tmp->next->next;
}

void dcl_print(DoublyCircularLinkedList *last){
	DoublyCircularLinkedList *tmp = last->next;

	do{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}while(tmp != last->next);

	printf("\n");
}

int main(){
	DoublyCircularLinkedList *last = doubly_circular_linked_list_new();
	
	for(int i = 1; i <= 10; i++){
		doubly_circular_linked_list_add_front(&last, i);
	}

	doubly_circular_linked_list_add_last(&last, 11);
	doubly_circular_linked_list_add_after_node(&last, 5, 12);
	doubly_circular_linked_list_delete_front(&last);
	doubly_circular_linked_list_delete_last(&last);
	doubly_circular_linked_list_delete_after_node(&last, 5);

	dcl_print(last);

	return 0;
}
