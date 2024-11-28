#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int ID;
    char Name[51];
    int Age;
} User;

void Create()
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
    scanf("%d", &u1.ID);
    fflush(stdin);
    fgets(u1.Name, 50, stdin);
    fflush(stdin);
    scanf("%d", &u1.Age);
    int len = strlen(u1.Name);

    u1.Name[len - 1] = '\0';

    while (fread(&u2, sizeof(u1), 1, fp))
    {
        if (u2.ID == u1.ID)
        {
            printf("Cannot create user, UNIQUE ID constraint\n");
            exit(1);
        }
    }

    fwrite(&u1, sizeof(u1), 1, fp);
    fclose(fp);
}

void Read()
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
        printf("%d %s %d\n", u1.ID, u1.Name, u1.Age);
    }

    fclose(fp);

    printf("Records read Successfully\n");
}

void Update()
{
    User u1, u2;
    bool flag;
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

    int targetID;
    printf("Enter the ID of user to be updated\n");
    scanf("%d", &targetID);
    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if (u1.ID == targetID)
        {
            flag = 1;
            u2.ID = targetID;
            bool boolName;
            printf("If you want to update name, enter '1' else '0':\n");
            scanf("%d", &boolName);
            if (boolName)
            {
                fflush(stdin);
                printf("Enter new name:\n");
                fgets(u2.Name, 50, stdin);
                int len = strlen(u2.Name);
                u2.Name[len - 1] = '\0';
            }
            else
            {
                strcpy(u2.Name, u1.Name);
            }
            bool boolAge;
            fflush(stdin);
            printf("If you want to update Age, enter '1' else '0':\n");
            scanf("%d", &boolAge);
            if (boolAge)
            {
                printf("Enter new Age:\n");
                scanf("%d", &u2.Age);
            }
            else
            {
                u2.Age = u1.Age;
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

void Delete()
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
    int targetID;
    printf("Enter ID of user to be deleted:\n");
    scanf("%d",&targetID);

    while (fread(&u1, sizeof(u1), 1, fp))
    {
        if (u1.ID != targetID)
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
