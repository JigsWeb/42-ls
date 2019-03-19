#ifndef LS_ENTRY_H

# include <stdlib.h>
# include <stddef.h>

typedef struct s_entry {
    unsigned int    err;
    int             is_dir;
    struct stat     *s;
    struct s_entry  *e;
    struct s_entry  *next;
    char            *name;
    char            *path;
}               t_entry;

t_entry *create_entry(char *path, char *name, int is_root, int is_dir);
t_entry *add_entry(t_entry **e, t_entry *new);

#endif