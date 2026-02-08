#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char **array1(char rightline);
char **array2(char rightline);
char **array3(char rightline);
char **array4(char rightline);

int main(int argc, char **argv)
{
    char    ***all_the_options;
    int i;
    char **matrix;
    matrix = malloc(4 * sizeof(char *));
    free(matrix);
    i = 0;
    while (i < 4)
    {
        if (argc != 2)
            return(0);
        if(argv[1][16 + 2 * i] == '1')
            all_the_options[i] = &(array1(argv[1][24 + 2 * i]));
        if(argv[1][16 + 2 * i] == '2')
            all_the_options[i] = &(array2(argv[1][24 + 2 * i]));
        if(argv[1][16 + 2 * i] == '3')
            all_the_options[i] = &(array3(argv[1][24 + 2 * i]));
        if(argv[1][16 + 2 * i] == '4')
            all_the_options[i] = &(array4(argv[1][24 + 2 * i]));
        else
            return(ERROR);
        i++;
    }
    while_loops(all_the_options);
    return(0);
}

char **array1(char rightline)
{
    char **result;
    char *array12[] = {"4123","4213"};
    char *array13[] = {"4132","4312","4231"};
    char *array14[] = {"4321"};

    if (rightline == '2')
    {
        result = malloc(3 * sizeof(char *));
        result = array12;
    }
    if (rightline == '3')
    {
        result = malloc(4 * sizeof(char *));
        result = array13;
    }
    if (rightline == '4')
    {
        result = malloc(2 * sizeof(char *));
        result = array14;
    }
    return(result);
}

char **array2(char rightline)
{
    char **result;
    char *array22[] = {"1423","2413","2143","3412","3142","3241"};
    char *array23[] = {"1432","2431","3421"};
    char *array21[] = {"3214","3124"};

    if (rightline == '2')
    {
        result = malloc(7 * sizeof(char *));
        result = array22;
    }
    if (rightline == '3')
    {
        result = malloc(4 * sizeof(char *));
        result = array23;
    }
    if (rightline == '1')
    {
        result = malloc(3 * sizeof(char *));
        result = array21;
    }
    return(result);
}

char **array3(char rightline)
{
    char **result;
    char *array31[] = {"2314","2134","1324", NULL};
    char *array32[] = {"2341","1342","1243", NULL};

    if (rightline == '1')
    {
        result = malloc(4 * sizeof(char *));
        result = array31;
    }
    if (rightline == '3')
    {
        result = malloc(4 * sizeof(char *));
        result = array32;
    }

    return(result);
}

char **array4(char rightline)
{
    char **result;
    char *array41[] = {"1234", NULL};

    if (rightline == '1')
    {
        result = malloc(2 * sizeof(char *));
        result = array41;
    }
    return(result);
}

int validacaofinal(**matrix,char **argv)
{
    int i;
    char *coluna1 = {matrix[0][0],matrix[1][0],matrix[2][0],matrix[3][0]};
    char *coluna2 = {matrix[0][1],matrix[1][1],matrix[2][1],matrix[3][1]};
    char *coluna3 = {matrix[0][2],matrix[1][2],matrix[2][2],matrix[3][2]};
    char *coluna4 = {matrix[0][3],matrix[1][3],matrix[2][3],matrix[3][3]};

    while (i < 4)
    {
        if(argv[1][2 * i] == '1')
            
        if(argv[1][2 * i] == '2')
            
        if(argv[1][2 * i] == '3')
            
        if(argv[1][2 * i] == '4')
            
    
    }
}

