#include "../../includes/core.h"

t_ls ls;

char *create_pathname(char *name, struct dirent *dir)
{
    char *tmp;
    char *res;

    if (!name)
        return (NULL);
    if (name[ft_strlen(name) - 1] == '/')
        return ft_strjoin(name, dir->d_name);
    tmp = ft_strjoin(name, "/");
    res = create_pathname(tmp, dir);
    free(tmp);
    return (res);
}

int is_dir(struct dirent *dir)
{
    return (dir->d_type == 4
        && strcmp(dir->d_name, ".") && strcmp(dir->d_name, ".."));
}

int ft_ls(t_folder **flr)
{
    DIR *d;
    struct dirent *dir;

    if (!flr)
        return (0);
    d = opendir((*flr)->path);
    while((dir = readdir(d)))
        parse_pathname(create_pathname((*flr)->path, dir), dir->d_name, &(*flr)->e, &(*flr)->flr);
    closedir(d);
    return (1);
}

int main(int argc, char const *argv[])
{
    (void)argc;
    ls.flr = NULL;
    ls.e = NULL;
    ls.sk = 0;
    ls.opts = (t_opts*)malloc(sizeof(t_opts));
    *((long long*)&ls.opts) = 0;
    parse_args(argv);
    // t_entry *e = NULL;
    // ft_ls(strdup("test/"), &e);

    return 0;
}
