#include <iostream>
#include <unordered_map>
#include <map>

/*

The main difference between std::unordered_map and std::map (which is typically referred to as an ordered map) lies in their underlying data structures and the guarantees they provide in terms of element order and performance characteristics:

Data Structure:
std::unordered_map: Uses a hash table to store elements, providing fast average constant-time access, insertion, and deletion. However, the elements are not stored in any particular order, and iteration order may vary based on the internal hash function and bucket structure.
std::map: Typically implemented as a balanced binary search tree (usually a red-black tree). It maintains the elements in a specific order defined by the keys, which means the elements are sorted based on the keys. This structure guarantees that the keys will be sorted in ascending order.

Ordering:
std::unordered_map: Does not guarantee any specific order of the elements. If you need to maintain the order of insertion, you should use std::unordered_map along with an additional container like std::vector to keep track of the insertion order.
std::map: Maintains the elements sorted based on the keys. This means that the elements are ordered in ascending key order according to the comparison function (by default, the less-than operator <).

Complexity:
std::unordered_map: On average, the time complexity for access, insertion, and deletion is constant time O(1). In the worst case, when there are hash collisions, these operations can have a linear time complexity O(n).
std::map: The time complexity for access, insertion, and deletion is logarithmic time O(log n) in the size of the map, as it needs to traverse the tree for these operations.

Use Cases:
Use std::unordered_map when you need fast access to elements based on keys and don't require a specific order of the elements. This is suitable for cases where the order of elements does not matter, and you prioritize fast lookup operations.
Use std::map when you need to maintain the elements in a specific sorted order based on their keys. This is suitable for scenarios where you frequently need to iterate through the elements in a sorted order or perform range-based queries.
*/

int main() {
    std::unordered_map<int, std::string> unordered_map = {
        {3, "Alice"},
        {1, "Bob"},
        {2, "Charlie"}
    };

    std::map<int, std::string> ordered_map = {
        {3, "Alice"},
        {1, "Bob"},
        {2, "Charlie"}
    };

    std::cout << "Unordered Map:" << std::endl;
    for (const auto& pair : unordered_map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "Ordered Map:" << std::endl;
    for (const auto& pair : ordered_map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
