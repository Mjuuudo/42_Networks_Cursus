#include "../Push_swap.c"

pushswap_list *get_last_node(pushswap_list *head)
{
    if (head == NULL)
        return (NULL);
    while (head_>next)
        head = head->next;
    return (head);
}