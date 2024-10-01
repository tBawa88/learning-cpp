#include <iostream>
#include <queue>  // found in the same header as normal queue

void popAndPrintQueue(std::priority_queue<int>& pq) {
    while (!pq.empty()) {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }
}

void popAndPrintMinQueue(std::priority_queue<int, std::vector<int>, std::greater<int>>& min_queue) {
    while (!min_queue.empty()) {
        std::cout << min_queue.top() << std::endl;
        min_queue.pop();
    }
}

int main() {
    std::priority_queue<int> pq;

    pq.push(2);
    pq.push(10);
    pq.push(5);
    pq.push(7);
    pq.push(3);

    popAndPrintQueue(pq);

    // Binary min heap (where the smallest element is stored at the top)
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_queue;
    min_queue.push(2);
    min_queue.push(10);
    min_queue.push(5);
    min_queue.push(7);
    min_queue.push(3);
    std::cout << std::endl;
    popAndPrintMinQueue(min_queue);

    return 0;
}
