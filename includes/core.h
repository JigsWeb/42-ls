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

typedef enum { BY_NAME, M_TIME } sortkey;

typedef struct  s_opts {
    unsigned char   l:1;
    unsigned char   a:1;
    unsigned char   R:1;
    unsigned char   r:1;
}               t_opts;

typedef struct  s_ls {
    struct s_opts   *opts;
    struct s_folder *flr;
    sortkey         sk;
}               t_ls;

extern t_ls ls;

int         parse_args(char const *argv[]);
int         parse_pathname(char const *p, char *name, t_folder **flr);
void        print_entry(t_entry *e);
void        print_folder(t_folder *flr);

#endif