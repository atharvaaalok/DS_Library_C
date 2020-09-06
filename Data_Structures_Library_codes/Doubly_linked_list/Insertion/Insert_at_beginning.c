#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define True 1
#define False 0

typedef struct info_field_t
{
    int value;

}info_field;

typedef struct node_t
{
    info_field info;
    struct node_t *prev;
    struct node_t *next;
    
}node;


node *List;


int ask_to_add_node();
node* get_node();
void insert_at_beginning();
void display_forward();
void display_backward();
void print_info_field(node *ptr);

int main(void)
{    
    while(True)
    {
        if (ask_to_add_node() == True)
        {
            insert_at_beginning();
        }
        else
        {
            break;
        }
        
        
    }

    display_forward();
    display_backward();

    return(0);

}




int ask_to_add_node()
{
    char choice;
    printf("Do you want to insert node(y/n) ? ");
    fflush(stdin);
    scanf("%c", &choice);
    if (choice == 'y')
    {
        return(True);
    }
    else if (choice == 'n')
    {
        return(False);
    }
    else
    {
        printf("Incorrect value entered\n");
        int return_val;
        return_val = ask_to_add_node();
        return(return_val);
    }
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

    ptr->prev = NULL;
    ptr->next = NULL;
    return(ptr);

}




void insert_at_beginning()
{
    node *ptr;
    ptr = get_node();

    if (ptr == NULL)
    {
        return;
    }
    
    if (List == NULL)
    {
        List = ptr;
        return;
    }

    List->prev = ptr;
    ptr->next = List;
    List = ptr;

    return;
}



void display_forward()
{
    node *temp = List;

    printf("NULL<=>");

    while (temp != NULL)
    {
        print_info_field(temp);
        temp = temp->next;
    }

    printf("NULL\n");

    return;
}

void display_backward()
{
    node *temp = List;

    if (List == NULL)
    {
        printf("NULL<=>NULL\n");
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("NULL<=>");

    while (temp != NULL)
    {
        print_info_field(temp);
        temp = temp->prev;
    }

    printf("NULL\n");

    return;
}


void print_info_field(node *ptr)
{
    printf("%d<=>", (ptr->info).value);
    return;
}