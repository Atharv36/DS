
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int ssn;
    char name[50];
    char dept[30];
    char designation[30];
    float salary;
    char phone[15];
    struct Employee* next;
    struct Employee* prev;
};

struct Employee* head = NULL;
struct Employee* tail = NULL;
int count = 0;

void insertAtEnd();
void insertAtFront();
void deleteAtEnd();
void deleteAtFront();
void display();
void double_ended_queue();

int main() {
    int choice;

    while (1) {
        printf("\nEmployee DLL Menu\n");
        printf("1. Insert Employee at End\n");
        printf("2. Insert Employee at Front\n");
        printf("3. Delete Employee from End\n");
        printf("4. Delete Employee from Front\n");
        printf("5. Display DLL and Count\n");
        printf("6. Double Ended Queue Operations\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtEnd(); break;
            case 2: insertAtFront(); break;
            case 3: deleteAtEnd(); break;
            case 4: deleteAtFront(); break;
            case 5: display(); break;
            case 6: double_ended_queue(); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

void double_ended_queue() {
    int ch;
    while (1) {
        printf("\nDOUBLE ENDED QUEUE OPERATIONS");
        printf("\n1: Insert Rear\n2: Delete Rear\n3: Insert Front\n4: Delete Front\n5: Display\n6: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insertAtEnd(); break;
            case 2: deleteAtEnd(); break;
            case 3: insertAtFront(); break;
            case 4: deleteAtFront(); break;
            case 5: display(); break;
            case 6: return;
            default: printf("\nInvalid Choice\n");
        }
    }
}

void insertAtEnd() {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    printf("\nEnter SSN: ");
    scanf("%d", &newEmployee->ssn);
    printf("Enter Name: ");
    scanf("%s", newEmployee->name);
    printf("Enter Department: ");
    scanf("%s", newEmployee->dept);
    printf("Enter Designation: ");
    scanf("%s", newEmployee->designation);
    printf("Enter Salary: ");
    scanf("%f", &newEmployee->salary);
    printf("Enter Phone Number: ");
    scanf("%s", newEmployee->phone);

    newEmployee->next = NULL;
    newEmployee->prev = NULL;

    if (head == NULL) {
        head = newEmployee;
        tail = newEmployee;
    } else {
        tail->next = newEmployee;
        newEmployee->prev = tail;
        tail = newEmployee;
    }
    count++;
    printf("Employee added at end.\n");
}

void insertAtFront() {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    printf("\nEnter SSN: ");
    scanf("%d", &newEmployee->ssn);
    printf("Enter Name: ");
    scanf("%s", newEmployee->name);
    printf("Enter Department: ");
    scanf("%s", newEmployee->dept);
    printf("Enter Designation: ");
    scanf("%s", newEmployee->designation);
    printf("Enter Salary: ");
    scanf("%f", &newEmployee->salary);
    printf("Enter Phone Number: ");
    scanf("%s", newEmployee->phone);

    newEmployee->next = NULL;
    newEmployee->prev = NULL;

    if (head == NULL) {
        head = newEmployee;
        tail = newEmployee;
    } else {
        newEmployee->next = head;
        head->prev = newEmployee;
        head = newEmployee;
    }
    count++;
    printf("Employee added at front.\n");
}

void deleteAtEnd() {
    if (tail == NULL) {
        printf("DLL is empty, nothing to delete.\n");
        return;
    }
    struct Employee* temp = tail;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    printf("Deleted Employee with SSN: %d\n", temp->ssn);
    free(temp);
    count--;
}

void deleteAtFront() {
    if (head == NULL) {
        printf("DLL is empty, nothing to delete.\n");
        return;
    }
    struct Employee* temp = head;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    printf("Deleted Employee with SSN: %d\n", temp->ssn);
    free(temp);
    count--;
}

void display() {
    struct Employee* temp = head;
    if (temp == NULL) {
        printf("The DLL is empty.\n");
        return;
    }
    printf("\nEmployees in DLL:\n");
    while (temp != NULL) {
        printf("SSN: %d, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, Phone: %s\n",
               temp->ssn, temp->name, temp->dept, temp->designation, temp->salary, temp->phone);
        temp = temp->next;
    }
    printf("\nTotal number of employees: %d\n", count);

}


