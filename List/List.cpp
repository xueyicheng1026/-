#include "List.h"
#include <iostream>

using namespace std;

int main()
{
    List<int> lst1;
    List<int> lst2 {1,3,5,7,9};
    List<int> lst3 = lst2;
    List<int> lst4 = List<int>({2,4,6,8,10});
    const List<int> lst5(lst3);
    //List的默认构造函数，带参数列表构造函数，赋值运算（左值/右值），拷贝函数调用
    for (int i = 0; i < 10; ++i)
    {
        if (i % 2 == 0) 
            lst1.push_back(i);
        else 
            lst1.push_front(i);
    }
    //push_back push_front的调用
    lst1.push_back(13);
    //包含了insert右值版的调用
    lst1.printList(); 
    lst2.printList(); 
    lst3.printList(); 
    lst4.printList(); 
    lst5.printList(); 
    //printList内调用了begin 和 end
    //begin end 包含了const_iterator 和 iterator 的构造函数的调用
    std::cout << lst1.size() << std::endl;
    //size()
    lst2.clear();
    //clear()
    std::cout << lst2.empty() << std::endl;
    //empty()
    std::cout << lst1.front() << std::endl;
    std::cout << lst1.back() << std::endl;
    lst1.front() = 100;
    lst1.back() = 200;
    //front和back静态和动态的调用 包含了 begin()只读 和 可读可写 两个版本
    //end() 返回的是tail为什么需要动态版本？？？
    lst1.printList();
    lst1.pop_front(); lst1.pop_back();
    //pop_front() pop_back()的调用 包含了erase单个迭代器的调用
    lst1.printList();
    std::cout << *lst1.erase(lst1.begin()) << std::endl;
    lst1.printList();
    //erase单个迭代器调用，并且确认返回值是否正确
    std::cout << *lst1.erase(lst1.begin(), --(lst1.end())) << std::endl;
    //erase一串迭代器调用，并且查看是否返回的是最后一个迭代器
    lst1.printList();//查看lst1的erase结果
    lst3.printList();
    auto a = lst3.begin();
    std::cout << *(a++) << std::endl;
    std::cout << *(++a) << std::endl;
    std::cout << *(a--) << std::endl;
    std::cout << *(--a) << std::endl;
    //iterator前置/后置++和-- operator*(包含retrieve)调用
    auto b = lst5.begin();
    std::cout << *(b++) << std::endl;
    std::cout << *(++b) << std::endl;
    std::cout << *(b--) << std::endl;
    std::cout << *(--b) << std::endl;
    //const_iterator前置/后置++和-- operator*(包含retrieve)调用
    lst4.printList();
    auto c = lst4.begin();
    lst4.insert(c,50);
    lst4.printList();
    int x = 50;
    auto d = lst4.begin();
    lst4.insert(d,50);
    lst4.printList();
    //insert左值/右值的调用
    return 0;
}
