#ifndef CUSTOM_LINKED_LIST_H
#define CUSTOM_LINKED_LIST_H

/**
 * struct custom_list_node - singly linked list node
 * @str: string (allocated using malloc)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: Defines a node structure for a singly linked list
 * used in a custom project.
 */
typedef struct custom_list_node
{
	char *str;
	unsigned int len;
	struct custom_list_node *next;
} custom_list_t;

size_t custom_print_list(const custom_list_t *h);
size_t custom_list_len(const custom_list_t *h);
custom_list_t *custom_add_node(custom_list_t **head, const char *str);
custom_list_t *custom_add_node_end(custom_list_t **head, const char *str);
void custom_free_list(custom_list_t *head);

#endif
