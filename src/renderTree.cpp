#include "../include/tree.h"

#include <iostream>
#include <vector>

using std::vector;

void drawNode(Image img, Tree &tree, Font font) {
    int t = LINE_THICKNESS;
    float x = tree.pos_x - NODE_PADDING - CHAR_W * tree.valind / 2;
    float y = tree.pos_y;
    float w = tree.valind * CHAR_W + NODE_PADDING * 2;
    float h = CHAR_H + NODE_PADDING * 2;


    for (Tree c : tree.children) {
        int h = c.pos_y - tree.pos_y - NODE_HEIGHT;
        ImageDrawRectangle(&img, 
            tree.pos_x - t/2, 
            tree.pos_y + NODE_HEIGHT,
            t,
            NODE_MARGIN_V / 2,
            BLACK
        );
        ImageDrawRectangle(&img, 
            (tree.pos_x > c.pos_x) ? c.pos_x - t/2 : tree.pos_x - t/2, 
            tree.pos_y + NODE_HEIGHT + NODE_MARGIN_V / 2 - t/2,
            (tree.pos_x > c.pos_x) ? tree.pos_x - c.pos_x + t : c.pos_x - tree.pos_x + t,
            t,
            BLACK
        );
        ImageDrawRectangle(&img, 
            c.pos_x - t/2, 
            c.pos_y - h + NODE_MARGIN_V / 2,
            t,
            h - NODE_MARGIN_V / 2,
            BLACK
        );
    }

    std::cout << tree.pos_y + NODE_HEIGHT << "\n";
    if (tree.children.size() == 0)
        ImageDrawRectangleLines(
            &img, 
            Rectangle{
                (float)tree.pos_x - NODE_PADDING - CHAR_W * tree.valind / 2, 
                (float)tree.pos_y,
                (float)tree.valind * CHAR_W + 2 * NODE_PADDING,
                (float)NODE_HEIGHT
            },
            t,
            BLACK
        );

    ImageDrawTextEx(
        &img, 
        font,
        tree.value.c_str(),
        {
            (float)tree.pos_x - tree.valind * CHAR_W / 2, 
            (float)tree.pos_y + NODE_HEIGHT / 2 - CHAR_H / 2
        },
        CHAR_H, 0, BLACK
    );
};

Image renderTree(Tree &tree) {
    getTreeWidth(tree);
    arrangeTree(tree, PAGE_PADDING, getTreeDepth(tree));

    Font font = LoadFontEx("demo-font.otf", CHAR_H, NULL, 0);

    vector<Tree> queue = {tree};

    int img_width = getTreeWidth(tree) + 2 * PAGE_PADDING;
    int img_height = getTreeDepth(tree) * (NODE_HEIGHT + NODE_MARGIN_V) + 1 * PAGE_PADDING;

    Image img{ GenImageColor(img_width, img_height, WHITE) };
    
    int i = 0;
    while (i < queue.size()) {
        for (Tree c : queue[i].children) {
            queue.push_back(c);
        }

        drawNode(img, queue[i], font);
        // break;
        i++;
    }
    // std::cout << queue.size() << "\n";

    return img;
}