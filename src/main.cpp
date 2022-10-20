#include <raylib.h>
#include <iostream>

#include "../include/tree.h"

int main(int argc, char *argv[]) {
    if (argc > 1) {
        InitWindow(100, 100, "temp-window");
        Tree tree = parseTree(argv[1]);

        Image img = renderTree(tree);

        ExportImage(img, (argc > 2) ? argv[2] : "out.png");
    } else {
        std::cout << "Error: No input file provided" << "\n";
    }
}