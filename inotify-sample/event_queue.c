#include "event_queue.h"
#include <stdlib.h>
#include <stdint.h>

/* Simple queue implemented as a singly linked list with head 
   and tail pointers maintained
*/
int queue_empty (queue_t q)
{
  return q->head == NULL;
}

queue_t queue_create ()
{
  queue_t q;
  q = malloc (sizeof (struct queue_struct));
  if (q == NULL)
    exit (-1);

  q->head = q->tail = NULL;
  return q;
}

void queue_destroy (queue_t q)
{
  if (q != NULL)
    {
      while (q->head != NULL)
	{
	  queue_entry_t next = q->head;
	  q->head = next->next_ptr;
	  next->next_ptr = NULL;
	  free (next);
	}
      q->head = q->tail = NULL;
      free (q);
    }
}

void queue_enqueue (queue_entry_t d, queue_t q)
{
  d->next_ptr = NULL;
  if (q->tail)
    {
       q->tail->next_ptr = d;
       q->tail = d;
    }
  else
    {
      q->head = q->tail = d;
    }
}

queue_entry_t  queue_dequeue (queue_t q)
{
  queue_entry_t first = q->head;
  if (first)
    {
      q->head = first->next_ptr;
      if (q->head == NULL) 
	{
	  q->tail = NULL;
	}
      first->next_ptr = NULL;
    }
  return first;
}

