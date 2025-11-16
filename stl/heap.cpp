#include <iostream>
#include <vector>
#include <algorithm> // std::make_heap, std::push_heap, std::pop_heap, std::sort_heap
#include <functional> // std::greater

int main()
{
    // 使用 vector 作为堆的底层容器
    std::vector<int> heap = {3, 1, 4, 1, 5, 9, 2, 6};

    // make_heap 将一个范围转换为堆 (默认是最大堆)
    std::make_heap(heap.begin(), heap.end());
    // 此时 heap 满足堆的性质，但整体不是有序的
    std::cout << "After make_heap (max-heap): ";
    for (int val : heap) {
        std::cout << val << " "; // 输出顺序未指定，但满足堆性质 (最大值在 front)
    }
    std::cout << std::endl;
    std::cout << "Top element (max): " << heap.front() << std::endl; // 9 (最大值)

    // push_heap 需要先在容器末尾添加元素，然后调用 push_heap 维护堆性质
    heap.push_back(8); // 先添加到末尾
    std::push_heap(heap.begin(), heap.end()); // 调整堆
    std::cout << "After push_heap with 8: ";
    std::cout << "Top element (max): " << heap.front() << std::endl; // 9 或 8 (取决于 8 在哪里，但最大值仍在 front)

    // pop_heap 将堆顶元素移到容器末尾，并调整堆
    std::pop_heap(heap.begin(), heap.end()); // 将最大值移到末尾 (但并未真正删除)
    std::cout << "After pop_heap, heap size: " << heap.size() << std::endl;
    std::cout << "Max element is now at back: " << heap.back() << std::endl; // 原来最大的元素
    heap.pop_back(); // 真正删除
    std::cout << "After pop_back, new top: " << heap.front() << std::endl; // 新的最大元素

    // sort_heap 将堆排序成有序序列 (升序)
    std::vector<int> heap2 = {3, 1, 4, 1, 5, 9, 2, 6};
    std::make_heap(heap2.begin(), heap2.end());
    std::sort_heap(heap2.begin(), heap2.end());
    std::cout << "After sort_heap (sorted ascending): ";
    for (int val : heap2) {
        std::cout << val << " "; // 1 1 2 3 4 5 6 9
    }
    std::cout << std::endl;

    // 创建最小堆 (使用 greater 比较器)
    std::vector<int> min_heap = {3, 1, 4, 1, 5, 9, 2, 6};
    std::make_heap(min_heap.begin(), min_heap.end(), std::greater<int>{}); // 使用 greater
    std::cout << "Min-heap top: " << min_heap.front() << std::endl; // 1 (最小值)
    // 注意: 对最小堆使用 pop_heap 和 push_heap 时，仍需传入 greater 比较器
    min_heap.push_back(0);
    std::push_heap(min_heap.begin(), min_heap.end(), std::greater<int>{});
    std::cout << "After pushing 0 to min-heap, new top: " << min_heap.front() << std::endl; // 0

    // is_heap 检查范围是否为堆
    std::cout << "Is original vector a heap? " << std::is_heap(heap.begin(), heap.end()) << std::endl; // 0 (false, 因为已经 pop 过)
    std::vector<int> test_heap = {9, 5, 6, 1, 4, 3, 2};
    std::cout << "Is {9,5,6,1,4,3,2} a max-heap? " << std::is_heap(test_heap.begin(), test_heap.end()) << std::endl; // 1 (true)

    // make_heap, push_heap, pop_heap, sort_heap, is_heap
    // is_heap_until

    return 0;
}