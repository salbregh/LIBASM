/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: salbregh <salbregh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 14:03:43 by salbregh      #+#    #+#                 */
/*   Updated: 2020/12/25 17:57:34 by salbregh      ########   odam.nl         */
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


	dupreal = strdup(src);
	errorreal = errno; // errno of strdup set after calling the function
	dupmine = ft_strdup(src);
	errormine = errno; // errno of ft_strdup set after calling the function
	printf(BLU"String to duplicate:\n"CYN"%s\n", src);
	printf(BLU"Result of strdup:\n"CYN"%s\n", dupreal);
	if (errorreal != 0)
		printf(BLU"Errno of real strdup "CYN"%s\n", strerror(errorreal));
	printf(BLU"Result of ft_strdup:\n"CYN"%s\n", dupmine);
	if (errormine != 0)
		printf(BLU"Errno of my ft_strdup "CYN"%s\n", strerror(errormine));
	// check if the address is the same
	if (strcmp(src, dupmine) == 0 && (&dupreal != &dupmine))
		printf(GRN"TEST OK\n\n"RESET);
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
		ft_strcmp_test("Hello", "Hello"); // goes wrong when same length
		ft_strcmp_test("", ""); // goes wrong because some length
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
	else
		printf(RED"FUNCTION NOT FOUND\n"RESET);
	return (0);
}