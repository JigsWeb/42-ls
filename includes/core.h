#ifndef LS_CORE_H
# define LS_CORE_H 1

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
# include "utils.h"

# define _REG     0x1
# define _BLK     0x2
# define _CHR     0x3
# define _DIR     0x4
# define _FIFO    0x5
# define _LABEL   0x6
# define _LNK     0x7
# define _SOCK    0x8
# define _UNKNOWN 0xf

# define OPT_l      0x1        
# define OPT_a      0x2
# define OPT_R      0x4
# define OPT_r      0x8


typedef enum { BY_NAME, BY_MTIME } sortkey;

typedef struct  s_ls {
    struct s_entry  *e;
    sortkey         sk;
    unsigned char   opts;
}               t_ls;

extern t_ls ls;

int         parse_args(char const *argv[]);
// int         parse_entry(char const *p, char *name, t_entry **e);
int			sort(t_entry *current, t_entry *new);
void        print_entry(t_entry *e);
void        print_folder(t_entry *flr);

#endif