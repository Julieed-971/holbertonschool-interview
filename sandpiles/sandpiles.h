#ifndef SANDPILES_H
#define SANDPILES_H

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int check_if_unstable(int grid1[3][3]);
static void print_grid(int grid[3][3]);
void topple_grid(int grid1[3][3]);

#endif
