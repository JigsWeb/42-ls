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

// @TODO Option a, don't match name befin with dot
// @TODO Recursive condition except for call from parse_args, all in flr, is_root
void parse_pathname(char const *p, char *name, t_entry **e, t_folder **flr)
{
    struct stat s;
    
    if (stat(p, &s) == -1 || (S_ISLNK(s.st_mode) && lstat(p, &s) == -1))
        printf("ls: impossible d'accéder à '%s': %s\n", p, strerror(errno));
    else if (S_ISDIR(s.st_mode))
        add_folder(flr, create_folder((char*)p, s.st_mtime));
    else
        add_entry(e, create_entry(name, s.st_mtime));
}

int         parse_args(char const *argv[])
{
    int i;

    i = 0;
    while (argv[++i])
        if (argv[i][0] == '-' && argv[i][1])
            parse_opts(argv[i]);
        else
            parse_pathname(argv[i], (char *)argv[i], &ls.e, &ls.flr);
    return (1);
}