#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
#define True 1
#define False 0

typedef struct item_element_t
{
    int value;
}item_element;

typedef struct queue_t
{
    item_element items[MAX_SIZE];
    int front;
    int rear;
}queue;


void insert_in_queue(item_element item);
item_element delete_from_queue();
item_element element_to_push_in_queue();
int ask_and_return_option();
void operate_on_choice();
int is_queue_full();
int is_queue_empty();
void display_item_element(item_element item);
void display_queue();
int length_of_queue();


queue q;


int main(void)
{
    q.front = 0;
    q.rear = -1;
    
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
    printf("1)\t Insert\n");
    printf("2)\t Delete\n");
    printf("3)\t Check if queue is EMPTY\n");
    printf("4)\t Check if queue is FULL\n");
    printf("5)\t Display\n");
    printf("6)\t Length of Queue\n");
    printf("7)\t Exit\n");

    int choice;
    scanf("%d", &choice);

    return(choice);

}

void operate_on_choice(int choice)
{
    item_element push_val;
    item_element queue_front_element;

    switch(choice)
        {
            case 1:
            {
                push_val = element_to_push_in_queue();
                insert_in_queue(push_val);
                break;
            }
            case 2:
            {
                if (is_queue_empty())
                {
                    printf("Queue is EMPTY\n");
                    break;
                }
                else
                {
                    queue_front_element = delete_from_queue();
                    display_item_element(queue_front_element);
                    break;
                }
                
            }
            case 3:
            {
                if(is_queue_empty())
                {
                    printf("Queue is EMPTY\n");
                    break;
                }
                else
                {
                    printf("Queue is NOT EMPTY\n");
                    break;
                }
                
            }
            case 4:
            {
                if (is_queue_full())
                {
                    printf("Queue is FULL\n");
                    break;
                }
                else
                {
                    printf("Queue is NOT FULL\n");
                    break;
                }
                
            }
            case 5:
            {
                display_queue();
                break;
            }
            case 6:
            {
                int total_queue_length = length_of_queue();
                printf("Length of Queue is %d\n", total_queue_length);
                break;
            }
            case 7:
            {
                exit(0);
            }
        }

        return;
}


void insert_in_queue(item_element item)
{
    if (q.rear == MAX_SIZE - 1)
    {
        printf("Queue is FULL\n");
        return;
    }

    q.rear += 1;
    q.items[q.rear] = item;

    return;
}


item_element delete_from_queue()
{
    if (q.front > q.rear)
    {
        printf("Queue is already EMPTY\n");
        item_element null_item;
        null_item.value = -111;
        return(null_item);
    }

    q.front += 1;
    
    return(q.items[q.front - 1]);

}


item_element element_to_push_in_queue()
{
    item_element push_item;
    printf("Enter the details of item to put in queue\n");
    printf("Enter the value : ");
    scanf("%d", &(push_item.value));
    return(push_item);
}


int is_queue_full()
{
    if (q.rear == MAX_SIZE - 1)
    {
        return(True);
    }
    else
    {
        return(False);
    }
    
}


int is_queue_empty()
{
    if (q.front > q.rear)
    {
        return(True);
    }
    else
    {
        return(False);
    }
    
}


int length_of_queue()
{
    return(q.rear - q.front + 1);
}


void display_item_element(item_element item)
{
    printf("%d-", item.value);
    return;
}


void display_queue()
{
    for (int i = q.front; i <= q.rear; i++)
    {
        display_item_element(q.items[i]);
    }

    printf("|\n");

    return;
}
