#include "../Push_swap.h"

size_t linked_list_len(pushswap_list *head)
{
    size_t length;

    length = 0;
    if (head == NULL)
        return (NULL);
    while (head)
    {
        length++;
        head = head -> next;
    }
    return (length);
}