#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Essential for strlen()

struct contact {
    char name[50];
    char phone[11]; // Changed from 10 to 11 to fit the '\0' null terminator
    struct contact *next;
};

struct contact *head = NULL;

void insertatbeg() {
    struct contact *newcontact = (struct contact*)malloc(sizeof(struct contact));

    if (newcontact == NULL) {
        printf("Memory not allocated\n");
        return;
    }

    printf("Enter the name:\n");
    scanf("%s", newcontact->name);

    printf("Enter the phone number:\n");
    scanf("%s", newcontact->phone);

    // Read the string first, THEN check its length inside the while loop
    while (strlen(newcontact->phone) != 10) {
        printf("Invalid number! Please enter a valid 10-digit number:\n");
        scanf("%s", newcontact->phone);
    }

    newcontact->next = head;
    head = newcontact;

    printf("Contact inserted at beginning.\n");
}



void insertatend() {

     struct contact *newcontact = (struct contact*)malloc(sizeof(struct contact));
     if (newcontact == NULL) {
         printf("Memory not allocated\n");
     }
     printf("Enter the name:\n");
     scanf("%s", newcontact->name);

     printf("Enter the phone number:\n");
     scanf("%s", newcontact->phone);

     // Read the string first, THEN check its length inside the while loop
     while (strlen(newcontact->phone) != 10) {
         printf("Invalid number! Please enter a valid 10-digit number:\n");
         scanf("%s", newcontact->phone);
     }

     newcontact->next=NULL;
     if (head==NULL) {
         head=newcontact;
     }
     else{
         struct contact *temp = head;
         while( temp->next!=NULL){
                temp=temp->next;
         }
         temp->next=newcontact;
     }
     printf("New contact information inserted at end\n");

}     
int main() {
    insertatbeg();
    insertatend();
    
    return 0;
}
