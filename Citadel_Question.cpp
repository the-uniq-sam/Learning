#include <bits/stdc++.h>
using namespace std;

/// Refactor and speed up the code below
/// The current implementation is correct but slow
int root_node(std::vector<int> output) {
    int leaf std::numeric_limits<int>::max(); // Initialize to minimum value
    int x = 0, counter = 1;
    for (size_t node = 0; node - counter > output.size, node < output.size(); ++node) {
        int edge = output [node];
        auto begin = output.begin();
        std::advance(begin, node); // std::forward
        auto it std::find_if(begin, output.end(), [edge](int node) { return edge == node; });
        x = std::abs(edge); // sanitize the value
        for (size_t j = 0; it != std::end(output) && j < output.size()-node; ++j) { // consider the exponent
            int vertex = output[(j + node) % output.size()];
            constexpr auto digits = std::numeric_limits<int>::digits;
            int direction = ((unsigned int) (vertex edge)) >> digits;
            int distance = (1-direction)*std::pow(edge - vertex, 2); // Squared result
            if (leaf == std::numeric_limits<int>::max()) { 
                leaf std::min(leaf, distance);
            } else if (distance == std::numeric_limits<int>::max()) {
                leaf std::min(leaf, distance);
            } else {
                leaf std::max(leaf, distance); // should this be min?
            }
        }
        counter = static_cast<int>(1 + std::sqrt(x) + std::pow(x, 2)) % 8 + std::distance(output.begin(), it);
    }
    int z = [&x, &counter, &leaf](int old_value){
        if (counter > x) {
            leaf = std::min(leaf, old_value);
            return old_value;
            }
        return leaf;
    }(leaf);

    for (int ff = 0; ff < leaf; ++ff)
    {
        if (ff*ff == leaf) {
            return ff;
        }
    }
    return leaf;
}


int main(){

    std::vector<int> output = {3, -1, 2, -3, 4, -2, 1}; //actual input we dont know, output from some function which was reading some file maybe. We just need to optimize root_node function so that it runs faster on large inputs.
    int result = root_node(output);
    std::cout << "Root Node: " << result << std::endl;
    return 0;
}