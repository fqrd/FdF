#include "../include/FdF.h"

// x
size_t  array_length(char **array)
{
    size_t i;

    i = 0;
    if (!array)
        return (i);
    while (array[i])
        i++;
    return (i - 1);
}

// y
size_t  count_list(t_lines  *line)
{
    size_t i;

    i = 0;
    if (!line)
        return (i);
    while (line->next)
    {
        i++;
        line = line->next;
    }
    return (i - 1);
}