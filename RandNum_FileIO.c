/* Authur Info:
 * Name: TING-WEI
 * Email: willytwsu@tamu.edu
 * Date: 10/06/2021
 * 
 * Project Info:
 * Compiler: GCC
 * Environement: 
 * Class: ECEN 749
 * Homework: 2
 * Question: 4
 * Name: Generate random number sorting and save to file
 * Addition info: Sorting method: Quick sort
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define Name_Length 50

// define Error code for return
#define ERR_SEAT_NOT_AVAILABLE 0
#define ERR_STUDENT_NOT_IN_CLASS 1

struct Node{
    float randnum;
    struct Node *next;
};

// Function header
int Save_to_File(int N, char* file_name, struct Node *node);
int Read_from_File(int N, char* file_name, struct Node *node);
int Add_to_List(float num, struct Node *randlist);
int QuickSort_the_List(struct Node *randlist);

int main(void) {

    int N = 0;
    int i;
    pid_t pid = getpid();
    struct tm* ptr;
    time_t t;
    char input_file_name[15] = "q4input.txt"; 
    char output_file_name[15] = "q4output.txt";
    struct Node *randlist = (struct Node*)malloc(sizeof(struct Node)); 

    struct Node *o_randlist = (struct Node*)malloc(sizeof(struct Node)); 
    randlist->next = NULL;
    randlist->randnum = 0.0;
    t = time(NULL);
    ptr = localtime(&t);
    srand(pid*ptr->tm_hour*ptr->tm_min*ptr->tm_sec);

    printf("This is the random number generater and will help you save you number to file and sort it.\n");
    printf("Please provide your N =?\n");
    scanf("%d", &N);
    printf("N=%d\n", N);

    i = N;

    while(i>0){
        Add_to_List(rand()%4095*1.0, randlist);
        i--;
    }
    Save_to_File(N, input_file_name, randlist);

    Read_from_File(N, input_file_name, o_randlist);

    QuickSort_the_List(o_randlist);

    Save_to_File(N, output_file_name, randlist);
     
    return 0;
}
 
int Add_to_List(float num, struct Node *randlist)
{
    // Add student to class in ascending order 
    struct Node *ptr = randlist;
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    // assign the value to node
    new_node->randnum = num;
    // Insert the node in the list
    new_node->next = ptr->next;
    ptr->next = new_node;
    return 0;
}

int QuickSort_the_List(struct Node *randlist)
{    
    struct Node *ptr = randlist;
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    // special case when there is no element in the list
    return 0;
}
int Save_to_File(int N, char* file_name, struct Node *node)
{
    struct Node * s = node;
    FILE *fptr;

    fptr = fopen(file_name, "w");

    if (fptr == NULL)
    {
        printf("No such file");
        exit(1);
    }

    fprintf(fptr, "N:%d \n", N);
    while (s)
    {
        fprintf(fptr, "%f \n", s->randnum);
        s = s->next;
    }

    fclose(fptr);
    return 0;
}

int Read_from_File(int N, char* file_name, struct Node *node)
{
    char buffer[100];
    char *buffer_split;
    struct Node * s = node;
    struct Node * new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> next = NULL;
    FILE *fptr;

    fptr = fopen(file_name, "r");

    if (fptr == NULL)
    {
        printf("No such file");
        exit(1);
    }

    while (fgets(buffer, 100, fptr))
    {
        // 
        
    }
    printf("Buffer:%s\n", buffer);


    buffer_split = strtok(buffer, ":, ");
    while( buffer_split != NULL ) {
        printf(" %s\n", buffer_split); //printing each token
        buffer_split = strtok(NULL, ":, ");
    }
    // Add_to_List(buffer_split ,node)

    fclose(fptr);
    return 0;
}



