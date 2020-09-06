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
    struct node_t *next;
}node;


node *List;


int ask_to_add_node();
node* get_node();
void insert_at_position_append_allowed();
void insert_at_position_append_unallowed();
void display();
void print_info_field(node *ptr);








int main(void)
{    
    while(True)
    {
        if (ask_to_add_node() == True)
        {
            insert_at_position_append_allowed();
        }
        else
        {
            break;
        }
        
        
    }

    display();

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

    ptr->next = NULL;
    return(ptr);

}




void insert_at_position_append_allowed()
{
    node *ptr;
    ptr = get_node();

    if (ptr == NULL)
    {
        return;
    }

    int position;
    printf("Enter the position you want to insert at : ");
    fflush(stdin);
    scanf("%d", &position);

    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    node *temp = List;
    int count;
    count = 1;

    if (position == 1 && List == NULL)
    {
        ptr->next = List;
        List = ptr;
        return;
    }

    if (position == 1)
    {
        ptr->next = List->next;
        List = ptr;
        return;
    }


    while (count != position && temp != NULL)
    {
        temp = temp->next;
        count += 1;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    ptr->next =  temp->next;
    temp->next  = ptr;

    return;
}


void insert_at_position_append_unallowed()
{
    node *ptr;
    ptr = get_node();

    if (ptr == NULL)
    {
        return;
    }

    int position;
    printf("Enter the position you want to insert at : ");
    fflush(stdin);
    scanf("%d", &position);

    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    node *temp = List;
    int count;
    count = 1;

    if (position == 1 && List == NULL)
    {
        ptr->next = List;
        List = ptr;
        return;
    }

    if (position == 1)
    {
        ptr->next = List->next;
        List = ptr;
        return;
    }

    while (count != position && temp->next != NULL)
    {
        temp = temp->next;
        count += 1;
    }

    if (temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    ptr->next =  temp->next;
    temp->next  = ptr;

    return;
}



void display()
{
    node *temp = List;
    if (List == NULL)
    {
        printf("NULL");
        return;
    }

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