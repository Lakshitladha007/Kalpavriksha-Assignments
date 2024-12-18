#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include<limits.h>

void removeSpaces(char *inputString)
{
  int currentChar = 0;
  for (int index = 0; index < strlen(inputString); index++)
  {
    if (inputString[index] != ' ')
    {
      inputString[currentChar] = inputString[index];
      currentChar++;
    }
  }
  currentChar--;
  inputString[currentChar] = '\0';
  return;

}

int validateString(char *inputString)
{
  for (int index = 0; inputString[index] != '\0'; index++)
  {
    char currentCharacter = inputString[index];
    if (!isdigit(currentCharacter))
    {
      if (currentCharacter != '+' && currentCharacter != '-' && currentCharacter != '*' && currentCharacter != '/')
      {
        return 0;
      }
    }
  }
  return 1;

}

int calculate(char *inputString)
{
  int stack[300000];
  int top = -1;
  char operator= '+';
  int num = 0;

  for (int index = 0; index < strlen(inputString); index++)
  {
    if (isdigit(inputString[index]))
    {
      num = num * 10 + (inputString[index] - '0');
    }
    if (!isdigit(inputString[index]) || inputString[index + 1] == '\0')
    {
      if (operator== '+')
      {
        top++;
        stack[top] = num;
      }
      else if (operator== '-')
      {
        top++;
        stack[top] = num * -1;
      }
      else if (operator== '*')
      {
        int temp = stack[top];
        temp = temp * num;
        stack[top] = temp;
      }
      else if (operator== '/')
      {
        int temp = stack[top];
        if(num==0){
          printf("Divide by Zero Exception!\n");
          return INT_MIN;
        }
        temp = temp / num;
        stack[top] = temp;
      }
      operator= inputString[index];
      num = 0;
    }
  }

  int result = 0;
  for (int index = 0; index <= top; index++)
  {
    result += stack[index];
  }
  return result;

}

int main()
{
  char inputString[300000];
  printf("Enter the string you want to evaluate:\n");
  fgets(inputString, sizeof(inputString), stdin);

  removeSpaces(inputString);

  if (validateString(inputString) == 0)
  {
    printf("Error! Invalid Input\n");
    return 0;
  }
  
  int result=calculate(inputString);
  if(result!=INT_MIN){
  printf("The result is:%d\n",result );
  }
  return 0;

}
