/*
** EPITECH PROJECT, 2019
** unit_test16.c
** File description:
** unit_test16.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "mysh.h"

Test(check_par_3, Return_Value_Test)
{
    char *tb[] = {strdup("foch"), strdup("(x)"), strdup("etst"), NULL};

    cr_assert_eq(check_par(tb), 0);
}

Test(err_handling_foreach_3, Return_Value_Test)
{
    char *tb[] = {strdup("foch"), strdup("x"), strdup("(etst"), NULL};

    cr_assert_eq(err_handling_foreach(tb), -1);
}

Test(err_handling_foreach_6, Return_Value_Test)
{
    char *tb[] = {strdup("foreach"), strdup("x"), strdup("(1 2 3)"), NULL};

    cr_assert_eq(err_handling_foreach(tb), 0);
}

Test(test_create_executable, Return_Value_test)
{
    char *chaine = my_strdup("ls -a \"-l\"");
    char *result[] = {"ls", "-a", "-l", NULL};
    char **result_func = create_executable(chaine);

    cr_assert_str_eq(result_func[0], result[0]);
    cr_assert_str_eq(result_func[1], result[1]);
    cr_assert_str_eq(result_func[2], result[2]);
}

Test(test_execute_executable, Return_Value_test)
{
    sh_t sh;
    char *chaine = my_strdup("ls -a \"-l\"");
    char **exe = create_executable(chaine);

    exe[0] = my_strcat_slash(my_strdup("/bin"), exe[0]);
    sh.path.env = malloc(sizeof(char *) * 2);
    sh.path.env[0] = "PATH=/bin";
    sh.path.env[1] = NULL;
    cr_assert_eq(execute_fonction(exe, &sh), 0);
}