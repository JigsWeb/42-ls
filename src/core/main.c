#include "../../includes/core.h"

t_ls ls;

char *create_pathname(char *name, struct dirent *dir)
{
    char *tmp;
    char *res;

    if (!name)
        return (NULL);
    if (name[strlen(name) - 1] == '/')
        return ft_strjoin(name, dir->d_name);
    tmp = ft_strjoin(name, "/");
    res = create_pathname(tmp, dir);
    free(tmp);
    return (res);
}

int ft_ls(t_folder **flr)
{
    DIR *d;
    struct dirent *dir;

    if (!flr)
        return (0);
    if (!(d = opendir((*flr)->name)))
        return (((*flr)->err = errno));
    while((dir = readdir(d)))
        if(parse_pathname(create_pathname((*flr)->name, dir), dir->d_name, flr))
            ft_ls(&(*flr)->flr);
    print_folder(*flr);
    closedir(d);
    return (1);
}

void init(void)
{
    ls.sk = BY_NAME;
    ls.flr = create_folder(".", 0);
    ls.flr->is_root = 1;
    if (!(ls.opts = (t_opts*)malloc(sizeof(t_opts))))
        exit(1);
    ls.opts->l = 0;
    ls.opts->a = 0;
    ls.opts->R = 0;
    ls.opts->r = 0;
}

int main(int argc, char const *argv[])
{
    t_folder *flr;

    (void)argc;
    init();
    parse_args(argv);
    flr = ls.flr->flr;

    while (flr)
    {
        ft_ls(&flr);
        flr = flr->next;
    }

    return 0;
}
