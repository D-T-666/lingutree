#include "../include/tree.h"

int getTreeDepth(Tree &tree) {
    vector<Tree> queue = {tree};

    int max_depth = 1;

    int i = 0;
    while (i < queue.size()) {
        if (queue[i].depth > max_depth) {
            max_depth = queue[i].depth;
        }

        for (Tree &c : queue[i].children) {
            queue.push_back(c);
        }
        i++;
    }

    return 1 + max_depth;
}