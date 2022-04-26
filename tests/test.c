/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** unit test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "../include/p.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void redirect_all_std(void)
{
    cr_redirect_stdout ();
    cr_redirect_stderr ();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(there_is_op, one_sign)
{
    cr_assert_eq(there_is_op("30+30", "()+-*/%"), 0);
}

Test(my_strcpy , copy_five_characters_in_empty_array)
{
    char dest [6] = {0};

    my_strcpy(dest , "HelloWorld");
    cr_assert_str_eq(dest , "HelloWorld");
}
