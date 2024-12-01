#include <vector>
#include <iostream>
#include <cmath>
#include <initializer_list>

using std::floor;
using std::vector;
using std::swap;


template <typename T>
class Heap {
private:
    vector<T> data;
    int currentSize = 0;

    void percolate_up(int pos) {
        while (pos > 1 && data[pos] < data[(pos)>>1])
        {
            swap(data[pos], data[pos>>1]);
            pos >>= 1;
        }
    }

    void percolate_down(int pos) {
        while (true) {
            int smallest = pos;
            int left = pos << 1 ;
            int right = (pos << 1) + 1;
            // if (left < currentSize && (data)[left] < (data)[smallest])
            //     smallest = left;
            smallest = (left < currentSize && (data)[left] < (data)[smallest]) ? left : smallest;
            // if (right < currentSize && (data)[right] < (data)[smallest])
            //     smallest = right;
            smallest = (right < currentSize && (data)[right] < (data)[smallest]) ? right : smallest;
            if (smallest == pos) break;
            swap(data[pos], data[smallest]);
            pos = smallest;
        }   
    }

public:
    Heap() {};
    Heap(vector<T> &&vec) : data(std::move(vec)), currentSize(data.size()) {};
    Heap(vector<T> &vec) : data(vec), currentSize(data.size()) {};

    void build() {
        for (int i = currentSize>>1; i>=1; --i) {
            percolate_down(i);
        }
    }
    
    void insert(const T &element) {
        ++currentSize;
        data.push_back(element);
        percolate_up(currentSize);
    }

    void sort() {
        int n = currentSize;
        for (int i = 1; i <= n; ++i){
            swap(data[1], data[currentSize]);
            --currentSize;
            percolate_down(1);
        }
        currentSize = n;
    }
    
    void print() {
        for (int i = 1; i <= currentSize; ++i)
            std::cout << data[i] << " ";
    }
    ~Heap() {};
};
