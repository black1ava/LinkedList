#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList {
	int value;
	struct LinkedList *next;
} LinkedList;

LinkedList *linked_list_new(){
	LinkedList *newNode = (LinkedList*)malloc(sizeof(LinkedList));
	newNode = NULL;
	return newNode;
}

void linked_list_insert_front(LinkedList **head, int n){
	LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
	newNode->value = n;
	newNode->next = *head;

	*head = newNode;
}

void linked_list_insert_last(LinkedList **head, int n){
	LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
	newNode->value = n;
	newNode->next = NULL;

	LinkedList *tmp = *head;

	while(tmp->next != NULL){
		tmp = tmp->next;
	}

	tmp->next = newNode;
}

void linked_list_insert_after_node(LinkedList **head, int current, int n){
	LinkedList *newNode = (LinkedList *)malloc(sizeof(LinkedList));
	newNode->value = n;

	LinkedList *tmp = *head;
	
	while(tmp != NULL){
		if(tmp->value == current){
			break;
		}

		tmp = tmp->next;
	}

	newNode->next = tmp->next;
	tmp->next = newNode;
}

void linked_list_delete_front(LinkedList **head){
	*head = (*head)->next;
}

void linked_list_delete_last(LinkedList **head){
	LinkedList *tmp = *head;

	while(tmp->next->next != NULL){
		tmp = tmp->next;
	}

	tmp->next = NULL;
}

void linked_list_delete_after_node(LinkedList **head, int current){
	LinkedList *tmp = *head;

	while(tmp != NULL){
		if(tmp->value == current){
			break;
		}
		tmp = tmp->next;
	}

	tmp->next = tmp->next->next;
}

void linked_list_sort(LinkedList **head){
	LinkedList *current = *head;

	while(current != NULL){
		LinkedList *index = current->next;
		
		while(index != NULL){
			if(index->value > current->value){
				int temp = current->value;
				current->value = index->value;
				index->value = temp;
			}

			index = index->next;
		}

		current = current->next;
	}
}

void l_print(LinkedList *head){
	if(head != NULL){
		printf("%d ", head ->value);
		l_print(head->next);
	}
}
int main(){
	LinkedList *head;
	head = linked_list_new();
	for(int i = 10; i >= 1; i--){
		linked_list_insert_front(&head, i);
	}

	linked_list_insert_last(&head, 11);
	linked_list_insert_after_node(&head, 4, 12);
	linked_list_delete_front(&head);
	linked_list_delete_last(&head);
	linked_list_delete_after_node(&head, 4);
	linked_list_sort(&head);
	l_print(head);
	return 0;
}