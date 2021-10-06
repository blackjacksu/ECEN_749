/* Authur Info:
 * Name: TING-WEI
 * Email: willytwsu@tamu.edu
 * Date: 10/05/2021
 * 
 * Project Info:
 * Compiler: GCC
 * Environement: 
 * Class: ECEN 749
 * Homework: 2
 * Question: 3
 * Name: Class Roster
 * _
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Name_Length 50

// define Error code for return
#define ERR_SEAT_NOT_AVAILABLE 0
#define ERR_STUDENT_NOT_IN_CLASS 1

struct student{
    char name[Name_Length];
    char UIN[Name_Length];
    struct student *next;
};

struct Class
{
    int class_capacity;
    int occupied_seats;
    int remaining_seats;
    char class_name[Name_Length];
    struct student *head;
    struct student *tail;
    
};


int Add_to_Class(struct student * s, struct Class *class);
void Remove_from_class(struct student * s, struct Class *class);
void Save_Class_Info_to_File();
int Init_Class(int capacity, char *name, struct Class *class);
void Show_Class_Info(struct Class * class);


int main(void) {
    int user_option_1st = 0;
    int user_option_2nd = 0;
    int user_option_3rd = 0;
    int keep_menu = 1;
    
    struct student *new_student = (struct student*)malloc(sizeof(struct student));
    struct Class *class_501 = (struct Class*)malloc(sizeof(struct Class)); 
    struct Class *class_502 = (struct Class*)malloc(sizeof(struct Class)); 
    struct Class *class_503 = (struct Class*)malloc(sizeof(struct Class)); 
    
    
    // Initialize the linked list
    if (!Init_Class(50, "501", class_501))
    {
        // Init failed
        printf("Class 501 not init");
    }
    if (!Init_Class(50, "502", class_502))
    {
        // Init failed
        printf("Class 502 not init");
    }
    if (!Init_Class(50, "503", class_503))
    {
        // Init failed
        printf("Class 503 not init");
    }

    while(keep_menu)
    {
        printf("Select action from the following menu:\n[1]Add\n[2]Remove\n[3]Create Roster\n");
        scanf("%d", &user_option_1st);
        switch (user_option_1st)
        {
        case 1:
            // Add student to class
            memset(new_student->name, 0, sizeof(new_student->name));
            memset(new_student->UIN, 0, sizeof(new_student->UIN));
            new_student->next = NULL;
            printf("Please enter the student name:\n");
            scanf("%s", new_student->name);
            printf("Please enter the student UIN:\n");
            scanf("%s", new_student->UIN);
            printf("Please enter the class section you want to add\n[1]501\n[2]502\n[3]503\n");
            scanf("%d", &user_option_2nd);
            switch (user_option_2nd)
            {
            case 1:
                Add_to_Class(new_student, class_501);
                break;
            case 2:
                Add_to_Class(new_student, class_502);
                break;
            case 3:
                Add_to_Class(new_student, class_503);
                break;
            default:
                // Back to main menu
                break;
            }
            break;
        case 2:
            // Remove student from class
            printf("Please enter the student name:\n");
            scanf("%s", new_student->name);
            printf("Please enter the student UIN:\n");
            scanf("%s", new_student->UIN);
            printf("Please enter the class section you want to add\n[1]501\n[2]502\n[3]503\n");
            scanf("%d", &user_option_2nd);
            switch (user_option_2nd)
            {
            case 1:
                Add_to_Class(new_student, class_501);
                break;
            case 2:
                Add_to_Class(new_student, class_502);
                break;
            case 3:
                Add_to_Class(new_student, class_503);
                break;
            default:
                keep_menu = 0;
                break;
            }
            break;
        case 3:
            // Create class roster
            // Show class info
            printf("Select the class number:\n[1]501\n[2]502\n[3]503]\n");
            scanf("%d", &user_option_2nd);
            switch (user_option_2nd)
            {
            case 1:
                Show_Class_Info(class_501);
                Save_Class_Info_to_File(class_501, "501.txt");
                break;
            case 2:
                Show_Class_Info(class_502);
                Save_Class_Info_to_File(class_502, "502.txt");
                break;
            case 3:
                Show_Class_Info(class_503);
                Save_Class_Info_to_File(class_503, "503.txt");
                break;
            default:
                keep_menu = 0;
                break;
            }
            break;
        
        default:
            // Jump out of the loop
            keep_menu = 0;
            break;
        }
    }
    printf("Regret to see you leave\n");
    
    return 0;
}

int Init_Class(int capacity, char *name, struct Class *class)
{
    struct Class *ptr = class;
    memcpy(ptr->class_name, name, sizeof(ptr->class_name));
    ptr->class_capacity = capacity;
    ptr->remaining_seats = capacity;
    ptr->occupied_seats = 0;
    ptr->head = NULL;
    ptr->tail = NULL;
    
    return 0;
}

int Add_to_Class(struct student * s, struct Class *class)
{
    // Add student to class in ascending order 
    struct Class *class_ptr = class;
    struct student *new_student = (struct student *)malloc(sizeof(struct student));
    struct student *current = (struct student *)malloc(sizeof(struct student));

    // check remaining seats
    if (class_ptr->remaining_seats >= class_ptr->class_capacity)
    {
        // No more empty seats
        return ERR_SEAT_NOT_AVAILABLE;
    }

    // update the seat info in class
    class_ptr->occupied_seats++;
    class_ptr->remaining_seats = class_ptr->class_capacity - class_ptr->occupied_seats;
    new_student->next = NULL;
    memcpy(new_student->name, s->name, sizeof(new_student->name));
    memcpy(new_student->UIN, s->UIN, sizeof(new_student->UIN));
    // special case when there is no element in the list
    if (class_ptr->head == NULL ||
        class_ptr->head->name > new_student->name)
    {
        new_student->next = class_ptr->head;
        class_ptr->head = new_student;
    }
    else
    {
        // Search through all elements in the linked list
        // Locate the student in the class
        current = class_ptr->head;
        // // Sorting using name 
        // while (strcmp(current->next->name, new_student->name)<=0 &&
        //         current->next != NULL)
        // {
        //     if (strcmp(current->next->name, new_student->name)==0)
        //     {
        //         // The two students have the same name
        //         // Sorted using UIN
        //         if (strcmp(current->next->UIN, new_student->UIN)<0)
        //         {
        //             break;
        //         }
        //     }
        //     // move to the next node to check the orderness 
        //     current = current->next;
        // }
        int result = strcmp(current->next->name, new_student->name);
        int result_2 = strcmp(current->next->UIN, new_student->UIN);

        new_student->next = current->next;
        current->next = new_student;
    }
    return 0;
}
void Remove_from_class(struct student * s, struct Class *class)
{
    // Add student to class in ascending order 
    struct Class *class_ptr = class;
    struct student *remove_student = (struct student *)malloc(sizeof(struct student));
    struct student *current = (struct student *)malloc(sizeof(struct student));    
    if (strcmp()==0)
    {
        
    }

}
void Save_Class_Info_to_File(struct Class *class, char *file_name)
{
    struct Class * ptr = class;
    struct student * s = class->head;
    FILE *class_Info;

    int i = 1;

    class_Info = fopen(file_name, "w");

    if (class_Info == NULL)
    {
        printf("No such file");
        exit(1);
    }

    fprintf(class_Info, "Class Name:%s\n", ptr->class_name);
    fprintf(class_Info, "Class Capacity:%d\n", ptr->class_capacity);
    fprintf(class_Info, "Seats taken:%d\n", ptr->occupied_seats);
    fprintf(class_Info, "Seats available:%d\n", ptr->remaining_seats);
    fprintf(class_Info, "Name   UIN\n");
    while (s)
    {
        fprintf(class_Info, "%s    %s\n", s->name, s->UIN);
        s = s->next;
    }

    fclose(class_Info);
}

void Show_Class_Info(struct Class * class)
{
    struct Class *ptr = class;
    struct student * s = class->head->next;
    printf("Class name:%s\n", ptr->class_name);
    printf("Total capacity:%d\n", ptr->class_capacity);
    printf("Seat occupied:%d\n", ptr->occupied_seats);
    printf("Seat available:%d\n", ptr->remaining_seats);
    printf("Name    UIN\n");
    while (s)
    {
        printf("%s  %s\n", s->name,s->UIN);
        s = s->next;
    }
}



