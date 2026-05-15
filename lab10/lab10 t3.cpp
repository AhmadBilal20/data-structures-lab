//#include <iostream>
//using namespace std;
//
//int findMax(int arr[], int size) {
//
//    if (size == 1) {
//        return arr[0];
//    }
//
//    int max = findMax(arr, size - 1);
//
//
//    if (arr[size - 1] > max) {
//        return arr[size - 1];
//    }
//    else {
//        return max;
//    }
//}
//
//int main() {
//    int arr[] = { 12, 5, 18, 7, 3 };
//    int size = 5;
//
//    int result = findMax(arr, size);
//
//    cout << "Maximum element: ";
//    cout<< result << endl;
//
//    return 0;
//}