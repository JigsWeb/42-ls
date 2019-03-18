#include "../../includes/folder.h"

t_folder *create_folder(char *path, long int mtime)
{
    t_folder *new_folder;

    if (!(new_folder = (t_folder*)malloc(sizeof(t_folder))))
        return (NULL);
    new_folder->name = path;
    new_folder->mtime = mtime;
    new_folder->e = NULL;
    new_folder->flr = NULL;
    new_folder->next = NULL;
    new_folder->is_root = 0;
    return (new_folder);
}

t_folder *add_folder(t_folder **flr, t_folder *new)
{
    t_folder *tmp;

    if (!new)
        return (NULL);
    if (!(*flr))
        return ((*flr) = new);
    tmp = (*flr);
    (*flr) = new;
    (*flr)->next = tmp;
    return ((*flr));
}