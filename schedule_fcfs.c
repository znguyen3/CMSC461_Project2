#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "cpu.h"
#include "list.h"
#include "schedulers.h"

struct node *start;
struct task *add_task;
struct node *head = NULL;
struct node *current = NULL;


int num = 0;

// Function to reverse the linked list
static void reverse(struct node** head) {
        struct node* previous = NULL;   // the previous pointer
        struct node* current = *head;   // the main pointer

        // traverse the list
        while (current != NULL) {
                // tricky: note the next node
                struct node* next = current->next;

                current->next = previous;    // fix the current node

                // advance the two pointers
                previous = current;
                current = next;
        }

        // fix the head pointer to point to the new front
        *head = previous;
}


/*Delete the first node of a linked list.*/
void delete_first_node(struct node **head) {
  struct node *tmp;

  /*Linked list does not exist or the list is empty*/
  if(head == NULL || *head == NULL) return;

  /*Storing the head to a temporary variable*/
  tmp = *head;

  /*Moving head to the next node*/
  *head = (*head)->next;

  /*Deleting the first node*/
  free(tmp);
}


void add(char *name_id,int priority_id,int burst_id) {

        start = malloc(sizeof(struct task));
        add_task = malloc(sizeof(struct task));

        //start->id = 1;

        add_task->name = name_id;
        add_task->priority = priority_id;
        add_task->burst = burst_id;


        printf("Inserted [%s] [%d] [%d]\n", name_id, priority_id, burst_id);
        insert(&start, add_task);

        //counts the number of tasks in the queue
        num = num + 1;

        //point it to old first node
        start->next = head;

        //point first to new first node
        head = start;

        return;
}

void schedule() {
        printf("\nPrinting out the schedule and running the task \n\n");

        reverse(&start);

        printf("FCFS (First come, first served) is the process that comes first will be executed first and next process starts only after the previous gets fully executed\n\n");

        for (int i = 0; i <= num - 1; i++) {
                printf("Running the task\n");
                run(start->task,start->task->burst);

                printf("Removing [%s] from queue\n", start->task->name);
                delete_first_node(&start);
        }

        return;
}
