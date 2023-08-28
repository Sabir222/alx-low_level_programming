#include "lists.h"

/**
 * find_listint_loop - Searches for a magical loop in the linked list.
 * @head: The head of the mystical list.
 *
 * Return: The entrance to the loop, or NULL if the loop is a myth.
 *                (Imagine the linked list as a path through a magical forest,
 *                and this function as a tracker of elusive footprints.)
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *adventurer_slow, *adventurer_fast; /* The brave adventurers exploring the enchanted forest */

	if (head == NULL || head->next == NULL)
		return (NULL); /* If the forest is empty or has only one path, there can be no loop */

	adventurer_slow = head->next; /* The slow adventurer sets foot in the forest, starting the exploration */
	adventurer_fast = head->next->next; /* The fast adventurer takes swift steps, leading the way */

	while (adventurer_fast != NULL && adventurer_fast->next != NULL)
	{
		if (adventurer_slow == adventurer_fast) /* If the adventurers meet, a magical loop is found */
		{
			adventurer_slow = head; /* The slow adventurer returns to the start of the forest path */
			while (adventurer_slow != adventurer_fast) /* They continue their journey together until they meet again */
			{
				adventurer_slow = adventurer_slow->next; /* The slow adventurer takes a step forward */
				adventurer_fast = adventurer_fast->next; /* The fast adventurer rushes ahead */
			}
			return (adventurer_slow); /* They meet at the entrance of the loop, marking their discovery */
		}
		adventurer_slow = adventurer_slow->next; /* The slow adventurer takes a step forward */
		adventurer_fast = adventurer_fast->next->next; /* The fast adventurer races ahead */
	}

	return (NULL); /* If the adventurers exhaust their exploration without finding a loop, it's a myth */
}
