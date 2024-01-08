#include <iostream>
using namespace std;
class NODE
{
public:
    int value;
    NODE *next; 

    NODE(int data)
    {
        value = data;
        next = NULL;
    }
};
// Function to insert a new node with a given value at the beginning of a linked list
void insertAThead(NODE *&head, int value) 
{
    // Create a new node with the given value
    NODE *new_node = new NODE(value);

    // Set the next pointer of the new node to point to the current head
    new_node->next = head;

    // Update the head to point to the new node, making it the new head
    head = new_node;
}

void insertATtail(NODE *&head, int value) // fuction to insert node at tail
{
    NODE *new_node = new NODE(value); //(DMA)->A new node created with a particular address in the memoery store value and null
    NODE *temp = head;                // created a new node pointer temp to traverse to the tail node to insert new node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node; // putting the address of newly created node in the next box of tail node
}
void insert_AT_Kth_position(NODE *head, int position, int value)
{
    if (position == 0)
    {
        insertAThead(head, value);
        return;
    }
    NODE *temp = head;
    NODE *new_node = new NODE(value);
    int current_position = 0;
    while (current_position != position - 1)
    {
        temp = temp->next;
        current_position++;
    }
    // temp is at k-1;
    new_node->next = temp->next;
    temp->next = new_node;
}
void update_AT_Kthposition(NODE *&head, int position, int value)
{
    NODE *temp = head;
    int current_position = 0;
    while (current_position != position)
    {
        temp = temp->next;
        current_position++;
    }
    // temp is at k position
    temp->value = value;
}
void DeleteAThead(NODE *&head)
{
    NODE *temp = head;
    head = head->next;
    free(temp);
}
void DeleteATtail(NODE *&head)
{
    NODE *second_last = head;
    while (second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }
    // second_last will point at second last node;
    NODE *temp = second_last->next;
    second_last->next = NULL;
    free(temp);
}
void DeleteAT_Kth_position(NODE *&head, int position)
{
    if (position == 0)
    {
        DeleteAThead(head);
        return;
    }
    NODE *onePositionless = head;
    int current = 0;
    while (current != position - 1)
    {
        onePositionless = onePositionless->next;
        current++;
    }
    // onePositionless is pointing to previous node above which comes the node that we have to deleted
    NODE *temp = onePositionless->next; // node to be deleted;
    onePositionless->next = onePositionless->next->next;
    free(temp);
}

void display(NODE *head)
{
    NODE *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void DeleteAlternate1(NODE *&head)
{
    // Initialize two pointers, ptr1 and ptr2, to traverse the linked list
    NODE *ptr1 = head;
    NODE *ptr2 = head->next;

    // Traverse the linked list until either ptr1 or ptr2 becomes NULL
    while (ptr2 != NULL && ptr1 != NULL)
    {
        // Update the next pointer of ptr1 to skip the next node (alternate node)
        ptr1->next = ptr2->next;

        // Store the current node to be deleted in a temporary pointer temp
        NODE *temp = ptr2;

        // Move ptr1 to the next node, skipping the one that was just deleted
        ptr1 = ptr1->next;

        // Check if ptr1 is not NULL to avoid accessing a NULL pointer
        if (ptr1 != NULL)
        {
            // Move ptr2 two steps ahead to the next alternate node
            ptr2 = ptr2->next->next;

            // Free the memory of the node pointed to by temp
            free(temp);
        }
    }
}

// Function to delete alternate nodes from a linked list
void DeleteAlternate2(NODE *head)
{
    // Initialize a pointer to traverse the linked list
    NODE *ptr = head;

    // Traverse the linked list until either ptr or ptr->next becomes NULL
    while (ptr != NULL && ptr->next != NULL)
    {
        // Create a temporary pointer to the next node (alternate node)
        NODE *temp = ptr->next;

        // Update the next pointer of ptr to skip the next node (alternate node)
        ptr->next = ptr->next->next;

        // Free the memory of the node pointed to by temp (delete alternate node)
        free(temp);

        // Move ptr to the next node (either the one after deletion or the end of the list)
        ptr = ptr->next;
    }
}

int main()
{
    NODE *head = NULL;
    display(head);
    insertAThead(head, 2);
    insertAThead(head, 3);
    insertAThead(head, 6);
    insertAThead(head, 8);
    insertAThead(head, 9);
    insertATtail(head, 1);
    display(head);
    DeleteAlternate2(head);

    display(head);
}
