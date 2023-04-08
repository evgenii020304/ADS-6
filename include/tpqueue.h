// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T, int size>
class TPQueue {
 private:
  T* arr;
  int sizeM;
  int first, last;
  int count;

 public:
  TPQuene() : sizeM(size), first(0), last(0), count(0) {
    arr = new T[sizeM + 1];
  }
  
  ~TPQuene() {
    delete[] arr;
  }
  
  void push(const T& value) {
    assert(count < sizeM);
    if (count == 0) {
      arr[last++] = value;
      count++;
    } else {
      int i = last - 1;
      bool flag = 0;
      while (i >= first && value.prior > arr[i].prior) {
        flag = 1;
        arr[i + 1] = arr[i];
        arr[i] = value;
        i--;
      }
      if (flag == 0) {
        arr[last] = value;
      }
      last++;
      count++;
    }
    if (last > sizeM) {
      last -= sizeM + 1;
    }
  }
  
  const T& pop() {
    assert(count > 0);
    count--;
    if (first > sizeM) {
      first -= sizeM + 1;
    }
    return arr[first++];
  }
  
  const T& get() {
    assert(count > 0);
    return arr[first];
  }
  
  bool isFull() const {
    return count == sizeM;
  }
  
  bool isEmpty() const {
    return count == 0;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
