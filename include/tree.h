#pragma once
#include <vector>
#include <raylib.h>
#include <string>

#define CHAR_H 24
#define CHAR_W 13
#define NODE_PADDING 16
#define NODE_MARGIN_H 8
#define NODE_MARGIN_V 96
#define NODE_HEIGHT (CHAR_H + NODE_PADDING * 2)
#define PAGE_PADDING 64
#define LINE_THICKNESS 2

using std::vector;

struct Tree {
    std::string value;
    int valind = 0;
    int width = 0;
    int depth = 0;
    int pos_x, pos_y;
    vector<Tree> children;
};

Tree parseTree(const char* file_name);
// Image renderTree(Tree tree);
void arrangeTree(Tree &tree, int x_off = NODE_MARGIN_H, int depth = 0);
Image renderTree(Tree &tree);
int getTreeWidth(Tree &tree);
int getTreeChildrenWidth(Tree &tree);
int getTreeDepth(Tree &tree);
