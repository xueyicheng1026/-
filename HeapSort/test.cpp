#include "HeapSort.h"
#include <random>
#include <chrono>
#include <algorithm>

vector<int> generateRandomInitializerList(size_t size, int max) {
    static vector<int> data(size); // 使用静态存储，避免局部对象被销毁
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-max,max); // 定义随机范围

    for (size_t i = 0; i < size; ++i) {
        data[i] = dis(gen);
    }

    return data;
}

int main() {
    size_t length = 1000000; 
//randanm sequence
    std::cout << "random sequence" << std::endl;
    auto randomList = generateRandomInitializerList(length, 5*length);
    Heap<int> heap1(randomList);
    //my_heap_sort
    auto start = std::chrono::high_resolution_clock::now();
    heap1.build();
    heap1.sort();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "耗时: " << duration.count() << " 毫秒" << std::endl;
    //std::heap_sort
    start = std::chrono::high_resolution_clock::now();
    std::make_heap(randomList.begin(), randomList.end(), std::greater<int>());
    std::sort_heap(randomList.begin(), randomList.end(), std::greater<int>());
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "耗时: " << duration.count() << " 毫秒" << std::endl;

//ordered sequence
    std::cout << "ordered sequence" << std::endl;
    vector<int> orderedList;
    for (long long i = 0; i < length; ++i) {
        orderedList.push_back(i);
    }
    Heap<int> heap2(orderedList);
    //my_heap_sort
    start = std::chrono::high_resolution_clock::now();
    heap2.build();
    heap2.sort();
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "耗时: " << duration.count() << " 毫秒" << std::endl;
    //std::heap_sort
    start = std::chrono::high_resolution_clock::now();
    std::make_heap(orderedList.begin(), orderedList.end(), std::greater<int>());
    std::sort_heap(orderedList.begin(), orderedList.end(), std::greater<int>());
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "耗时: " << duration.count() << " 毫秒" << std::endl;

//reverse sequence
    std::cout << "reverse sequence" << std::endl;
    vector<int> reverseList;
    for (long long i = length-1; i >= 0; --i) {
        reverseList.push_back(i);
    }
    Heap<int> heap3(reverseList);
    //my_heap_sort
    start = std::chrono::high_resolution_clock::now();
    heap3.build();
    heap3.sort();
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "耗时: " << duration.count() << " 毫秒" << std::endl;
    //std::heap_sort
    start = std::chrono::high_resolution_clock::now();
    std::make_heap(reverseList.begin(), reverseList.end(), std::greater<int>());
    std::sort_heap(reverseList.begin(), reverseList.end(), std::greater<int>());
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "耗时: " << duration.count() << " 毫秒" << std::endl;

//repetitive sequence
    std::cout << "repetitive sequence" << std::endl;
    auto repetitiveList = generateRandomInitializerList(length, 10000);
    Heap<int> heap4(repetitiveList);
    //my_heap_sort
    start = std::chrono::high_resolution_clock::now();
    heap4.build();
    heap4.sort();
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "耗时: " << duration.count() << " 毫秒" << std::endl;
    //std::heap_sort
    start = std::chrono::high_resolution_clock::now();
    std::make_heap(repetitiveList.begin(), repetitiveList.end(), std::greater<int>());
    std::sort_heap(repetitiveList.begin(), repetitiveList.end(), std::greater<int>());
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "耗时: " << duration.count() << " 毫秒" << std::endl;


}