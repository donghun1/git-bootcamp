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
  int ind;
  int qsize;
  list_ele_t *curr_elem;
  list_ele_t *next_elem;
  if (q != NULL)
  {
    qsize = q_size(q);
    for (ind = 0; ind < qsize; ind++)
    {
      curr_elem = q->head;
      next_elem = curr_elem->next;
      free(curr_elem->value); // free space malloced for value
      free(curr_elem); // free pointer
      if (next_elem == NULL)
      {
        break;
      }
      q->head = next_elem;
    }
    free(q);
  }
  /* Free queue structure */
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
  if (q == NULL)
  {
    return false;
  }
  newh = malloc(sizeof(list_ele_t));
  if (newh == NULL)
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
  q->tail = newh;
  // account for adding to empty queue
  if (q->head == NULL)
  {
    q->head = newh;
  }
  q->qsize++;
  return true;
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
  size_t str_length;
  char *str_removed;
  int qsize;
  qsize = q_size(q); // returns 0 if q is NULL or qsize is 0
  if (q ==  NULL || qsize == 0)
  {
    return false;
  }
  if (q->head == NULL)
  {
    return false;
  }
  str_removed = q->head->value;
  // value exists
  if (str_removed != NULL)
  {
    str_length = strlen(str_removed);
    if (sp != NULL)
    {
      // string to be removed > sp size
      if (str_length > (bufsize - 1))
      {
        str_length = bufsize - 1;
      }
      memset(sp, '\0', bufsize);
      strncpy(sp, str_removed, str_length);
    }
    // free value of pointer
    free(str_removed);
  }
  // update queue
  q->qsize = q->qsize - 1; // qsize guaranteed to be at least 1
  if (q->head->next != NULL)
  {
    q->head = q->head->next;
  }
  // if we removed last element of queue
  if (qsize == 0)
  {
    q->head = NULL;
    q->tail = NULL;
  }
  free(q->head);
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
  /*list_ele_t *prev_elem;
  list_ele_t *curr_elem;
  list_ele_t *next_elem;
  list_ele_t *qhead;
  list_ele_t *qtail;
  if (q != NULL)
  {
    qhead = q->head;
  }*/
  return;
}

