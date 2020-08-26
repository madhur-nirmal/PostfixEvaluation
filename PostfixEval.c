/*
Name: Madhur Nirmal
Roll No: 19CE7019
Batch: C/C2
Date of Performance:
*/
#include <stdio.h>
#include <string.h>
#define MAX 50
#define INT_MIN -2147483648

struct stack
{
  int postfix[50];
  int top;
} s1;

void push(int c)
{
  if (s1.top == MAX - 1)
  {
    printf("Stack Overflow");
  }
  else
  {
    s1.postfix[++s1.top] = c;
  }
}
int pop()
{
  if (s1.top == -1)
  {
    printf("Stack Underflow");
    return INT_MIN;
  }
  else
  {
    return s1.postfix[s1.top--];
  }
}

int calculate(int pop1, int pop2, char op)
{
  if (op == '+')
    return pop2 + pop1;
  else if (op == '*')
    return pop2 * pop1;
  else if (op == '-')
    return pop2 - pop1;
  else
    return pop2 / pop1;
}

int evaluate(char input[])
{
  int len = strlen(input);
  int pop1;
  int pop2;
  char temp;

  for (int i = 0; i < len; ++i)
  {
    temp = input[i];
    if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
    {
      pop1 = pop();
      pop2 = pop();
      push(calculate(pop1, pop2, temp));
    }
    else if (temp >= '0' && temp <= '9')
      push(temp - '0');
  }

  return pop();
}
int main()
{
  s1.top = -1;
  char input[50];
  printf("Enter Postfix Expression: ");
  scanf("%s", input);

  printf("Answer: %d", evaluate(input));
  return 0;
}
/*
Output1:
Enter Postfix Expression: 23+56+*
Answer: 55  

Output2:
Enter Postfix Expression: 23*3/6+
Answer: 8

*/
