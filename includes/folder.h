#ifndef LS_FOLDER_H

# include <stdlib.h>
# include <stddef.h>

typedef struct  s_folder {
    char            *path;
    long int        mtime;
    struct s_entry  *e;
    struct s_folder *flr;
    struct s_folder *next;
    struct s_folder *prev;
}               t_folder;

t_folder *create_folder(char *path, long int mtime);
t_folder *add_folder(t_folder **flr, t_folder *new);

#endif