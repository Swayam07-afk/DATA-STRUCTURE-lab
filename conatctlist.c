#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[20];
    char phone[20];
    struct contact *next;
};

struct contact *head = NULL;

// Insert at beginning
void insertBeg() {
    struct contact *newcontact = (struct contact*)malloc(sizeof(struct contact));
    if (newcontact == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %19[^\n]", newcontact->name);

    printf("Enter phone number: ");
    scanf(" %19[^\n]", newcontact->phone);

    newcontact->next = head;
    head = newcontact;

    printf("Contact inserted at beginning.\n");
}

// Insert at end
void insertEnd() {
    struct contact *newcontact = (struct contact*)malloc(sizeof(struct contact));
    if (newcontact == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %19[^\n]", newcontact->name);

    printf("Enter phone number: ");
    scanf(" %19[^\n]", newcontact->phone);

    newcontact->next = NULL;

    if (head == NULL) {
        head = newcontact;
    } else {
        struct contact *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newcontact;
    }

    printf("New contact added at end.\n");
}

// Delete contact by name
void deletecontact() {
    if (head == NULL) {
        printf("Contact list is empty.\n");
        return;
    }

    struct contact *temp = head;
    struct contact *prev = NULL;
    char name[20];

    printf("Enter name to delete: ");
    scanf(" %19[^\n]", name);

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Contact deleted successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

// Search contact
void search() {
    if (head == NULL) {
        printf("Contact list is empty.\n");
        return;
    }

    char name[20];
    struct contact *temp = head;

    printf("Enter name to search: ");
    scanf(" %19[^\n]", name);

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("\nContact found!\n");
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

// Display contact list
void display() {
    struct contact *temp = head;
    if (head == NULL) {
        printf("Contact list is empty.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    while (temp != NULL) {
        printf("Name: %s | Phone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

// Free allocated memory on exit
void freeList() {
    struct contact *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice;

    do {
        printf("\n===== Dynamic Contact List =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Contact by Name\n");
        printf("4. Search Contact by Name\n");
        printf("5. Display All Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear invalid input buffer
            continue;
        }

        switch (choice) {
            case 1:
                insertBeg();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                deletecontact();
                break;
            case 4:
                search();
                break;
            case 5:
                display();
                break;
            case 6:
                freeList();
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
