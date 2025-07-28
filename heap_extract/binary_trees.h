#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s heap_t;

/**
 * struct queue_node - queue node
 *
 * @tree_node: Binary tree node
 * @next: pointer to the next queue_node
 */
typedef struct queue_node
{
	heap_t *tree_node;
	struct queue_node *next;
} queue_node;

/**
 * struct queue - queue
 *
 * @front: first element in the queue
 * @rear: last element in the queue
 */
typedef struct queue
{
	queue_node *front;
	queue_node *rear;
} queue;

typedef struct binary_tree_s binary_tree_t;

int heap_extract(heap_t **root);
void binary_tree_print(const binary_tree_t *);
void heapify_down(heap_t *root_node);

#endif /* BINARY_TREES_H */