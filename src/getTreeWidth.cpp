#include "../include/tree.h"

#include <math.h>

int getTreeChildrenWidth(Tree &tree) {
    int children_width = (tree.children.size() - 1) * NODE_MARGIN_H;
    for (Tree &c : tree.children)
        children_width += getTreeWidth(c);
    
    return children_width;
}

int getTreeWidth(Tree &tree) {
    if (!tree.width) {
        int value_width = tree.valind * CHAR_W + 2 * NODE_PADDING;

        int children_width = getTreeChildrenWidth(tree);

        tree.width = std::max(children_width, value_width);
    }
    return tree.width;
}