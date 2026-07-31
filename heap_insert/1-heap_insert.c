#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * enqueue - enqueue a tree node from a queue
 *
 * @heap_queue: queue to queue the node in
 * @tree_node: node to queue
 */

void enqueue(queue *heap_queue, heap_t *tree_node)
{
	queue_node *new_queue_node = malloc(sizeof(queue_node));

	if (new_queue_node)
	{
		new_queue_node->tree_node = tree_node;
		new_queue_node->next = NULL;
	}
	if (heap_queue->rear)
	{
		heap_queue->rear->next = new_queue_node;
	}
	else
	{
		heap_queue->front = new_queue_node;
	}
	heap_queue->rear = new_queue_node;
}

/**
 * dequeue - dequeue a tree node from a queue
 *
 * @heap_queue: queue to dequeue a node from
 *
 * Return: the first node from the queue or NULL
 */

heap_t *dequeue(queue *heap_queue)
{
	if (heap_queue->front)
	{
		queue_node *temp = heap_queue->front;
		heap_t *tree_node = temp->tree_node;

		heap_queue->front = heap_queue->front->next;
		if (!heap_queue->front)
		{
			heap_queue->rear = NULL;
		}
		free(temp);
		return (tree_node);
	}
	return (NULL);
}

/**
 * heapify_up - restore the max heap property
 *
 * @last_node: current root_node to start heapifying from
 */
void heapify_up(heap_t *last_node)
{
	heap_t *current_node = last_node;
	int tmp = 0;

	while (current_node->parent != NULL &&
		current_node->parent->n < current_node->n)
	{
		tmp = current_node->parent->n;
		current_node->parent->n = current_node->n;
		current_node->n = tmp;
		current_node = current_node->parent;
	}
}

/**
 * heap_insert - function that inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *current_node = NULL;
	queue *queue;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	queue = malloc(sizeof(queue));
	if (queue == NULL)
	{
		return (NULL);
	}
	queue->front = NULL;
	queue->rear = NULL;
	enqueue(queue, *root);
	while (queue->front != NULL)
	{
		current_node = dequeue(queue);
		if (current_node->left == NULL)
		{
			current_node->left = binary_tree_node(current_node, value);
			new_node = current_node->left;
			break;
		}
		enqueue(queue, current_node->left);
		if (current_node->right == NULL)
		{
			current_node->right = binary_tree_node(current_node, value);
			new_node = current_node->right;
			break;
		}
		enqueue(queue, current_node->right);
	}
	free(queue);
	if (new_node)
		heapify_up(new_node);
	return (new_node);
}
