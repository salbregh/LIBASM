/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 14:03:43 by salbregh      #+#    #+#                 */
/*   Updated: 2020/12/28 15:43:51 by salbregh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** TEST MAIN LIBASM
*/

#include "libasm.h"

int     ft_strcmp_test(char *s1, char *s2)
{
    int     ret1;
    int     ret2;

    ret1 = ft_strcmp(s1, s2);
    ret2 = strcmp(s1, s2);
    printf(BLU"String 1: "CYN"%s\n"BLU"String 2: "CYN"%s\n", s1, s2);
	printf(BLU"Value of ft_strcmp: "CYN"%d\n", ret1);
	printf(BLU"Value of strcmp: "CYN"%d\n"RESET, ret2);
    if (ret1 == ret2)
        printf(GRN"TEST OK\n\n"RESET);
    else
		printf(RED"TEST FAIL\n\n"RESET);
    return (0);
}

int		ft_strlen_test(char *str)
{
	int		ret1;
	int		ret2;
	
	if (str == NULL)
		str = "(null)";
	ret1 = ft_strlen(str);
	ret2 = strlen(str);
	printf(BLU"String: "CYN"%s\n"RESET, str);
	printf(BLU"Length of ft_strlen: "CYN"%d\n", ret1);
	printf(BLU"Length of strlen: "CYN"%d\n"RESET, ret2);
	if (ret1 == ret2)
		printf(GRN"TEST OK\n\n"RESET);
	else
		printf(RED"TEST FAIL\n\n"RESET);
	return (0);
}

void	ft_strcpy_test(char *src)
{
	char	dstreal[100];
	char	dstmine[100];

	bzero(dstreal, 100);
	bzero(dstmine, 100);
	printf(BLU"String to copy:\n"CYN"%s\n"RESET, src);
	printf(BLU"Result of strcpy:\n"CYN"%s\n", strcpy(dstreal, src));
	printf(BLU"Result of ft_strcpy:\n"CYN"%s\n"RESET, ft_strcpy(dstmine, src));
	if (strcmp(dstmine, dstreal) == 0)
		printf(GRN"TEST OK\n\n"RESET);
	else
		printf(RED"TEST FAIL\n\n"RESET);
}

void	ft_strdup_test(char *src)
{
	char	*dupreal;
	char	*dupmine;
	int		errorreal;
	int		errormine;

	errno = 0;
	dupreal = strdup(src);
	errorreal = errno;
	dupmine = ft_strdup(src);
	errno = 0;
	errormine = errno;
	printf(BLU"String to duplicate:\n"CYN"%s\n", src);
	printf(BLU"Result of strdup:\n"CYN"%s\n", dupreal);
	if (errorreal != 0)
		printf(BLU"Errno of real strdup "CYN"%s\n", strerror(errorreal));
	printf(BLU"Result of ft_strdup:\n"CYN"%s\n", dupmine);
	if (errormine != 0)
		printf(BLU"Errno of my ft_strdup "CYN"%s\n", strerror(errormine));
	if (strcmp(src, dupmine) == 0 && (&dupreal != &dupmine) && errormine == errorreal)
		printf(GRN"TEST OK\n\n"RESET);
	else
		printf(RED"TEST FAIL\n"RESET);
}

void	ft_write_test(int fd, char *buf, size_t count)
{
	int		errorreal;
	int		errormine;
	int		returnreal;
	int		returnmine;

	errno = 0;
	printf(YEL"\nOfficial write function: \n"RESET);
	printf(BLU"To be written:\n");
	if (fd != 1)
		printf("%s\n", buf);
	printf("\nReturn of write: %d\n", returnreal = write(fd, buf, count));
	errorreal = errno;
	if (errorreal != 0)
		printf("Error real:\n%d, %s\n", errorreal, strerror(errorreal));
	errno = 0;
	printf(YEL"\nMy write function: \n"RESET);
	printf(CYN"To be written:\n");
	if (fd != 1)
		printf("%s\n", buf);
	printf("\nReturn of write: %d\n", returnmine = ft_write(fd, buf, count));
	errormine = errno;
	if (errormine != 0)
		printf("Error mine:\n%d, %s\n", errormine, strerror(errormine));
	if (returnmine == returnreal && errormine == errorreal)
		printf(GRN"\nTEST OK\n"RESET);
	else
		printf(RED"\nTEST FAIL\n"RESET);
}

void	ft_read_test(int fd, int fd2, char *buf, size_t count)
{
	int		errorreal;
	int		errormine;
	int		returnreal;
	int		returnmine;

	errno = 0;
	printf(YEL"\nOfficial read function\n"RESET);
	returnreal = read(fd, buf, count);
	errorreal = errno;
	printf(BLU"Return real:\n"CYN"%d\n"RESET, returnreal);
	if (errorreal != 0)
		printf(BLU"Error real:\n"CYN"%d: %s\n"RESET, errorreal, strerror(errorreal));
	errno = 0;
	printf(YEL"My read function\n"RESET);
	returnmine = ft_read(fd2, buf, count);
	errormine = errno;
	printf(BLU"Return mine:\n"CYN"%d\n", returnmine);
	if (errormine != 0)
		printf(BLU"Error mine:\n"CYN" %d: %s\n"RESET, errormine, strerror(errormine));
	if (errormine == errorreal && returnreal == returnmine)
		printf(GRN"TEST OK\n\n"RESET);
	else
		printf(RED"TEST FAIL\n\n"RESET);
	close(fd);
		close(fd2);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf(MAG"\nGive as argmument which funtion to test:\n"RESET);
		printf("For example: ./test strlen\n\n");
		printf(YEL"- strlen\n- strcmp\n- strcpy\n- strdup\n- write\n- read\n\n"RESET);
		return (0);
	}
	if (ft_strcmp(argv[1], "strlen") == 0)
	{
		printf(MAG"---------------\n");
		printf("| TEST STRLEN |\n");
		printf("---------------\n\n"RESET);
		ft_strlen_test("test");
		ft_strlen_test("loooooooooooooooooooooong string");
		ft_strlen_test(NULL);
		return (0);
	}
	if (ft_strcmp(argv[1], "strcmp") == 0)
	{
		printf(MAG"---------------\n");
		printf("| TEST STRCMP |\n");
		printf("---------------\n\n"RESET);	
		ft_strcmp_test("Hello", "Hello");
		ft_strcmp_test("", "");
		ft_strcmp_test("Hello", "");
		ft_strcmp_test("", "Hello");
		ft_strcmp_test("HOI", "hoi");
		ft_strcmp_test("longer", "long");
		ft_strcmp_test("long", "longer");
		return (0);
	}
	if (ft_strcmp(argv[1], "strcpy") == 0)
	{
		printf(MAG"---------------\n");
		printf("| TEST STRCPY |\n");
		printf("---------------\n\n"RESET);
		ft_strcpy_test("Halloooooo");
		ft_strcpy_test("\0");
		ft_strcpy_test("\nnewline");
		ft_strcpy_test("laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaange test     hier");
		return (0);
	}
	if (ft_strcmp(argv[1], "strdup") == 0)
	{
		printf(MAG"---------------\n");
		printf("| TEST STRDUP |\n");
		printf("---------------\n\n"RESET);
		ft_strdup_test("Halloooooooooooo");
		ft_strdup_test("");
		ft_strdup_test("loooooooooooooooooooooooooooooooooooong");
		ft_strdup_test("test\nthis");
		return (0);
	}
	if (ft_strcmp(argv[1], "write") == 0)
	{
		printf(MAG"--------------\n");
		printf("| TEST WRITE |\n");
		printf("--------------\n"RESET);
		ft_write_test(1, "Hellooo\n", 8);
		ft_write_test(1, "Hellooo\n", 2);
		ft_write_test(6, "TEST\n", 10);
		ft_write_test(1, "TEST\n", -1);
		int		fd;
		fd = open("text", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		if (fd < 0)
			return (-1);
		ft_write_test(fd, "WRITE IN TEST FILE\n", 19);
		ft_write_test(fd, "one more line\n", 14);
		close(fd);
		return (0);
	}
	if (ft_strcmp(argv[1], "read") == 0)
	{
		char	buf[100];
		int		fd;
		int		fd2;
		
		printf(MAG"-------------\n");
		printf("| TEST READ |\n");
		printf("-------------\n\n"RESET);
		bzero(buf, sizeof(buf));
		fd = open("readfile", O_RDONLY, O_CREAT | O_TRUNC, S_IRWXU);
		fd2 = open("readfile", O_RDONLY, O_CREAT | O_TRUNC, S_IRWXU);
		ft_read_test(fd, fd2, buf, 15);
		bzero(buf, sizeof(buf));
		fd = open("readfile", O_RDONLY, O_CREAT | O_TRUNC, S_IRWXU);
		fd2 = open("readfile", O_RDONLY, O_CREAT | O_TRUNC, S_IRWXU);
		ft_read_test(fd, fd2, buf, 10);
		bzero(buf, sizeof(buf));
		fd = open("readfile", O_RDONLY, O_CREAT | O_TRUNC, S_IRWXU);
		fd2 = open("readfile", O_RDONLY, O_CREAT | O_TRUNC, S_IRWXU);
		ft_read_test(fd, fd2, buf, -1);
		bzero(buf, sizeof(buf));
		ft_read_test(42, 42, buf, 100);
		bzero(buf, sizeof(buf));
		fd = open("readfile", O_RDONLY, O_CREAT | O_TRUNC, S_IRWXU);
		fd2 = open("readfile", O_RDONLY, O_CREAT | O_TRUNC, S_IRWXU);
		ft_read_test(fd, fd2, buf, 0);
		return (0);
	}

	else
		printf(RED"FUNCTION NOT FOUND\n"RESET);
	return (0);
}