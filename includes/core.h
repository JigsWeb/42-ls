#ifndef LS_CORE_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <dirent.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>
# include <errno.h>

# include "entry.h"
# include "folder.h"
# include "utils.h"

typedef struct  s_opts {
    unsigned char   l;
    unsigned char   a;
    unsigned char   R;
    unsigned char   t;
    unsigned char   r;
}               t_opts;

typedef struct  s_ls {
    struct s_opts   *opts;
    struct s_folder *flr;
    struct s_entry  *e;
}               t_ls;

extern t_ls ls;

int         parse_args(char const *argv[]);

#endif