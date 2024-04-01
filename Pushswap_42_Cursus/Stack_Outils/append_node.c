#include "../Push_swap.h"

void append_node(pushswap_list **head, int data)
{
    pushswap_list   *node;
    pushswap_list   *last_node;

    node = (pushswap_list *)malloc(sizeof(pushswap_list));
    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    if (*head == NULL)
    {
        head = node;
        node->prev = NULL;
    }
    else
    {
        last_node = ft_get_last(*head);
        last_node->next = node;
        node->prev = last_node;
    }
}
