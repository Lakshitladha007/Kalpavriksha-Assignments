#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int id;
    char name[51];
    int age;
} User;

void createUser()
{
    fflush(stdin);
    User u1, u2;
    FILE *fp;
    fp = fopen("users.txt", "a+");

    if (fp == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    printf("Enter ID, name and Age of user:\n");
    scanf("%d", &u1.id);
    fflush(stdin);
    fgets(u1.name, 50, stdin);
    fflush(stdin);
    scanf("%d", &u1.age);
    int len = strlen(u1.name);

    u1.name[len - 1] = '\0';

    while (fread(&u2, sizeof(u1), 1, fp))
    {
        if (u2.id == u1.id)
        {
            printf("Cannot create user, UNIQUE ID constraint\n");
            exit(1);
        }
    }

    fwrite(&u1, sizeof(u1), 1, fp);
    fclose(fp);

}

void readUser()
{
    User u1;
    FILE *fp;
    fp = fopen("users.txt", "a+");
    
    if (fp == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    while (fread(&u1, sizeof(u1), 1, fp))
    {
        printf("%d %s %d\n", u1.id, u1.name, u1.age);
    }

    fclose(fp);

    printf("Records read Successfully\n");

}

void updateUser()
{
    User u1, u2;
    bool flag;
    FILE *fp, *tp;
    fp = fopen("users.txt", "r+");
    tp = fopen("temp.txt", "w+");

    if (fp == NULL)
    {
        printf("Cannot open file\n");
        return;
    }

    if (tp == NULL)
    {
        printf("Cannot open file\n");
        return;
    }

    int targetId;
    printf("Enter the ID of user to be updated\n");
    scanf("%d", &targetId);
    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if (u1.id == targetId)
        {
            flag = 1;
            u2.id = targetId;
            bool boolName;
            printf("If you want to update name, enter '1' else '0':\n");
            scanf("%d", &boolName);
            if (boolName)
            {
                fflush(stdin);
                printf("Enter new name:\n");
                fgets(u2.name, 50, stdin);
                int len = strlen(u2.name);
                u2.name[len - 1] = '\0';
            }
            else
            {
                strcpy(u2.name, u1.name);
            }
            bool boolAge;
            fflush(stdin);
            printf("If you want to update Age, enter '1' else '0':\n");
            scanf("%d", &boolAge);
            if (boolAge)
            {
                printf("Enter new Age:\n");
                scanf("%d", &u2.age);
            }
            else
            {
                u2.age = u1.age;
            }
            fwrite(&u2, sizeof(u2), 1, tp);
        }
        else
        {
            fwrite(&u1, sizeof(u1), 1, tp);
        }
    }

    fclose(fp);
    fclose(tp);

    if (flag)
    {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("Record updated successfully.\n");
    }
    else
    {
        printf("Cannot update user, as user with given ID doesnot exist\n");
    }

}

void deleteUser()
{
    User u1;
    FILE *fp, *tp;
    fp = fopen("users.txt", "r+");
    tp = fopen("temp.txt", "w+");

    if (fp == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    if (tp == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    bool flag = 0;
    int targetId;
    printf("Enter ID of user to be deleted:\n");
    scanf("%d",&targetId);

    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if (u1.id != targetId)
        {
            fwrite(&u1, sizeof(u1), 1, tp);
        }
        else
        {
            flag = 1;
        }
    }

    fclose(fp);
    fclose(tp);

    if (flag)
    {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("Record deleted successfully.\n");
    }
    else
    {
        printf("Can't delete user, as User with given ID does not Exist\n");
    }

}

int main()
{
   return 0;
}
