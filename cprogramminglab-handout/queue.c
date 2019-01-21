/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */ 
    if (q != NULL)
    {
      q->qsize = 0;
      q->head = NULL;
      q->tail = NULL;
    }
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
  int ind = 0;
  int qsize;
  list_ele_t *curr_elem;
  list_ele_t *next_elem;
  if (q != NULL)
  {
    qsize = q->qsize;
    while (ind < qsize)
    {
      curr_elem = q->head;
      next_elem = curr_elem->next;
      free(curr_elem->value); // free space malloced for value
      free(curr->elem); // free pointer
      if (next_elem == NULL)
      {
        break;
      }
      // increment loop
      ind++;
      q->head = next_elem;
    }
  }
  /* Free queue structure */
  free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    char *new_str;
    size_t str_length;
    // if q is NULL or fail malloc, return false
    newh = malloc(sizeof(list_ele_t));
    if (q == NULL || newh == NULL)
    {
      return false;
    }
    str_length = strlen(s);
    // allocate for size of string + NULL terminator
    new_str = malloc(str_length + 1);
    // fail allocation of string
    if (new_str == NULL)
    {
      free(newh);
      return false;
    }
    strcpy(new_str, s);
    // edit list element
    newh->value = new_str;
    newh->next = q->head;
    // adjust queue head
    q->head = newh;
    // account for adding to empty queue
    if (q->tail == NULL)
    {
      q->tail = q->head;
    }
    q->qsize++;
    return true;
}

/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    return false;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* You need to fix up this code. */
    q->head = q->head->next;
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
  if (q == NULL)
  {
    return 0;
  }
  return q->qsize;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
}

