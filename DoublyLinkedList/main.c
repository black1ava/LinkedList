#include<stdio.h>
#include<stdlib.h>

typedef struct DoublyLinkedList {
	int value;
	struct DoublyLinkedList *prev, *next;
} DoublyLinkedList;

DoublyLinkedList *doubly_linked_list_new(){
	DoublyLinkedList *newNode = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
	newNode = NULL;

	return newNode;
}

void doubly_linked_list_insert_front(DoublyLinkedList **head, int n){
	DoublyLinkedList *newNode = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
	newNode->value = n;
	newNode->prev = NULL;
	newNode->next = *head;

	if(*head != NULL){
		(*head)->prev = newNode;
	}

	*head = newNode;
}

void doubly_linked_list_insert_after_node(DoublyLinkedList **head, int current, int n){
	DoublyLinkedList *newNode = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
	newNode->value = n;
	DoublyLinkedList *tmp = *head;

	while(tmp != NULL){
		if(tmp->value == current){
			break;
		}

		tmp = tmp->next;
	}

	newNode->next = tmp->next;
	tmp->next->prev = newNode;
	newNode->prev = tmp;
	tmp->next = newNode;
}

void doubly_linked_list_insert_last(DoublyLinkedList **head, int n){
	DoublyLinkedList *newNode = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
	newNode->value = n;
	newNode->next = NULL;
	DoublyLinkedList *tmp = *head;

	while(tmp->next != NULL){
		tmp = tmp->next;
	}

	newNode->prev = tmp;
	tmp->next = newNode;
}

void doubly_linked_list_delete_front(DoublyLinkedList **head){
	(*head) = (*head)->next;
	(*head)->prev = NULL;
}

void doubly_linked_list_delete_after_node(DoublyLinkedList **head, int current){
	DoublyLinkedList *tmp = *head;

	while(tmp != NULL){
		if(tmp->value == current){
			break;
		}

		tmp = tmp->next;
	}

	tmp->next = tmp->next->next;
	tmp->next->next->prev = tmp;
}

void doubly_linked_list_delete_last(DoublyLinkedList **head){
	DoublyLinkedList *tmp = *head;

	while(tmp->next->next != NULL){
		tmp = tmp->next;
	}

	tmp->next = NULL;
}

void dll_print(DoublyLinkedList *head){
	DoublyLinkedList *tmp = head;

	while(tmp != NULL){
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}

	printf("\n");
}

int main(){
	DoublyLinkedList *head = doubly_linked_list_new();

	for(int i = 1; i <= 10; i++){
		doubly_linked_list_insert_front(&head, i);
	}

	doubly_linked_list_insert_after_node(&head, 5, 11);
	doubly_linked_list_insert_last(&head, 12);
	doubly_linked_list_delete_front(&head);
	doubly_linked_list_delete_after_node(&head, 5);
	doubly_linked_list_delete_last(&head);

	dll_print(head);
	return 0;
}