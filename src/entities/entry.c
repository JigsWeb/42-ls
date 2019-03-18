#include "../../includes/core.h"

#include <stdio.h>

t_ls ls;

t_entry *create_entry(char *name, long int mtime)
{
    t_entry *new_entry;

    if (!(new_entry = (t_entry*)malloc(sizeof(t_entry))))
        return (NULL);
    new_entry->name = name;
    new_entry->mtime = mtime;
    new_entry->next = NULL;
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
    (*e) = new;
    (*e)->next = tmp;
    return ((*e));
}

t_entry *add_entry_sk(t_entry **e, t_entry *new)
{
    t_entry *current;

    if (!new)
        return (NULL);
    if (!(*e) || (!sort(ENTRY, (*e), new) && (new->next = (*e))))
		return ((*e) = new);
    current = (*e);
	while (current->next && sort(ENTRY, current, new))
		current = current->next;
	new->next = current->next;
	current->next = new;
    return ((*e));
}