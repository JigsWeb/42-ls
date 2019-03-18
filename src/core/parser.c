#include "../../includes/core.h"

t_ls ls;

static void parse_opts(char const *opts)
{
    int i;

    i = 0;
    while (opts[++i])
    {
        if (opts[i] == 'l')
            ls.opts->l = 1;
        else if (opts[i] == 'a')
            ls.opts->a = 1;
        else if (opts[i] == 'R')
            ls.opts->R = 1;
        else if (opts[i] == 't')
            ls.sk = M_TIME;
        else if (opts[i] == 'r')
            ls.opts->r = 1;
        else
            return ;
    }
}

int check_is_dir(struct stat s, char *name)
{
    return (ls.opts->R
        && S_ISDIR(s.st_mode)
        && strcmp(name, ".")
        && strcmp(name, ".."));
}

// @TODO count folder/entries flr->count_<x>
// @TODO Don't need stat or lstat on option -l
int parse_pathname(char const *p, char *name, t_folder **flr)
{
    struct stat s;
    char        is_dir;
    char        is_lnk;

	printf("SIZEOF %zu\n", sizeof(t_folder));
    is_dir = 0;
    if (((!(*flr)->is_root || ls.opts->l) && lstat(p, &s) == -1)
        || (!(is_lnk = S_ISLNK(s.st_mode)) && stat(p, &s) == -1))
        printf("ls: cannot access '%s': %s\n", p, strerror(errno));
    else if ((*flr)->is_root || ls.opts->a || name[0] != '.')
    {
        is_dir = !is_lnk && check_is_dir(s, name);
        // printf("%s\n", name);
        if (((*flr)->is_root && S_ISDIR(s.st_mode)) || is_dir)
            add_folder(&(*flr)->flr, create_folder((char*)p, s.st_mtime));
        if (!(*flr)->is_root || !is_dir)
            add_entry_sk(&(*flr)->e, create_entry(name, s.st_mtime));
    }
    return (is_dir);
}

int         parse_args(char const *argv[])
{
    int i;

    i = 0;
    while (argv[++i])
        if (argv[i][0] == '-' && argv[i][1])
            parse_opts(argv[i]);
    i = 0;
    while (argv[++i])
        if (argv[i][0] != '-' || !argv[i][1])
            parse_pathname(argv[i], (char *)argv[i], &ls.flr);
    return (1);
}