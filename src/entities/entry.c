#include "../../includes/core.h"

#include <stdio.h>

t_ls ls;

char *create_pathname(char *path, char *name)
{
    char *tmp;
    char *res;

    if (!path)
        return (NULL);
    if (path[strlen(path) - 1] == '/')
        return ft_strjoin(path, name);
    tmp = ft_strjoin(path, "/");
    res = create_pathname(tmp, name);
    free(tmp);
    return (res);
}

int need_stat(t_entry **new)
{
    struct stat s;

    if (lstat((*new)->path, &s) == -1 || (!(S_ISLNK(s.st_mode))
        && stat((*new)->path, &s) == -1))
        return (printf("ls: cannot access '%s': %s\n", (*new)->path, strerror(errno)) && 0);
    (*new)->s = (struct stat*)malloc(sizeof(struct stat));
    ft_memcpy((void*)(*new)->s, (void*)&s, sizeof(struct stat));
    return (1);
}

t_entry *create_entry(char *path, char *name, int is_root, int is_dir)
{
    t_entry *new;

    if ((!(ls.opts&OPT_a) && name[0] == '.')
        || !(new = (t_entry*)malloc(sizeof(t_entry))))
        return (NULL);
    new->err = 0;
    new->name = name;
    new->path = is_root ? path : create_pathname(path, name);
    if ((is_root || ls.opts&OPT_l || ls.sk != BY_NAME) && !need_stat(&new))
    {
        free(new);
        return (NULL);
    };
    new->e = NULL;
    new->next = NULL;
    new->is_dir = is_root ? S_ISDIR(new->s->st_mode) : is_dir;
    return (new);
}

t_entry *add_entry(t_entry **e, t_entry *new)
{
    t_entry *current;

    if (!new)
        return (NULL);
    if (!(*e) || (!sort((*e), new)))
    {
        new->next = (*e);
		return ((*e) = new);
    }
    current = (*e);
	while (current->next && sort(current->next, new))
		current = current->next;
	new->next = current->next;
	current->next = new;
    return ((*e));
}