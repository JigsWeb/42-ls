#include "../../includes/core.h"

t_ls ls;

static unsigned char    by_mtime(t_entry *current, t_entry *new)
{
    return current->s->st_mtime < new->s->st_mtime;
}

static unsigned char    by_name(t_entry *current, t_entry *new)
{
    return ft_strcmp(current->path, new->path) < 0;
}

int                     sort(t_entry *current, t_entry *new)
{
    unsigned char (*sort_fn[2])(t_entry*, t_entry*);

    sort_fn[BY_NAME] = &by_name;
    sort_fn[BY_MTIME] = &by_mtime;
    return (ls.opts&OPT_r
        ? !(sort_fn[ls.sk](current, new))
        : sort_fn[ls.sk](current, new));
}