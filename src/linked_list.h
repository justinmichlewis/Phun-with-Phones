#include <Arduino.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 10
struct Node
{
    char data[MAX_STRING_LENGTH];
    Node *next;
};

struct Node *head = NULL;

// Function to create a new node
Node *createNode(const char *data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strncpy(newNode->data, data, MAX_STRING_LENGTH - 1); // Copy the string
    newNode->data[MAX_STRING_LENGTH - 1] = '\0';         // Ensure null termination
    newNode->next = newNode;                             // Point to itself
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(Node **head, const char *data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    newNode->next = *head; // Point the new node to head
}
// Function to print the circular linked list
void printList(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;
    do
    {
        Serial.print(temp->data); // Use Serial.print for Arduino
        Serial.print(" -> ");
        temp = temp->next;
    } while (temp != head);
    Serial.println("(head)"); // Use Serial.println for a new line
}

// Function to search for a string in the circular linked list
bool searchList(Node *head, const char *target)
{
    if (head == NULL)
        return false;

    Node *temp = head;
    do
    {
        if (strcmp(temp->data, target) == 0)
        {                // Compare strings
            return true; // Found the target
        }
        temp = temp->next;
    } while (temp != head);
    return false; // Target not found
}

bool inLinkedList(char *searchString)
{
    if (searchList(head, searchString))
    {
        Serial.print(searchString);
        Serial.println(" found in the list.");
        return true;
    }
    else
    {
        Serial.print(searchString);
        Serial.println(" not found in the list.");
        return false;
    }
}