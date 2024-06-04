#include <iostream>
#include <string>

class MyVector {
private:
    int* vecnum;
    int temp_size;
    int max_size;
public:
    MyVector(int size=1) {
        vecnum = new int[size];
        max_size = size;
        temp_size = 0;
    };
    ~MyVector() {
        delete vecnum;
        temp_size = max_size = 0;
    };
    MyVector(MyVector& mv) {
        MyVector* anothermv = new MyVector();
        *anothermv = mv;
    }
    MyVector& operator=(MyVector mv) {
        this->vecnum = mv.vecnum;
        this->temp_size = mv.temp_size;
        this->max_size = mv.max_size;
        return *this;
    }
    
    void resize() {
        int* newVecnum = new int[max_size * 2];
        std::copy(vecnum, vecnum+temp_size, newVecnum);
        delete vecnum;
        vecnum = newVecnum;
        max_size *= 2;
    }
    
    int size() const { return temp_size; };
    
    int capacity() const { return max_size; };
    
    int get(int index) const { 
        if (index >= temp_size) return -1;
        return vecnum[index]; 
    }
    
    void _push_back(int element) {
        if (temp_size == max_size) resize();
        vecnum[temp_size++] = element;
    }
    
    void insert(int index, int element) {
        if (temp_size == max_size) resize();
        if (index > temp_size) return;
        for (int i = temp_size + 1; i > index; i--) {
            vecnum[i] = vecnum[i - 1];
        }
        vecnum[index] = element;
        temp_size++;
    }
    
    void pop() {
        if (temp_size > 0)
            temp_size--;
    }
    
    void clear() {
        temp_size = 0;
    }
    
    void print() {
        if (temp_size == 0) {
            std::cout << "empty" << std::endl;
            return;
        }
        for (int i = 0; i < temp_size; i++) std::cout << vecnum[i] << ' ';
        std::cout << std::endl; 
    }
    
    int* begin() const {
        return vecnum;
    }
    
    int* end() const {
        return vecnum + temp_size;
    }
};

int main() {
    int n;
    std::cin >> n;
    MyVector myvec;
    while (n--) {
        std::string s;
        std::cin >> s;
        int index = 0, element = 0;
        if (s == "push") {
            std::cin >> element;
            myvec._push_back(element);
        }
        if (s ==    "size"){
            std::cout << myvec.size() << std::endl;
        }
        if (s == "get") {    
            std::cin >> index;
            std::cout << myvec.get(index) << std::endl;
        }
        if (s== "insert") {
            std::cin >> index >> element;
            myvec.insert(index, element);
                
        }
        if (s == "pop") {
            myvec.pop();
        }
        if (s == "clear") {
            myvec.clear();
        }
        if (s == "print") {
            myvec.print();
        }
        if (s == "iterator") {
            if (myvec.size() == 0) {
                std::cout << "empty" << std::endl;
                continue;
            }
            for (int* it = myvec.begin(); it != myvec.end(); it++) {
                std::cout << *(it) << ' ';
            }
            std::cout << std::endl;
        }
        if (s == "foreach") {
            myvec.print();
        }
    }
    
}
