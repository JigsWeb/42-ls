#include "../../includes/core.h"

t_ls ls;

void print_entry(t_entry *e)
{
    if (!ls.opts->l)
        printf("%s ", e->name);
    else {
        printf("%s\n", e->name);
    }
    return ;
}

void print_folder(t_folder *flr)
{
    t_entry *e;

    e = flr->e;
    if (!flr->is_root)
        printf("%s:\n", flr->path);
    while (e)
    {
        print_entry(e);
        e = e->next;
    }
    if (!ls.opts->l)
        printf("\n");
    printf("\n");
}