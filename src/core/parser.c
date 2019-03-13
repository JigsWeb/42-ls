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
            ls.opts->t = 1;
        else if (opts[i] == 'r')
            ls.opts->r = 1;
        else
            return ;
    }
}

static void parse_pathname(char const *p)
{
    struct stat s;
    
    if (stat(p, &s) == -1)
        printf("ls: impossible d'accéder à '%s': %s\n", p, strerror(errno));
    else if (S_ISDIR(s.st_mode))
        add_folder(&ls.flr, create_folder((char*)p, s.st_mtime));
    else
        add_entry(&ls.e, create_entry((char*)p, s.st_mtime));
}

int         parse_args(char const *argv[])
{
    int i;

    i = 0;
    while (argv[++i])
        if (argv[i][0] == '-' && argv[i][1])
            parse_opts(argv[i]);
        else
            parse_pathname(argv[i]);
    return (1);
}