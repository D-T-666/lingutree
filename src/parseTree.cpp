#include "../include/tree.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Parser {
private:
    vector<Tree> stack;
    vector<char> node_val;
    int white_space_ind;

public:
    Tree result;
    Parser() {};

    bool insertChar(char c) {
        Tree temp;
        char pchar;
        switch (c) {
            case '[':
                stack.push_back(temp);
                break;

            case ']':
                if (stack.size() == 1) {
                    result = stack[0];
                    result.depth = stack.size() - 1;
                    result.pos_y = result.depth * ((NODE_HEIGHT) + NODE_MARGIN_V) + NODE_MARGIN_V;
                    // std::cout << temp.pos_y << "\n";
                    return true;
                } else {
                    temp = stack.back();
                    temp.depth = stack.size() - 1;
                    temp.pos_y = temp.depth * ((NODE_HEIGHT) + NODE_MARGIN_V) + NODE_MARGIN_V;
                    stack.pop_back();
                    stack.back().children.push_back(temp);
                }
                break;

            case ' ':
            case '\n':
            case '\t':
                pchar = node_val[node_val.size() - 1];
                if (pchar == ' ' || pchar == '\n' || pchar == '\t')
                    white_space_ind = node_val.size() - 1;
                node_val.push_back(c);
                break;

            default:
                white_space_ind = node_val.size() - 1;
                node_val.push_back(c);
                stack.back().value += string(1, c);
                stack.back().valind++;
                break;
        }

        return false;
    };
};

Tree parseTree(const char* file_name) {
    ifstream file;
    file.open(file_name,  ios::in);

    Parser p;
    Tree res;

    char c;
	while (!file.eof()) {
    	file.get(c);
        if (p.insertChar(c)) {
            res = p.result;
            break;
        }
	}

    return res;
}