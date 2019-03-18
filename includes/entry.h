#ifndef LS_ENTRY_H

# include <stdlib.h>
# include <stddef.h>

typedef struct s_entry {
    long int        mtime;
    struct s_entry  *prev;
    struct s_entry  *next;
    char            *name;
}               t_entry;

t_entry *create_entry(char *name, long int mtime);
t_entry *add_entry(t_entry **e, t_entry *new);
t_entry *add_entry_sk(t_entry **e, t_entry *new);

#endif