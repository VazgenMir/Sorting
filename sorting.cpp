#include <iostream> 
#include <vector>

template <typename T>
void bubbleSort(std::vector<T>& vec) {
    bool swaped;
    for(int i = 0;i < vec.size() - 1;i++) {
        swaped = false;
        for(int j = 0;j < vec.size() - i - 1;j++) {
            if(vec[j] > vec[j + 1]) {
                std::swap(vec[j],vec[j + 1]);
                swaped = true;    
            }
        }
        if(!swaped) {
            break;
        }
    }
}

template <typename T>
void selectionSort(std::vector<T>& vec) {
    for(int i = 0;i < vec.size() - 1;i++) {
        int minIndex = i;
        for(int j = i + 1;j < vec.size();j++) {
            if(vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(vec[i],vec[minIndex]);
        }
    }
}

template <typename T>
std::vector<T> merge(std::vector<T>& left, std::vector<T>& right) {
    std::vector<T> comb;
    int l = 0;
    int r = 0;
    while(true) {
        if(left[l] < right[r]) {
            comb.push_back(left[l]);
            l++;
        } else {
            comb.push_back(right[r]);
            r++;
        }
        if(l == left.size()) {
            for(int i = r; i < right.size();i++) {
                comb.push_back(right[i]);
            }
            break;
        }
        if(r == right.size()) {
            for(int i = l; i < left.size();i++) {
                comb.push_back(left[i]);
            }
            break;
        }
    }
    return comb;
}

template <typename T>
std::vector<T> mergeSort(std::vector<T>& vec) {
    
    std::vector<T> left(vec.begin(), vec.begin() + vec.size() / 2);
    std::vector<T> right(vec.begin() + vec.size() / 2, vec.end());
    if(left.size() != 1) {
        left = mergeSort(left);
    }
    if(right.size() != 1) {
        right = mergeSort(right);
    }
    return merge(left,right);

}

int main() {
    std::vector<int> vec = {2,5,1,4,7,8};
    vec = mergeSort(vec);
    for(int i = 0;i < vec.size();i++) {
        std::cout << vec[i] << ",";
    }
    std::cout << std::endl;
    return 0;
}