#include "../../includes/core.h"

t_ls ls;

static void parse_opts(char const *opts)
{
    int i;

    i = 0;
    while (opts[++i])
    {
        if (opts[i] == 'l')
            ls.opts|=OPT_l;
        else if (opts[i] == 'a')
            ls.opts|=OPT_a;
        else if (opts[i] == 'R')
            ls.opts|=OPT_R;
        else if (opts[i] == 'r')
            ls.opts|=OPT_r;
        else if (opts[i] == 't')
            ls.sk = BY_MTIME;
        else
            return ;             
    }
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
            add_entry(&ls.e, create_entry((char*)argv[i], (char*)argv[i], 1, -1));
    return (1);
}