#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
		int value;
		struct Node *next;
} Node;

static Node *head = NULL;

static Node* new_node(){
		Node *n = (Node *)malloc(sizeof(Node));
		if(n == NULL){
				printf("\n[Error] Insufficient memory!");
				return NULL;
		}
		printf("\n[Input] Enter the value of the node : ");
		scanf("%d", &n->value);
		n->next = NULL;
		return n;
}

void ins_head(){
		Node *n = new_node();
		if(n != NULL){
				n->next = head;
				head = n;
				printf("[Info] Insertion successful!");
		}
}

void ins_end(){
		Node *n = new_node(), *temp = head;
		if(n == NULL)
				return;
		if(head == NULL)
				head = n;
		else{
				while(temp->next != NULL)
						temp = temp->next;
				temp->next = n;
		}
		printf("[Info] Insertion successful!");
}

void ins_after_value(){
		int val;
		printf("\n[Input] Enter the value to insert after : ");
		scanf("%d", &val);
		Node *temp = head;
		while(temp != NULL && temp->value != val) 
				temp = temp->next;
		if(temp == NULL){
				printf("[Error] Value '%d' not found in the list!", val);
				return;
		}
		Node *n = new_node();
		if(n == NULL)
				return;
		n->next = temp->next;
		temp->next = n;
		printf("[Info] Insertion successful!");
}

void manage_ins(){
		printf("\n[Info] Insertion");
		printf("\n[Info] =========");
		printf("\n[Choice] 1. At head\n[Choice] 2. At end\n[Choice] 3. After value");
		printf("\n[Input] Choice : ");
		char c;
		scanf(" %c", &c);
		switch(c){
				case '1':
						ins_head();
						break;
				case '2':
						ins_end();
						break;
				case '3':
						ins_after_value();
						break;
				default:
						printf("[Error] Wrong choice!");
						break;
		}
}

void del_head(){
		if(head == NULL){
				printf("\n[Error] Unable to delete : List is empty!");
				return;
		}
		Node *bak = head;
		head = head->next;
		free(bak);
		printf("\n[Info] Deletion successful!");
}

void del_end(){
		if(head == NULL){
				printf("\n[Error] Unable to delete : List is empty!");
				return;	
		}
		if(head->next == NULL){
				free(head);
				head = NULL;
		}
		else{
				Node *temp = head;
				while(temp->next->next != NULL)
						temp = temp->next;
				Node *bak = temp->next;
				free(bak);
				temp->next = NULL;
		}
		printf("\n[Info] Deletion successful!");
}

void del_after_value(){
		if(head == NULL){
				printf("\n[Error] Unable to delete! List is empty!");
				return;	
		}
		int a;
		printf("\n[Input] Enter the value to delete after : ");
		scanf("%d", &a);
		Node *temp = head;
		while(temp->value != a && temp != NULL)
				temp = temp->next;
		if(temp == NULL){
				printf("[Error] Unable to delete : Value '%d' not found in the list!", a);
				return;
		}
		if(temp->next == NULL){
				printf("[Error] Unable to delete : The node which contains the value '%d' is the last node in the list!", a);
				return;
		}
		Node *bak = temp->next;
		temp->next = temp->next->next;
		free(bak);
		printf("[Info] Deletion successful!");
}

void manage_del(){
		printf("\n[Info] Deletion");
		printf("\n[Info] ========");
		printf("\n[Choice] 1. From head\n[Choice] 2. From end\n[Choice] 3. After value");
		printf("\n[Input] Choice : ");
		char c;
		scanf(" %c", &c);
		switch(c){
				case '1':
						del_head();
						break;
				case '2':
						del_end();
						break;
				case '3':
						del_after_value();
						break;
				default:
						printf("\n[Error] Wrong choice!");
						break;
		}
}

void list_rev(){
	if(head == NULL){
		printf("\n[Error] Unable to reverse : List is empty!");
		return;
	}
	Node *temp = head, *nhead = NULL;
	while(temp != NULL){
		Node *t = temp->next;
		temp->next = nhead;
		nhead = temp;	
		temp = t;
	}
	head = nhead;
	printf("\n[Info] Reversal successful!");
}

void display(){
		if(head == NULL){
				printf("\n[Info] List is empty!");
				return;
		}
		Node *bak = head;
		int i = 1;
		while(bak != NULL){
				printf("\n[Info] Node %d : %d", i++, bak->value);
				bak = bak->next;
		}
}

void free_list(){
		if(head == NULL)
			return;
		Node *temp = head;
		while(temp != NULL){
			Node *bak = temp->next;
			free(temp);
			temp = bak;
		}
}

int main(){
		while(1){
				printf("\n\n[Info] Main menu");
				printf("\n[Info] =========");
				printf("\n[Choice] 1. Insert\n[Choice] 2. Delete\n[Choice] 3. Display\n[Choice] 4. Reverse");
				printf("\n[Input] Choice : ");
				char c;
				scanf(" %c", &c);
				switch(c){
						case '1':
								manage_ins();
								break;
						case '2':
								manage_del();
								break;
						case '3':
								display();
								break;
						case '4':
							list_rev();
							break;
						default:
								printf("\n[Error] Wrong choice!\n");
								free_list();
								return 0;
				}
		}
}
