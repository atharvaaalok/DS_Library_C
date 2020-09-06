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
void insert_at_end();
void insert_after_node();
void display_forward();
void display_backward();
void print_info_field(node *ptr);
int compare_info(node *original, node *ptr);

int main(void)
{    
    insert_at_end(); 
    while(True)
    {
        if (ask_to_add_node() == True)
        {
            insert_after_node();
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
    ptr->prev = temp;
    ptr->next = NULL;

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


void insert_after_node()
{
    if (List == NULL)
    {
        printf("List is empty\n");
        return;
    }

    node *ptr;
    ptr = get_node();

    node *node_to_insert_after;
    printf("Enter the values for the node you want to insert after\n");
    node_to_insert_after = get_node();

    if (ptr == NULL)
    {
        return;
    }

    node *temp = List;
    

    while (!(compare_info(temp, node_to_insert_after)) && temp->next != NULL)
    {
        temp = temp->next;
    }


    if (compare_info(temp, node_to_insert_after) == True)
    {
        if (temp->next == NULL)
        {
            temp->next = ptr;
            ptr->prev = temp;
        }
        else
        {
            ptr->next = temp->next;
            ptr->prev = temp;
            temp->next->prev = ptr;
            temp->next = ptr;
        }
    }
    else
    {
        printf("Invalid position\n");
    }

    

    

    return;
}


int compare_info(node *original, node *ptr)
{
    if ((original->info).value == (ptr->info).value)
    {
        return(True);
    }
    else
    {
        return(False);
    }
    
}