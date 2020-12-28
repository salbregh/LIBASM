/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 13:41:35 by salbregh      #+#    #+#                 */
/*   Updated: 2020/12/28 15:44:41 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

# define RED   "\033[1m\33[31m"
# define GRN   "\033[1m\33[32m"
# define YEL   "\033[1m\33[33m"
# define BLU   "\x1B[34m"
# define MAG   "\033[1m\033[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dest, char const *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t count);
ssize_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s);

#endif
