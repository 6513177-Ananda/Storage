#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *next;
	struct node* prev;
};

typedef struct node node_t;

void printlist(node_t *head)
{
	node_t *temporary = head;

	while (temporary != NULL)
	{
		printf("%d - ", temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
}

node_t *create_new_node(int value)
{
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	result->prev = NULL;
	return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
	node_to_insert->next = *head;
	(*head)->prev = node_to_insert;
	*head = node_to_insert;
	return node_to_insert;
}

void remove_node(node_t **head, node_t *node_to_remove)
{
	if (*head == node_to_remove)
	{
		*head = node_to_remove->next;
		return;
	}
	else
	{
		//find the previous node in the list
		node_t *temp = *head;
		while(temp != NULL && temp->next != node_to_remove)
		{
			temp = temp->next;
		}
		if (temp == NULL) return;
		temp->next = node_to_remove->next;
		node_to_remove->next = NULL;
	}
	return;
}

void *insert_after_node(node_t *node_to_insert_after, node_t *newnode)
{
	newnode->next = node_to_insert_after->next;
	node_to_insert_after->next = newnode;
}

node_t *find_node(node_t *head, int value)
{
	node_t *tmp = head;
	while (tmp != NULL)
	{
		if (tmp->value == value) return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

int main()
{
	node_t *head = NULL;
	node_t *tmp;

	for(int i = 0; i < 25; i++)
	{
		tmp = create_new_node(i);
		insert_at_head(&head, tmp);
	}
	
	tmp = find_node(head, 13);
	printf("found node with value %d\n", tmp->value); 

	insert_after_node(tmp, create_new_node(75));

	tmp = find_node(head, 22);
	remove_node(&head, tmp);

	printlist(head);

	return 0;
}