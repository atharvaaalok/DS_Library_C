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
void insert_at_end();
void display();
void print_info_field(node *ptr);
void delete_last_node();


int main(void)
{    
    while(True)
    {
        if (ask_to_add_node() == True)
        {
            insert_at_end();
        }
        else
        {
            break;
        }
        
        
    }

    display();
    delete_last_node();
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




void insert_at_end()
{
    node *ptr;
    ptr = get_node();

    if (ptr == NULL)
    {
        return;
    }

    node *temp = List;

    if (temp == NULL)
    {
        List = ptr;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = ptr;
    ptr->next = NULL;

    return;
}


void display()
{
    node *temp = List;
    if (List == NULL)
    {
        printf("NULL\n");
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


void delete_last_node()
{
    if (List == NULL)
    {
        printf("List is already empty\n");
        return;
    }

    node *temp = List;

    if (List->next == NULL)
    {
        free(List);
        List = NULL;
        return;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return;

}