#ifndef LS_UTILS_H

# include <stddef.h>
# include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *dest, const char *src);
size_t	ft_strlen(const char *s);
int	    ft_strcmp(char *s1, char *s2);

#endif