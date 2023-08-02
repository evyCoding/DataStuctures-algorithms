#include <iostream>
#include <cstdlib>
#include <cstdio>

class Array
{
public:
    int* Arr;
    int length;
    int size;
    //constructor
    explicit Array()
    {
        size = 20;
        length = 10;
        Arr = new int[size];
    }
    //destructor
    ~Array() { delete [] Arr; };
    //functions
    [[nodiscard]] int set(int i, int x) const;
    [[nodiscard]] int Get(int i) const;
    [[nodiscard]] int min() const;
    [[nodiscard]] int max() const;
    [[nodiscard]] int sum() const;
    [[nodiscard]] int avg() const;
    //fill functions
    void fill();
    // todo !!!
    int find_the_missing_element_1();
    void find_the_missing_element_2_v1();
    void find_the_missing_element_2_v2();
    void search_for_dup_1();
    void search_for_dup_2();
    void search_for_dup_3();
    void search_for_dup_4();
    void search_for_dup_5();
    void find_pair_1(int target);
    void find_pair_2(int target);
    void find_pair_3_sorted(int target);
    void max_and_min();
};

int Array::set(int i, int x) const {
    if(i >= length && i < 0) return -1;
    else {
        Arr[i] = x;
        return Arr[i];
    }
}

int Array :: Get(int i) const {
    if(i >= length && i < 0) return -1;
    else return Arr[i];
}

int Array :: min() const
{
    int MIN(Arr[0]);
    for(int i = 1; i < length; i++) if(Arr[i] < MIN) MIN = Arr[i];
    return MIN;
}

int Array :: avg() const
{
    int AVG(0);
    for(int i = 0; i < length; i++) AVG += Arr[i];
    return AVG / length;
}

int Array :: sum() const
{
    long SUM(0);
    for(int i = 0; i < length; i++) SUM += Arr[i];
    return SUM;
}

void insert(Array* o, int index, int value)
{
    if (index >= o->size) return;
    if (index >= o->length) o->Arr[index] = value;
    else {
        for (int i = o->length + 1; i >= index; i--) {
            if (i == index) o->Arr[index] = value;
            else o->Arr[i] = o->Arr[i - 1];
        }
    }
}

void Delete(Array* o, int index)
{
    if (index >= o->size) return;
    if (index >= o->length) return;
    else {
        for(int i = index; i < o->length; i++) {
            o->Arr[i] = o->Arr[i+1];
        }
    }
}

int * search_v2(Array *o, int target)
{
    int *ptr = nullptr;
    for(int i = 0; i < o->length; i++) {
        if(o->Arr[i] == target) {
            ptr = &i;
            return ptr;
        }
    }
    return ptr;
}

int * search_v1(Array *o, int target)
{
    int *p = nullptr;
    for(int i = 0; i < o->length; i++) {
        if(o->Arr[i] == target) {
            p = &i;
            int temp = o->Arr[i];
            o->Arr[i] = o->Arr[i-1];
            o->Arr[i-1] = temp;
            return p;
        }
    }
    return p;
}

int* binary_search(Array* oo, int target)
{
    int* ptr = nullptr;
    int l(0);
    int h(oo->length - 1);
    while (l <= h) {
        int mid = (h + l) / 2;
        if (target == oo->Arr[mid]) {
            ptr = &mid;
            return ptr;
        }
        if (oo->Arr[mid] > target) h = mid - 1;
        if (oo->Arr[mid] < target) l = mid + 1;
    }
    return ptr;
}

void reverse_v1(Array *a)
{
    const int B_SIZE = a->length;
    int B[B_SIZE];
    for(int i = a->length - 1, j = 0; i >= 0, j < a->length; i--, j++) {
        B[j] = a->Arr[i];
    }
    for(int i = 0; i < a->length; i++) {
        a->Arr[i] =  B[i];
    }
}

inline void reverse_v2(Array *o) { for(int i = 0, j = o->length - 1; i < j; i++, j--) std::swap(o->Arr[i], o->Arr[j]); }

void insertXOrdred (Array *o, int target)
{
    int i = o->length - 1;
    while(target < o->Arr[i]) {
        o->Arr[i + 1] = o->Arr[i];
        i--;
    }
    o->Arr[i + 1] = target;
}

bool isSorted(Array *o)
{
    for(int i = 0; i < o->length - 1; i++) if(o->Arr[i] > o->Arr[i + 1]) return false;
    return true;
}

template<typename T>
void print(T A[]) {
    for (int i = 0; i < sizeof(A) / sizeof(T); i++) {
        std::cout << A[i] << ' ';
    }
}

void REarrange(Array *o)
{
    int i = 0;
    int j = o->length - 1;
    while(i < j) {
        while(o->Arr[i] < 0) i++;
        while(o->Arr[j] >= 0) j--;
        if (i < j) std::swap(o->Arr[i], o->Arr[j]);
    }
}

Array * merge (Array *o, Array *oo)
{
    auto *ooo = new Array;
    ooo->Arr = new int[o->length + oo->length];
    int i, j, k;
    i = j = k = 0;
    while(i < o->length && j < oo->length) {
        if(o->Arr[i] < oo->Arr[j])
            ooo->Arr[k++] = o->Arr[i++];
        else
            ooo->Arr[k++] = oo->Arr[j++];
    }
    for(; i < o->length; i++) ooo->Arr[k++] = o->Arr[i];
    for(; j < oo->length; j++) ooo->Arr[k++] = oo->Arr[j];
    return ooo;
}

Array * Merge (Array *o, Array *oo)
{
    auto *ooo = new Array;
    ooo->Arr = new int[o->length + oo->length];
    int i, j, k;
    i = j = k = 0;
    while(i < o->length && j < oo->length) {
        if(o->Arr[i] == oo->Arr[j])
            ooo->Arr[k++] = o->Arr[i++];
        if(o->Arr[i] < oo->Arr[j])
            ooo->Arr[k++] = o->Arr[i++];
        else
            ooo->Arr[k++] = oo->Arr[j++];
    }
    for(; i < o->length; i++) ooo->Arr[k++] = o->Arr[i];
    for(; j < oo->length; j++) ooo->Arr[k++] = oo->Arr[j];
    return ooo;
}

Array * Union(Array *o1, Array *o2)
{
    if(isSorted(o1) && isSorted(o2)) return Merge(o1, o2);
    else {
        auto *o3 = new Array;
        o3->Arr = new int[o1->length + o2->length];
        o3->length =0;
        int i(0);
        for(i = 0; i < o1->length; i++) {
            o3->Arr[i] = o1->Arr[i];
            o3->length++;
        }
        for(i = 0; i < o2->length; i++, o3->length++) if(*search_v2(o3, o2->Arr[i]) != -1) o3->Arr[o3->length] = o2->Arr[i];
        return o3;
    }
}

Array * intersection(Array *o1, Array *o2)
{
    auto *o3 = new Array;
    o3->Arr = new int[o1->length + o2->length];
    o3->length =0;
    if(isSorted(o1) && isSorted(o2)) {
        int i, j;
        i = j = 0;
        while(i < o1->length, j < o2->length) {
            if(o1->Arr[i] < o2->Arr[j]) i++;
            else if (o1->Arr[i] < o2->Arr[j]) j++;
            else if (o1->Arr[i] == o2->Arr[j]) {
                o3->Arr[o3->length] = o1->Arr[i];
                o3->length++;
                j++;
            }
        }
    }
    else {
        int i = 0;
        for(i; i < o1->length; i++){
            int index;
            index = *search_v2(o2, o1->Arr[i]);
            if(index != -1) {
                o3->Arr[o3->length] = o1->Arr[i];
                o2->Arr[index] = -258;
                o3->length++;
            }
        }
    }
    return o3;
}

void Array :: fill()
{
    Arr[0] = 1;
    Arr[1] = 2;
    Arr[2] = 6;
    Arr[3] = 7;
    Arr[4] = 8;
    Arr[5] = 9;
    Arr[6] = 10;
    Arr[7] = 13;
    Arr[8] = 14;
    Arr[9] = 15;

}

int Array::find_the_missing_element_1()
{
    fill();
    int sum(0), formula;
    formula = ((Arr[length - 1]) * (Arr[length - 1] + 1)) / 2;
    for (int i = 0; i < length; i++) sum += Arr[i];
    return formula - sum;
}

void Array::find_the_missing_element_2_v1() {
    fill();
    int Diff = Arr[0];
    for(int i = 0; i < length; i++) {
        if(Arr[i] - i != Diff) {
            while(Arr[i] - i > Diff) {
                std::cout << Diff + i << '\n';
                Diff++;
            }
        }

    }
}

void Array::find_the_missing_element_2_v2() {
    fill();
    int i, h = Arr[length - 1];
    int *Hash = new int[h];
    for(i = 0; i < h; i++) Hash[i] = 0;
    for(i = 0; i < length; i++) Hash[Arr[i]] = 1;
    for(i = 1; i < h; i++)
        if(Hash[i] == 0) std::cout << i << '\n';
    delete [] Hash;
}

int Array::max() const {
        int MAX(Arr[0]);
        for(int i = 1; i < length; i++) if(Arr[i] > MAX) MAX = Arr[i];
        return MAX;
}

void Array :: search_for_dup_1() {
    fill();
    int Last_Dup (-258);
    for(int i = 0; i < length - 1; i++) {
        if(Arr[i] == Arr[i + 1] && Arr[i] == Last_Dup) {
            std::cout << Arr[i] << '\n';
            Last_Dup = Arr[i];
        }
    }
}

void Array :: search_for_dup_2() {
    fill();
    int i = 0, j = i + 1;
    while (i < length) {
        if(Arr[i] == Arr[j]) {
            while(Arr[i] == Arr[j]) j++;
            std::cout << Arr[i] << " appear " << j - i << " times" << '\n';
            i = j - 1;
        }
        else  {
            i++;
            j++;
        }
    }
}

void Array :: search_for_dup_3() {
    fill();
    int l = Arr[0], h = Arr[length - 1], i = 0;
    int *Hash = new int[h];
    for(i = 0; i < h; i++) Hash[i] = 0;
    for(i = 0; i < length; i++) Hash[Arr[i]]++;
    for(i = 0; i < h; i++)
        if(Hash[i] > 1) std::cout << i << " appear " << Hash[i] << " times" << '\n';
    delete [] Hash;
}

void Array :: search_for_dup_4()
{
    fill();
    int count(1);
    for(int i = 0; i < length - 1; i++) {
        count = 1;
        if(Arr[i] == -258) continue;
        for(int j = i + 1; j < length; j++) {
            if(Arr[i] == Arr[j])  {
                count++;
                Arr[j] = -258;
            }
        }
        if(count > 1) std::cout << Arr[i] << " appear " << count << " times" << '\n';
    }
}

void Array::search_for_dup_5()
{
    fill();
    int i, h = max();
    int *Hash = new int[h];
    for(i = 0; i < h; i++) Hash[i] = 0;
    for(i = 0; i < length; i++) Hash[Arr[i]]++;
    for(i = 0; i < h; i++)
        if(Hash[i] > 1) std::cout << i << " appear " << Hash[i] << " times" << '\n';
    delete [] Hash;
}

void Array::find_pair_1(int target)
{
    fill();
    for(int i = 0; i < length - 1; i++) {
        for(int j = i + 1; j < length; j++) {
            if(Arr[i] + Arr[j] == target) {
                std::cout << Arr[i] << " + "<< Arr[j] << " = " << target << '\n';
            }
        }
    }
}

void Array::find_pair_2(int target)
{
    fill();
    int i, h = max();
    int *Hash = new int[h];
    for(i = 0; i < h; i++) Hash[i] = 0;
    for(i = 0; i < length; i++) Hash[Arr[i]]++;
    for(i = 0; i < h; i++)
        if(Hash[i] >= 1 && Hash[target - i] >= 1) {
            std::cout << i << " + "<< target - i << " = " << target << '\n';
            Hash[i] = -258;
        }
    delete [] Hash;
}

void Array::find_pair_3_sorted(int target) {
    fill();
    int i = 0, j = length - 1;
    while(i < j) {
        if(Arr[i] + Arr[j] == target) {
            std::cout << Arr[i] << " + "<< Arr[j] << " = " << target << '\n';
            i++;
            j--;
        }
        else if(Arr[i] + Arr[j] > target) j--;
        else i++;
    }
}

void Array :: max_and_min()
{
    fill();
    int max, min;
    max = min = Arr[0];
    for(int i = 1; i < length; i++) {
        if(Arr[i] < min) min = Arr[i];
        else if(Arr[i] > max) max = Arr[i];
    }
    std::cout << max << " & " << min;
}

int main()
{
    auto *a = new Array;
    for (int i = 0; i < 10; i++) a->Arr[i] = i + 1;
    std::cout << *binary_search(a, 7);
    delete[] a->Arr;
    delete a;
}

