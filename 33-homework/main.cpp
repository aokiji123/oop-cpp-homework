#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>
class Greater 
{
public:
    bool operator()(const T& a, const T& b) const { return a > b; }
};

template <typename T>
class SortStrategy abstract 
{
public:
    virtual void Sort(vector<T>& v) abstract;
};

template <typename T>
class IncreasingSTLSort : public SortStrategy<T> 
{
public:
    void Sort(vector<T>& v) override { sort(v.begin(), v.end()); }
};

template <typename T>
class DecreasingSTLSort : public SortStrategy<T> 
{
public:
    void Sort(vector<T>& v) override { sort(v.begin(), v.end(), Greater<T>()); }
};

template <typename T>
class IncreasingShellSort : public SortStrategy<T> 
{
public:
    void Sort(vector<T>& v) override
    {
        int step = v.size() / 2;
        while (step > 0) {
            for (int i = 0; i < (v.size() - step); i++) 
            {
                int j = i;
                while (j >= 0 && v[j] > v[j + step]) 
                {
                    T temp = v[j];
                    v[j] = v[j + step];
                    v[j + step] = temp;
                    j--;
                }
            }
            step /= 2;
        }
    }
};

template <typename T>
class DecreasingShellSort : public SortStrategy<T> 
{
public:
    void Sort(vector<T>& v) override
    {
        int step = v.size() / 2;
        while (step > 0) {
            for (int i = 0; i < (v.size() - step); i++) 
            {
                int j = i;
                while (j >= 0 && v[j] > v[j + step]) 
                {
                    T temp = v[j];
                    v[j] = v[j + step];
                    v[j + step] = temp;
                    j--;
                }
            }
            step /= 2;
        }
        v.reserve();
    }
};

template <typename T>
class IncreasingBubbleSort : public SortStrategy<T> 
{
public:
    void Sort(vector<T>& v) override
    {
        for (int k = v.size() - 1; k > 0; k--) 
        {
            for (int i = 0; i < k; i++) 
            {
                if (v[i] > v[i + 1]) 
                {
                    T buf = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = buf;
                }
            }
        }
    }
};

template <typename T>
class DecreasingBubbleSort : public SortStrategy<T> 
{
public:
    void Sort(vector<T>& v) override
    {
        for (int k = v.size() - 1; k > 0; k--) 
        {
            for (int i = 0; i < k; i++) 
            {
                if (v[i] < v[i + 1]) 
                {
                    T buf = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = buf;
                }
            }
        }
    }
};

template <typename T>
class SortedArray 
{
private:
    vector<T> vector;
    SortStrategy<T>* sortstrategy;

public:
    void SetSortStrategy(SortStrategy<T>* sortstrategy) { this->sortstrategy = sortstrategy; }
    void Add(T value) { vector.push_back(value); }
    void Sort()
    {
        sortstrategy->Sort(vector);
        for (T val : vector)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
};

int main()
{
    SortedArray<string> arrStr;

    arrStr.Add("Adapter");
    arrStr.Add("Decorator");
    arrStr.Add("Factory");
    arrStr.Add("Prototype");

    IncreasingSTLSort<string> increasingSTLSort;
    arrStr.SetSortStrategy(&increasingSTLSort);
    arrStr.Sort();

    arrStr.Add("Singleton");
    arrStr.Add("Visitor");

    DecreasingBubbleSort<string> decreasingBubbleSort;
    arrStr.SetSortStrategy(&decreasingBubbleSort);
    arrStr.Sort();

    cout << "\n" << "\n";

    SortedArray<int> arrInt;

    arrInt.Add(4);
    arrInt.Add(3);
    arrInt.Add(6);
    arrInt.Add(8);
    arrInt.Add(1);
    arrInt.Add(9);

    IncreasingShellSort<int> increasingShellSort;
    arrInt.SetSortStrategy(&increasingShellSort);
    arrInt.Sort();

    arrInt.Add(5);
    arrInt.Add(2);

    DecreasingSTLSort<int> decreasingSTLSort;
    arrInt.SetSortStrategy(&decreasingSTLSort);
    arrInt.Sort();
}