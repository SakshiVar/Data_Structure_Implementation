
#include <stdio.h>
#include <stdlib.h>
int v; // every section choice
#define MAX 50
int a[5], pos, elem, item1, item2; // a is an array
int stack_arr[MAX];
int top = -1;
int n = 0; // array size storage
int queue_arr[MAX];
int rear = -1;
int front = -1;
int i; // global loop pointer

struct node
{
    int info;
    struct node *link;
};
struct node *start = NULL;

struct Node
{
    int data;
    struct Node *prev, *next;
};
struct Node *current = NULL;

// ARRAY OPERATIONS.......
void create_Array();
void display_Array();
void insert_Array();
void delete_Array();

// STACKS OPERATION........
void push_Stack(int item1);
int pop_Stack();
int peek_Stack();
int isEmpty_Stack();
int isFull_Stack();
void display_Stack();

// QUEUES OPERATIONS........
void enqueue(int item2);
int dequeue();
int peek_Queue();
void display_Queue();
int isFull_Queue();
int isEmpty_Queue();

// SINGLY LINKED LIST OPERATIONS.......
void createList_SLL();
void traverse_SLL();
void insertAtFirst_SLL();
void insertAtPosition_SLL();
void insertAtEnd_SLL();
void deleteFirst_SLL();
void deletePosition_SLL();
void deleteEnd_SLL();
void mean_SLL();
void reverse_SLL();
void sort_SLL();
void maximum_SLL();

// DOUBLY LINKED LIST OPERATIONS.......
void traverse_DLL();
void insertAtFront_DLL();
void insertAtEnd_DLL();
void insertAtPosition_DLL();
void deleteFirst_DLL();
void deleteEnd_DLL();
void deletePosition_DLL();

/// array functions starting
void create_Array()
{
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    display_Array();
}
void display_Array()
{
    if (n == 0)
    {
        printf("\nNo elements to display");
        return;
    }
    printf("\nArray elements are: ");
    for (i = 0; i < n; i++)
        printf("%d\t ", a[i]);
}
void insert_Array()
{
    if (n == 5)
    {
        printf("\nArray is full. Insertion is not possible");
        return;
    }
    do
    {
        printf("\nEnter a valid position where element to be inserted:    ");
        scanf("%d", &pos);
    } while (pos > n);
    printf("\nEnter the value to be inserted: ");
    scanf("%d", &elem);
    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = elem;
    n = n + 1;
    display_Array();
}
void delete_Array()
{
    if (n == 0)
    {
        printf("\nArray is empty and no elements to delete");
        return;
    }
    do
    {
        printf("\nEnter a valid position from where element to be deleted:    ");
        scanf("%d", &pos);
    } while (pos >= n);
    elem = a[pos];
    printf("\nDeleted element is : %d \n", elem);
    for (i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n = n - 1;
    display_Array();
}
void funcarray()
{
    do
    {
        // printf("ARRAY operations:");
        printf("\n\n~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~");
        printf("\n*1. Create an array of N integers.");
        printf("\n*2. Display of array elements");
        printf("\n*3. Insert eleemnt at a given position");
        printf("\n*4. Delete an element at a given position");
        printf("\n*5. Exit Array list");
        printf("\n\n Enter the choice : ");
        scanf("%d", &v);
        switch (v)
        {
        case 1:
            create_Array();
            break;
        case 2:
            display_Array();
            break;
        case 3:
            insert_Array();
            break;
        case 4:
            delete_Array();
            break;
        case 5:
            v = 0;
            break;
        default:
            printf("Error! The choice is not correct");
            v = 1;
            break;
        }
    } while (v != 0);
}
// array ending

// stack functions starting
void push_Stack(int item1)
{
    if (isFull_Stack())
    {
        printf("\nStack Overflow\n");
        return;
    }
    top = top + 1;
    stack_arr[top] = item1;
}

int pop_Stack()
{
    if (isEmpty_Stack())
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    item1 = stack_arr[top];
    top = top - 1;
    return item1;
}

int peek_Stack()
{
    if (isEmpty_Stack())
    {
        printf("\nStack Underflow\n");
        exit(1);
    }
    return stack_arr[top];
}

int isEmpty_Stack()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull_Stack()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

void display_Stack()
{
    if (isEmpty_Stack())
    {
        printf("\nStack is empty\n");
        return;
    }
    printf("\nStack elements :\n\n");
    for (i = top; i >= 0; i--)
        printf(" %d\n", stack_arr[i]);
    printf("\n");
}

void funcstack()
{
    do
    {
        // printf("Stack operations:");
        printf("\n\n~~~~~~~~~~~~MENU~~~~~~~~~~~~~~");
        printf("\n*1.Push an element in the stack");
        printf("\n*2.Pop an element from the stack");
        printf("\n*3.Display the top element of the stack");
        printf("\n*4.Display all stack elements ");
        printf("\n*5.Exit Stack list");
        printf("\n\n Enter the choice : ");
        scanf("%d", &v);
        switch (v)
        {
        case 1:
            printf("\nEnter the item to be pushed : ");
            scanf("%d", &item1);
            push_Stack(item1);
            break;
        case 2:
            item1 = pop_Stack();
            printf("\nPopped item is : %d\n", item1);
            break;
        case 3:
            printf("\nItem at the top is : %d\n", peek_Stack());
            break;
        case 4:
            display_Stack();
            break;
        case 5:
            v = 0;
            break;
        default:
            printf("Error! The choice is not correct");
            v = 1;
            break;
        }
    } while (v != 0);
}
// stack functions ending

// QUEUE functions starting
void enqueue(int item2)
{
    if (isFull_Queue())
    {
        printf("\nQueue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue_arr[rear] = item2;
}

int dequeue()
{
    int item2;
    if (isEmpty_Queue())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    item2 = queue_arr[front];
    front = front + 1;
    return item2;
}

int peek_Queue()
{
    if (isEmpty_Queue())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    return queue_arr[front];
}

int isEmpty_Queue()
{
    if (front == -1 || front == rear + 1)
        return 1;
    else
        return 0;
}

int isFull_Queue()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

void display_Queue()
{
    if (isEmpty_Queue())
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue is :\n\n");
    for (i = front; i <= rear; i++)
        printf("%d  ", queue_arr[i]);
    printf("\n\n");
}

void funcqueue()
{
    do
    {
        // printf("QUEUE operations:");
        printf("\n\n~~~~~~~~~~~~MENU~~~~~~~~~~~~~~");
        printf("\n*1.Insert in queues");
        printf("\n*2.Delete in queues");
        printf("\n*3.Display element at the front of queue");
        printf("\n*4.Display all elements of the queue");
        printf("\n*5.Exit QUEUE list");
        printf("\n\n Enter the choice : ");
        scanf("%d", &v);
        switch (v)
        {
        case 1:
            printf("\nInput the element for adding in queue : ");
            scanf("%d", &item2);
            enqueue(item2);
            break;
        case 2:
            item2 = dequeue();
            printf("\nDeleted element is  %d\n", item2);
            break;
        case 3:
            printf("\nElement at the front is %d\n", peek_Queue());
            break;
        case 4:
            display_Queue();
            break;
        case 5:
            v = 0;
            break;
        default:
            printf("Error! The choice is not correct");
            v = 1;
            break;
        }
    } while (v != 0);
}
// queue functions ending

// linked list starting
void createList_SLL()
{
    if (start == NULL)
    {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0)
        {
            int data;
            struct node *newnode;
            struct node *temp;
            newnode = malloc(sizeof(struct node));
            start = newnode;
            temp = start;
            printf("\nEnter number to"
                   " be inserted : ");
            scanf("%d", &data);
            start->info = data;

            for (int i = 2; i <= n; i++)
            {
                newnode = malloc(sizeof(struct node));
                temp->link = newnode;
                printf("\nEnter number to"
                       " be inserted : ");
                scanf("%d", &data);
                newnode->info = data;
                temp = temp->link;
            }
        }
        printf("\nThe list is created\n");
    }
    else
        printf("\nThe list is already created\n");
}

// Function to traverse the singly linked list
void traverse_SLL()
{
    struct node *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    // Else print the LL
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        }
    }
}

// Function to insert at the front
// of the linked list
void insertAtFront_SLL()
{
    int data;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
    temp->info = data;

    // Pointer of temp will be
    // assigned to start
    temp->link = start;
    start = temp;
}

// Function to insert at the end of
// the linked list
void insertAtEnd_SLL()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));

    // Enter the number
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);

    // Changes links
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL)
    {
        head = head->link;
    }
    head->link = temp;
}

// Function to insert at any specified
// position in the linked list
void insertAtPosition_SLL()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));

    // Enter the position and data
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);

    // Change Links
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

// Function to delete from the front
// of the linked list
void deleteFirst_SLL()
{
    struct node *temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = start;
        start = start->link;
        free(temp);
    }
}

// Function to delete from the end
// of the linked list
void deleteEnd_SLL()
{
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else
    {
        temp = start;
        while (temp->link != 0)
        {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}

// Function to delete from any specified
// position from the linked list
void deletePosition_SLL()
{
    struct node *temp, *position;
    int i = 1, pos;

    // If LL is empty
    if (start == NULL)
        printf("\nList is empty\n");

    // Otherwise
    else
    {
        printf("\nEnter index : ");

        // Position to be deleted
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;

        // Traverse till position
        while (i < pos - 1)
        {
            temp = temp->link;
            i++;
        }

        // Change Links
        position = temp->link;
        temp->link = position->link;

        // Free memory
        free(position);
    }
}

// Function to find the maximum element
// in the linked list
void maximum_SLL()
{
    int a[10];
    int i;
    struct node *temp;

    // If LL is empty
    if (start == NULL)
        printf("\nList is empty\n");

    // Otherwise
    else
    {
        temp = start;
        int max = temp->info;

        // Traverse LL and update the
        // maximum element
        while (temp != NULL)
        {

            // Update the maximum
            // element
            if (max < temp->info)
                max = temp->info;
            temp = temp->link;
        }
        printf("\nMaximum number "
               "is : %d ",
               max);
    }
}

// Function to find the mean of the
// elements in the linked list
void mean_SLL()
{
    int a[10];
    int i;
    struct node *temp;

    // If LL is empty
    if (start == NULL)
        printf("\nList is empty\n");

    // Otherwise
    else
    {
        temp = start;

        // Stores the sum and count of
        // element in the LL
        int sum = 0, count = 0;
        float m;

        // Traverse the LL
        while (temp != NULL)
        {

            // Update the sum
            sum = sum + temp->info;
            temp = temp->link;
            count++;
        }

        // Find the mean
        m = sum / count;

        // Print the mean value
        printf("\nMean is %f ", m);
    }
}

// Function to sort the linked list
// in ascending order
void sort_SLL()
{
    struct node *current = start;
    struct node *index = NULL;
    int temp;

    // If LL is empty
    if (start == NULL)
    {
        return;
    }

    // Else
    else
    {

        // Traverse the LL
        while (current != NULL)
        {
            index = current->link;

            // Traverse the LL nestedly
            // and find the minimum
            // element
            while (index != NULL)
            {

                // Swap with it the value
                // at current
                if (current->info > index->info)
                {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->link;
            }

            // Update the current
            current = current->link;
        }
    }
}

// Function to reverse the linked list
void reverse_SLL()
{
    struct node *t1, *t2, *temp;
    t1 = t2 = NULL;

    // If LL is empty
    if (start == NULL)
        printf("List is empty\n");

    // Else
    else
    {

        // Traverse the LL
        while (start != NULL)
        {

            // reversing of points
            t2 = start->link;
            start->link = t1;
            t1 = start;
            start = t2;
        }
        start = t1;

        // New head Node
        temp = start;

        printf("Reversed linked list is : ");

        // Print the LL
        while (temp != NULL)
        {
            printf("%d ", temp->info);
            temp = temp->link;
        }
    }
}
void func_SinglyLL()
{
    do
    {
        // printf("LinkedList operations:");
        printf("\n\n~~~~~~~~~~~~MENU~~~~~~~~~~~~~~");
        printf("\n*01.To see the singly linked list");
        printf("\n*02.For insertion at the starting");
        printf("\n*03.For insertion at the end");
        printf("\n*04.For insertion at any position");
        printf("\n*05.For deletion of first element");
        printf("\n*06.For deletion of last element");
        printf("\n*07.For deletion of element at any position");
        printf("\n*08.To find maximum among the elements");
        printf("\n*09.To find mean of the elements");
        printf("\n*10 To sort element");
        printf("\n*11.To reverse the Singly linked list");
        printf("\n*12.Exit Linkedlist Operation");
        printf("\n\n Enter the choice : ");
        scanf("%d", &v);
        switch (v)
        {
        case 1:
            traverse_SLL();
            break;
        case 2:
            insertAtFront_SLL();
            break;
        case 3:
            insertAtEnd_SLL();
            break;
        case 4:
            insertAtPosition_SLL();
            break;
        case 5:
            deleteFirst_SLL();
            break;
        case 6:
            deleteEnd_SLL();
            break;
        case 7:
            deletePosition_SLL();
            break;
        case 8:
            maximum_SLL();
            break;
        case 9:
            mean_SLL();
            break;
        case 10:
            sort_SLL();
            break;
        case 11:
            reverse_SLL();
            break;
        case 12:
            v = 0;
            break;
        default:
            printf("Error! The choice is not correct");
            v = 1;
            break;
        }
    } while (v != 0);
}
// linkedlist functions ending

// Doubly Linked List Function Starting
void traverse_DLL()
{
    // List is empty
    if (current == NULL) {
        printf("\nList is empty\n");
        return;
    }
    // Else print the Data
    struct Node* temp;
    temp = current;
    while (temp != NULL) {
        printf("Value = %d\n", temp->data);
        temp = temp->next;
    }
}
void insertAtFront_DLL()
{
    int value;
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &value);
    temp->data = value;
    temp->prev = NULL;

    // Pointer of temp will be
    // assigned to start
    temp->next = current;
    current = temp;
}

// Function to insert at the end of
// the linked list
void insertAtEnd_DLL()
{
    int value;
    struct Node *temp, *trav;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &value);
    temp->data = value;
    temp->next = NULL;
    trav = current;

    // If start is NULL
    if (current == NULL)
    {

        current = temp;
    }

    // Changes Links
    else
    {
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}

// Function to insert at any specified
// position in the linked list
void insertAtPosition_DLL()
{
    int value, pos, i = 1;
    struct Node *temp, *newnode;
    newnode = malloc(sizeof(struct Node));
    newnode->next = NULL;
    newnode->prev = NULL;

    // Enter the position and value
    printf("\nEnter position : ");
    scanf("%d", &pos);

    // If current==NULL,
    if (current == NULL)
    {
        current = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }

    // If position==1,
    else if (pos == 1)
    {
        // this is author method its correct but we can simply call insertAtfront() function for this special case
        /* newnode->next = current;
         newnode->next->prev = newnode;
         newnode->prev = NULL;
         start = newnode; */
        // now this is improved by Jay Ghughriwala on geeksforgeeks
        insertAtFront_DLL();
    }

    // Change links
    else
    {
        printf("\nEnter number to be inserted: ");
        scanf("%d", &value);
        newnode->data = value;
        temp = current;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
}

// Function to delete from the front
// of the linked list
void deleteFirst_DLL()
{
    struct Node *temp;
    if (current == NULL)
        printf("\nList is empty\n");
    else
    {
        temp = current;
        current = current->next;
        if (current != NULL)
            current->prev = NULL;
        free(temp);
    }
}

// Function to delete from the end
// of the linked list
void deleteEnd_DLL()
{
    struct Node *temp;
    if (current == NULL)
        printf("\nList is empty\n");
    temp = current;
    while (temp->next != NULL)
        temp = temp->next;
    if (current->next == NULL)
        current = NULL;
    else
    {
        temp->prev->next = NULL;
        free(temp);
    }
}

// Function to delete from any specified
// position from the linked list
void deletePosition_DLL()
{
    int pos, i = 1;
    struct Node *temp, *position;
    temp = current;

    // If DLL is empty
    if (current == NULL)
        printf("\nList is empty\n");

    // Otherwise
    else
    {
        // Position to be deleted
        printf("\nEnter position : ");
        scanf("%d", &pos);

        // If the position is the first node
        if (pos == 1)
        {
            deleteFirst_DLL(); 
            if (current != NULL)
            {
                current->prev = NULL;
            }
            free(position);
            return;
        }

        // Traverse till position
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        // Change Links
        position = temp->next;
        if (position->next != NULL)
            position->next->prev = temp;
        temp->next = position->next;

        // Free memory
        free(position);
    }
}
void func_DoublyLL()
{
    int choice;
    do
    {
        // printf("Doubly Linked List Operations");
        printf("\n\n~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~");
        printf("\n*1. For insertion at starting\n");
        printf("\n*2. For insertion at end\n");
        printf("\n*3. For insertion at any position\n");
        printf("\n*4. For deletion offirst element\n");
        printf("\n*5. For deletion of last element\n");
        printf("\n*6. For deletion of element at any position\n");
        printf("\n*7.To exit\n");
        printf("\n\nEnter Choice :");
        scanf("%d", &choice);

        
        switch (v)
        {
        case 1:
            traverse_DLL();
            break;
        case 2:
            insertAtFront_DLL();
            break;
        case 3:
            insertAtEnd_DLL();
            break;
        case 4:
            insertAtPosition_DLL();
            break;
        case 5:
            deleteFirst_DLL();
            break;
        case 6:
            deleteEnd_DLL();
            break;
        case 7:
            deletePosition_DLL();
            break;
        case 8:
            v = 0;
            break;
        default:
            printf("Error! The choice is not correct");
            v = 1;
            break;
        }
    } while (v != 0);
}
// array ending

void print_rectangle(int n, int m)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (i == 1 || i == n || j == 1 || j == m)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    int choice = 0;

    do
    {
        printf("Enter a choice number for the desired function \n");
        printf("1.Arrary\n2.Queue\n3.Stacks \n4.Linked List \n5.Doubly Linked List\n6.Exit \n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // Array Function execution
            funcarray();
            break;
        case 2:
            // queue function execution
            funcqueue();
            break;
        case 3:
            // Stack Function execution
            funcstack();
            break;
        case 4:
            // Singly Linked list function execution
            func_SinglyLL();
            break;
        // case 5:
        // //Singly Linked List execution
        //     func_SinglyLL();
        //     break;
        case 5:
        //Doubly Linked List execution
            func_DoublyLL();
            break;
        case 6:
            choice = 0;
            break;
        default:
            printf("Error! The choice is not correct");
            choice = 1;
            break;
        }
    } while (choice != 0);
    return 0;
}