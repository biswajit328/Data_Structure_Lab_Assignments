#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Compare = std::less<T>>
class BinaryHeapPQ {
private:
    vector<T> data;
    Compare cmp;

    inline int parent(int i) const { return (i - 1) / 2; }
    inline int left(int i) const { return 2 * i + 1; }
    inline int right(int i) const { return 2 * i + 2; }

    void siftDown(int i) {
        int n = data.size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int best = i;

            if (l < n && cmp(data[best], data[l])) best = l;
            if (r < n && cmp(data[best], data[r])) best = r;

            if (best == i) break;
            swap(data[i], data[best]);
            i = best;
        }
    }

    void siftUp(int i) {
        while (i > 0) {
            int p = parent(i);
            if (cmp(data[p], data[i])) {
                swap(data[p], data[i]);
                i = p;
            } else break;
        }
    }

public:
    BinaryHeapPQ() = default;

    BinaryHeapPQ(const vector<T>& elems) : data(elems) {
        for (int i = data.size() / 2 - 1; i >= 0; --i) {
            siftDown(i);
        }
    }

    void push(const T& val) {
        data.push_back(val);
        siftUp(data.size() - 1);
    }

    template<typename... Args>
    void emplace(Args&&... args) {
        data.emplace_back(std::forward<Args>(args)...);
        siftUp(data.size() - 1);
    }

    const T& top() const {
        if (data.empty()) throw runtime_error("top() on empty heap");
        return data.front();
    }

    void pop() {
        if (data.empty()) throw runtime_error("pop() on empty heap");
        if (data.size() == 1) {
            data.pop_back();
            return;
        }
        data[0] = data.back();
        data.pop_back();
        siftDown(0);
    }

    int size() const { return data.size(); }
    bool empty() const { return data.empty(); }
    void clear() { data.clear(); }

    const vector<T>& container() const { return data; }
};

int main() {
    BinaryHeapPQ<int> maxpq;
    maxpq.push(5);
    maxpq.push(1);
    maxpq.push(7);
    maxpq.push(3);
    cout << maxpq.top() << "\n";
    maxpq.pop();
    cout << maxpq.top() << "\n";

    BinaryHeapPQ<int, std::greater<int>> minpq;
    minpq.push(5);
    minpq.push(1);
    minpq.push(7);
    minpq.push(3);
    cout << minpq.top() << "\n";
    minpq.pop();
    cout << minpq.top() << "\n";

    vector<int> v = {10, 4, 9, 1, 7, 3};
    BinaryHeapPQ<int> fromVec(v);
    cout << fromVec.top() << "\n";

    struct Item { int priority; string name; };
    auto cmp = [](const Item& a, const Item& b) { return a.priority < b.priority; };
    BinaryHeapPQ<Item, decltype(cmp)> itemPQ(cmp);
    itemPQ.push({2, "low"});
    itemPQ.push({10, "high"});
    cout << itemPQ.top().name << " " << itemPQ.top().priority << "\n";

    return 0;
}
