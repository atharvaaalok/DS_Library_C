#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10
#define True 1
#define False 0

typedef struct item_element_t
{
    int value;

}item_element;

typedef struct Stack_t
{
    int top;
    item_element items[MAX_STACK_SIZE];

}Stack;


void push(item_element push_val);
item_element element_to_push_in_stack();
item_element pop();
item_element peep();
int is_stack_full();
int is_stack_empty();
void display_stack();
int ask_and_return_option();
void operate_on_choice();

Stack s;

int main(void)
{
    s.top = -1;

    int choice;

    while(True)
    {
        choice = ask_and_return_option();

        operate_on_choice(choice);        

    }

    return(0);
    
}





int ask_and_return_option()
{
    printf("Select your option : \n");
    printf("1)\t Push\n");
    printf("2)\t Pop\n");
    printf("3)\t Peep\n");
    printf("4)\t Check if stack is empty\n");
    printf("5)\t Check if stack is full\n");
    printf("6)\t Display\n");
    printf("7)\t Exit\n");

    int choice;
    scanf("%d", &choice);

    return(choice);

}




void operate_on_choice(int choice)
{
    item_element push_val;
    item_element stack_top_element;

    switch(choice)
        {
            case 1:
            {
                push_val = element_to_push_in_stack();
                push(push_val);
                break;
            }
            case 2:
            {
                if (is_stack_empty())
                {
                    printf("Stack is empty\n");
                    break;
                }
                else
                {
                    stack_top_element = pop();
                    printf("%d\n", stack_top_element.value);
                    break;
                }
                
            }
            case 3:
            {
                if (is_stack_empty())
                {
                    printf("Stack is empty\n");
                    break;
                }
                else
                {
                    stack_top_element = peep();
                    printf("%d\n", stack_top_element.value);
                    break;
                }
                
                
            }
            case 4:
            {
                if(is_stack_empty())
                {
                    printf("Stack is EMPTY\n");
                    break;
                }
                else
                {
                    printf("Stack is NOT EMPTY\n");
                    break;
                }
                
            }
            case 5:
            {
                if (is_stack_full())
                {
                    printf("Stack is FULL\n");
                    break;
                }
                else
                {
                    printf("Stack is NOT FULL\n");
                    break;
                }
                
            }
            case 6:
            {
                display_stack();
                break;
            }
            case 7:
            {
                exit(0);
            }
        }

        return;
}




item_element element_to_push_in_stack()
{
    item_element push_val;
    printf("Enter details of item you want to enter : \n");
    scanf("%d", &(push_val.value));

    return(push_val);

}



int is_stack_full()
{
    if (s.top == MAX_STACK_SIZE - 1)
    {
        return(True);
    }
    else
    {
        return(False);
    }
    
}

int is_stack_empty()
{
    if (s.top == -1)
    {
        return(True);
    }
    else
    {
        return(False);
    }
    
}

void display_stack()
{
    if (is_stack_empty())
    {
        printf("TOP\n");
        printf("BOTTOM\n");
        printf("Stack is EMPTY\n");
        return;
    }

    printf("TOP\n");

    for (int position = s.top; position > -1; position--)
    {
        printf("%d\n", (s.items[position]).value);
    }

    printf("BOTTOM\n");

    return;
}


void push(item_element push_element)
{
    if (s.top == MAX_STACK_SIZE - 1)
    {
        printf("Stack is FULL\n");
        return;
    }


    s.top += 1;
    s.items[s.top] = push_element;

    return;

}


item_element pop()
{
    if (s.top == -1)
    {
        printf("Stack is EMPTY\n");
        return(s.items[s.top + 1]);
    }

    s.top -= 1;
    return(s.items[s.top + 1]);

}

item_element peep()
{
    if (s.top == -1)
    {
        printf("Stack is EMPTY\n");
        return(s.items[s.top]);
    }

    return(s.items[s.top]);

}
