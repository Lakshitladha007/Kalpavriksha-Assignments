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
    User user1, user2;
    FILE *fp;
    fp = fopen("users.txt", "a+");

    if (fp == NULL)
    {
        printf("Cannot open file\n");
        return;
    }

    printf("Enter ID, name and Age of user:\n");
    scanf("%d", &user1.id);
    fflush(stdin);
    fgets(user1.name, 50, stdin);
    fflush(stdin);
    scanf("%d", &user1.age);
    int len = strlen(user1.name);

    user1.name[len - 1] = '\0';

    while (fread(&user2, sizeof(user1), 1, fp))
    {
        if (user2.id == user1.id)
        {
            printf("Cannot create user, UNIQUE ID constraint\n");
            return;
        }
    }

    fwrite(&user1, sizeof(user1), 1, fp);
    fclose(fp);

}

void readUser()
{
    User user1;
    FILE *fp;
    fp = fopen("users.txt", "a+");
    
    if (fp == NULL)
    {
        printf("Cannot open file\n");
        return;
    }

    while (fread(&user1, sizeof(user1), 1, fp))
    {
        printf("%d %s %d\n", user1.id, user1.name, user1.age);
    }

    fclose(fp);

    printf("Records read Successfully\n");

}

void updateUser()
{
    User user1, user2;
    bool flag=0;
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
    while (fread(&user1, sizeof(user1), 1, fp))
    {
        if (user1.id == targetId)
        {
            flag = 1;
            user2.id = targetId;
            bool boolName;
            printf("If you want to update name, enter '1' else '0':\n");
            scanf("%d", &boolName);
            if (boolName)
            {
                fflush(stdin);
                printf("Enter new name:\n");
                fgets(user2.name, 50, stdin);
                int len = strlen(user2.name);
                user2.name[len - 1] = '\0';
            }
            else
            {
                strcpy(user2.name, user1.name);
            }
            bool boolAge;
            fflush(stdin);
            printf("If you want to update Age, enter '1' else '0':\n");
            scanf("%d", &boolAge);
            if (boolAge)
            {
                printf("Enter new Age:\n");
                scanf("%d", &user2.age);
            }
            else
            {
                user2.age = user1.age;
            }
            fwrite(&user2, sizeof(user2), 1, tp);
        }
        else
        {
            fwrite(&user1, sizeof(user1), 1, tp);
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
        printf("Cannot update user, as user with given ID does not exist\n");
    }

}

void deleteUser()
{
    User user1;
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

    bool flag = 0;
    int targetId;
    printf("Enter ID of user to be deleted:\n");
    scanf("%d",&targetId);

    while (fread(&user1, sizeof(user1), 1, fp))
    {
        if (user1.id != targetId)
        {
            fwrite(&user1, sizeof(user1), 1, tp);
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

