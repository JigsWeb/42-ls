#include "../../includes/entry.h"

t_entry *create_entry(char *name, long int mtime)
{
    t_entry *new_entry;

    if (!(new_entry = (t_entry*)malloc(sizeof(t_entry))))
        return (NULL);
    new_entry->name = name;
    new_entry->mtime = mtime;
    new_entry->next = NULL;
    new_entry->prev = NULL;
    return (new_entry);
}

t_entry *add_entry(t_entry **e, t_entry *new)
{
    t_entry *tmp;

    if (!new)
        return (NULL);
    if (!(*e))
        return ((*e) = new);
    tmp = (*e);
    tmp->prev = new;
    (*e) = new;
    (*e)->next = tmp;
    return ((*e));
}