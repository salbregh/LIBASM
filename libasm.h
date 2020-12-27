/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 13:41:35 by salbregh      #+#    #+#                 */
/*   Updated: 2020/12/27 16:20:57 by salbregh      ########   odam.nl         */
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
// Calculates the length of the string s, excluding terminating null byte
// Returns the number of bytes in the string s.
char		*ft_strcpy(char *dest, char const *src);
// Copies the string pointed to by src, including the terminating /0 byte
// to the buffer pointed to by dest. Dest must be large enough to recieve
// the copy.
// Returns a pointer to dest.
int			ft_strcmp(const char *s1, const char *s2);
// Compares the strings s1 and s2, the comparison in done using unsigned
// characters.
// It returns an integer indicating the result of the comparison.
// 0 is s1 and s2 are equal.
// a negative value if s1 is less than s2.
// a positive value if s1 is greater than s2.
ssize_t		ft_write(int fd, const void *buf, size_t count);
// Writes up to count bytes from the buffer poined buf to the file referred
// to by the filedescriptor fd.
// On succes the number of bytes written in returned. Zero indicates that
// nothing was written. On error -1 is returned and errno is set appropriatly.
ssize_t		ft_read(int fd, void *buf, size_t count);
// Attempts to read up to count bytes from file descriptor fd into the buffer
// starting at buf. If count is zero and no error occur read return zero.
// On succes the number of bytes read is returned, zero indicated EOF.
// On error -1 is returned, and errno is set appropriately.
char		*ft_strdup(const char *s);
// Returns a pointers to a new string which is a duplicate of the string s.
// Memory for the new string is obtained with malloc and can be freed with free.
// On a succes strdup returns a pointer to the duplicated string. It returns NULL
// if insufficient memory was available, with errno set to indicate the cause
// of error.

#endif
