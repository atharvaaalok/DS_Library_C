#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define True 1
#define False 0

typedef struct item_element_t
{
    int value;

}item_element;

typedef struct node_t
{
    item_element info;
    struct node_t *next;
    
}node;


node *Front = NULL;
node *Rear = NULL;


int ask_and_return_option();
void operate_on_choice();
node* get_node();
void insert_at_end();
node* delete_from_queue();
int is_queue_empty();
void print_info_field(node *ptr);
void display_queue();
int length_of_queue();


int main(void)
{    
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
    node* queue_front_element;

    switch(choice)
        {
            case 1:
            {
                insert_at_end();
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
                    print_info_field(queue_front_element);
                    free(queue_front_element);
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
                printf("Queue is NOT FULL\n");
                break;
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


node* get_node()
{
    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Memory is full");
        return(NULL);
    }

    printf("Enter the info for the node : ");
    scanf("%d", &((ptr->info).value));

    ptr->next = NULL;
    return(ptr);

}


void insert_at_end()
{

    node *ptr;
    ptr = get_node();

    if (ptr == NULL)
    {
        return;
    }


    if (Rear == NULL)
    {
        Rear = ptr;
        Front = ptr;
        return;
    }

    
    Rear->next = ptr;
    ptr->next = NULL;
    Rear = ptr;

    return;
}

int is_queue_empty()
{
    if (Rear == NULL)
    {
        return(True);
    }
    else
    {
        return(False);
    }
}


void display_queue()
{
    node *temp = Front;

    while (temp != NULL)
    {
        print_info_field(temp);
        temp = temp->next;
    }

    printf("NULL\n");

    return;
}


void print_info_field(node *ptr)
{
    printf("%d->", (ptr->info).value);
    return;
}


int length_of_queue()
{
    node *temp = Front;

    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count += 1;
    }

    return(count);
}


node* delete_from_queue()
{
    if (Front == Rear)
    {
        node *temp = Front;
        Front = NULL;
        Rear = NULL;
        return(temp);
    }
    node *temp = Front;
    Front = temp->next;

    return(temp);

}