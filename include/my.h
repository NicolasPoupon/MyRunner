/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** prototypes fct
*/

#ifndef _MY_H
    #define _MY_H

int it_is_alphanumeric(char c);
int it_is_alpha(char c);
int it_is_num(char c);
int count_len_alphanumeric(char const *str);
char *delete_non_alphanumeric_char(char const *str, char *str_alpha);

char *fill_str_of0(char *dest, char *src, int size);
void clear_first0(char *str);

int compare_str(char *str1, char *str2);

int count_len_int(int nb);
char *int_to_str(int nb);

int count_space_to_cut(char const *str, int i);
int count_len_of_word(char *str);
int count_number_of_word(char *str);
int nb_char_word(char *str);
char *cpy_nospace(char *dest, char *str_alpha);

char *switch_my_char_int_str(char c, char replace, char *str);
char *decrypt_str_with_key(char *str, char *key);
char *encrypt_str_with_key(char *str, char *key);

char *delete_min_str(char *str);
char *add_minus_str(char *str);

char *find_smallest_strm(char *str1, char *str2);
char *find_bigger_str_min(char *str1, char *str2);

char **free_array_char(char **array);
int **free_array_int(int **array);
int print_array_char(char **array);
int print_array_int(int **array);
int print_array_char_fast(char **array, int size);

char *int_to_str(int nb);

int it_is_prio_sign(char c);
int it_is_a_sign(char c);

int if_neg(char const *str);
int where_start_nbr(char const *str);
long what_is_my_nbr(char const *str, int start, long result);
int check_if_there_isnb(char const *str);
int my_getnbr(char const *str);

void my_putchar(char c);

int calc_put_nbr(int nb);
int my_put_nbr(int nb);

void my_putstr(char const *str);

char *my_revstr(char *str);

void swap_smallest_nb(int *array, int size, int nb_case_to_swap);
void my_sort_int_array(int *array, int size);

char *capitalize_case_char(char *str, int i);
char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);
char *my_strcat_alloc(char *dest, char const *src);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src);
char *my_strndup(char const *src, int start, int end);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

int my_strlen(char const *str);

char *low_case_char(char *str, int i);
char *my_strlowcase(char *str);

int my_strlen_ncat(char const *str);
char *my_strncat(char *dest, char const *src, int n);

char *my_strncpy(char *dest, char const *src, int n);
char *my_strncpy_rev(char *dest, char const *src, int n);

char *up_case_char(char *str, int i);
char *my_strupcase(char *str);

#endif
