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


//sortList() will sort nodes of the list in ascending order
void sortList() {
        //Node current will point to head
        struct node *current = start, *index = NULL;
        int temp;

        if(start == NULL) {
            return;
        }
        else {
                while(current != NULL) {
                        //Node index will point to node next to current
                        index = current->next;

                        while(index != NULL) {
                                //If current node's data is greater than index's node data, swap the data between them
                                if(current->task->burst > index->task->burst) {
                                        temp = current->task->burst;
                                        current->task->burst = index->task->burst;
                                        index->task->burst = temp;
                                }
                        index = index->next;
                        }
                current = current->next;
                }
        }
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

        // sort the list from least to highest based on task burst
        sortList();

        printf("Shortest Job First (SJF), an algorithm in which the process having the smallest burst (execution time) is chosen for the next execution.\n\n">

        printf("From the schedule, the task with the smallest burst is [%s] with a burst of [%d]\n", start->task->name, start->task->burst);

        // loops based on how many tasks
        for (int i = 0; i <= num - 1; i++) {
                printf("Running the task\n");
                run(start->task,start->task->burst);
                printf("Removing [%s] from queue\n", start->task->name);
                delete_first_node(&start);
        }
        return;
}
