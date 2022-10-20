#include "../include/tree.h"

#include <iostream>
#include <vector>

using std::vector;

void arrangeTree(Tree &tree, int x_off, int max_depth) {
    int x = x_off + tree.width / 2;
    tree.pos_x = x;

    int tw = getTreeWidth(tree), tcw = getTreeChildrenWidth(tree);
    if (tw > tcw) x_off += (tw - tcw + 1) / 2;

    if (tree.children.size() == 0) {
        tree.pos_y = max_depth * ((NODE_HEIGHT) + NODE_MARGIN_V) - NODE_MARGIN_V;
    } 

    for (Tree &c : tree.children) {
        arrangeTree(c, x_off, max_depth);
        x_off += c.width + NODE_MARGIN_H;
    }
}