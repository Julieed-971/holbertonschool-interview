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
 * find_last_node - find last node of a max binary heap
 *
 * @root: Root pointer of the tree
 *
 * Return: pointer to the last node, or NULL on failure
 */

heap_t *find_last_node(heap_t *root)
{
	if (root == NULL)
	{
		return (NULL);
	}
	queue *new_queue = malloc(sizeof(queue));

	if (new_queue)
	{
		new_queue->front = NULL;
		new_queue->rear = NULL;
	}

	enqueue(new_queue, root);

	heap_t *current_node = NULL;

	while (new_queue->front != NULL)
	{
		current_node = dequeue(new_queue);

		if (current_node->left)
		{
			enqueue(new_queue, current_node->left);
		}
		if (current_node->right)
		{
			enqueue(new_queue, current_node->right);
		}
	}
	free(new_queue);
	return (current_node);
}

/**
 * heapify_down - restore the heap property
 *
 * @root_node: current root_node to start heapifying
 */

void heapify_down(heap_t *root_node)
{
	heap_t *current = root_node;
	heap_t *largest;
	int tmp = 0;

	while (current != NULL && (current->left != NULL || current->right != NULL))
	{
		largest = current;
		if (current->left != NULL && current->left->n > largest->n)
		{
			largest = current->left;
		}
		if (current->right != NULL && current->right->n > largest->n)
		{
			largest = current->right;
		}
		if (largest == current)
		{
			break;
		}
		tmp = current->n;
		current->n = largest->n;
		largest->n = tmp;

		current = largest;
	}
}

/**
 * heap_extract - extract the root node
 * and heapify the Max Binary Heap if necessary
 *
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value of the extracted root node, or 0 on failure
 */

int heap_extract(heap_t **root)
{
	heap_t *last_node = NULL;
	int root_node_value = 0;

	if (*root == NULL)
	{
		return (0);
	}

	root_node_value = (*root)->n;
	last_node = find_last_node(*root);

	(*root)->n = last_node->n;

	if (last_node->parent->left == last_node)
	{
		last_node->parent->left = NULL;
	}
	if (last_node->parent->right == last_node)
	{
		last_node->parent->right = NULL;
	}
	last_node->parent = NULL;

	free(last_node);

	heapify_down(*root);

	return (root_node_value);
}