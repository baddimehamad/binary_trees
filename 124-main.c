#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_array
 *
 * @the_array: the_array
 * @the_size: Size of the the_array
 */
void print_array(const int *the_array, size_t the_size)
{
    size_t x;

    for (x = 0; x < the_size; ++x)
        printf("(%03d)", the_array[x]);
    printf("\n");
}

/**
 * main
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    avl_t *the_tree;
    int the_array[] = {
        1, 2, 20, 21, 22, 32, 34, 47, 62, 68,
        79, 84, 87, 91, 95, 98
    };
    size_t n = sizeof(the_array) / sizeof(the_array[0]);

    the_tree = sorted_array_to_avl(the_array, n);
    if (!the_tree)
        return (1);
    print_array(the_array, n);
    binary_tree_print(the_tree);
    return (0);
}
