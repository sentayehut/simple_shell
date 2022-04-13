#include "shell.h"

/**
 * print_list - Print the lists
 * @h: list with format list_t
 * Return: number of nodes of the list
 */
size_t print_list(const list_t *h)
{
	unsigned int number_nodes = 0;

	while (h != NULL)
	{
		if (h->str)
		{
			_puts(num_to_str(h->len));
			_puts(" ");
			_puts(h->str);
			_puts("\n");
		}
		else
			_puts("[0] (nil)\n");
		h = h->next;
		number_nodes++;
	}
	return (number_nodes);
}

/**
 * add_node_end - add a new node at the end of the linked list
 * @head: pointer to the first node
 * @str: content of the string for the first node
 * Return: pointer to the first node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *end_node, *tmp;

	end_node = malloc(sizeof(list_t));

	if (end_node == NULL)
		return (NULL);

	end_node->str = _strdup(str);
	end_node->len = _strlen(str);
	end_node->next = NULL;

	if (*head == NULL)
	{
		*head = end_node;
		return (*head);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = end_node;
	return (end_node);

}

/**
 * free_list - functions that free a linkedlist
 * @head: head of first node
 * Return: void -> free the linked list
 */
void free_list(list_t *head)
{
	if (head == NULL)
		return;
	free_list(head->next);
	free(head->str);
	free(head);
}
