#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
    int length = 0;

    while (list)
    {
        length++;
        length = length->next;
    }
    return (length);
}