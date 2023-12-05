#ifndef META_HEURISTIC_ALGORITHMS_MENU_H
#define META_HEURISTIC_ALGORITHMS_MENU_H

#include <vector>

namespace menu {

    void create_menu();

    void print_options();

    void print_result(int greedy_result, int algorithm_result, const std::vector<int> &path);
}

#endif //META_HEURISTIC_ALGORITHMS_MENU_H
