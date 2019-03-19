#include "../../includes/core.h"

t_ls ls;

static int check_is_dir(struct dirent *dir)
{
    return (ls.opts&OPT_R
        && dir->d_type == _DIR
        && strcmp(dir->d_name, ".")
        && strcmp(dir->d_name, ".."));
}

int traverse(t_entry **flr)
{
    DIR *d;
    struct dirent *dir;
    // t_entry *e;

    if (!*flr)
        return (0);
    if (!(d = opendir((*flr)->path)))
        return (((*flr)->err = errno));
    while((dir = readdir(d)))
        add_entry(&(*flr)->e,
            create_entry((*flr)->path, dir->d_name, 0, check_is_dir(dir)));
    print_folder(*flr);
    closedir(d);
    // e = (*flr)->e;
    // while (e)
    // {
    //     if (e->is_dir)
    //         traverse(&e);
    //     e = e->next;
    // }
    return (1);
}

void init(void)
{
    ls.sk = BY_NAME;
    ls.opts = 0;
    ls.e = NULL;
}

int main(int argc, char const *argv[])
{
    t_entry *e;

    (void)argc;
    init();
    parse_args(argv);
    e = ls.e;
    while (e)
    {
        if (!e->is_dir)
            print_entry(e);
        e = e->next;
    }
    printf("\n");
    e = ls.e;
    while (e)
    {
        if (e->is_dir)
            traverse(&e);
        e = e->next;
    }
    exit(0);
    return 0;
}
