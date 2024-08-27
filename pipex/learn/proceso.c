#include "pipex.h"

int main(int argc, char *argv[])
{
    int i;

    i = 0;
    ft_printf("%s : %i \n", argv[0], getpid());
    while (i < argc)
    {
        ft_printf("argumento %d = %s\n", i, argv[i]);
        i++;
    }
    return (0);
}