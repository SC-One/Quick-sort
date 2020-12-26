#include <iostream>
template <typename Type>
int partition(Type* arr, int from, int to) {  // [from - to]
  int before{from};
  for (int i{from}; i < to; i++) {
    if (arr[i] < arr[to]) {
      auto temp{arr[i]};
      arr[i] = arr[before];
      arr[before] = temp;
      before++;
    }
  }
  auto temp{arr[to]};
  arr[to] = arr[before];
  arr[before] = temp;
  return before;
}

template <typename Type>
void quickSort(Type* arr, int from, int to) {
  if (to >= from) {
    int q = partition(arr, from, to);
    quickSort(arr, from, q - 1);
    quickSort(arr, q + 1, to);
  }
}

int main() {
  int a[10] = {5, 3, 2, 1, 6, 42, 2, 5, 2, 32};
  quickSort(a, 0, 9);
  for (int i{0}; i < 10; ++i) std::cout << a[i] << "\t";
  return 0;
}
