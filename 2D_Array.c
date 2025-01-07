#include <stdio.h>
#include <string.h>

int validator(int row, int col){
    if (row > 10 || row < 1)
    {
        printf("invalid input constraint:\n");
        return 0;
    }
    if (col > 101 || col < 1)
    {
        printf("invalid input constraint:\n");
        return 0;
    }
    return 1;
}

void printNames(char s[][101][51], int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%s ", s[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printLongestNames(char s[][101][51], int row, int col, int maxLen){
     for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            int len = strlen(s[i][j]);
            if (len == maxLen)
            {
                printf("%s\n", s[i][j]);
            }
        }
    }
}

int main()
{
    int row, col;
    char s[10][101][51];
    printf("enter row\n");
    scanf("%d", &row);
    printf("enter col\n");
    scanf("%d", &col);
    if(!validator(row, col)){
        return 0;
    }

    int count = 0, maxLen = 0;
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            char str[51];
            scanf("%s", str);
            int len = strlen(str);
            if (len > 50)
            {
                printf("Invalid string: length of name should be less than 50 letters\n");
                return 0;
            }
            if (len > maxLen)
            {
                maxLen = len;
            }
            if (str[0] == 'A' || str[0] == 'E' || str[0] == 'I' || str[0] == 'O' || str[0] == 'U' || str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u')
            {
                count++;
            }
            strcpy(s[i][j], str);
        }
    }

    printNames(s, row, col);

    printf("Number of names starting with vowels: %d\n", count);

    printf("The longest name:");
    printLongestNames(s, row, col, maxLen);

    return 0;
}
