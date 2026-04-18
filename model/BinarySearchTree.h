//
// Created by qt55eq on 2026. 04. 18..
//

#ifndef CPPHAZIK_BINARYSEARCHTREE_H
#define CPPHAZIK_BINARYSEARCHTREE_H

#include <iterator>
#include <ostream>

template<typename Key, typename Value>
class BinarySearchTree {
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(const Key& k, const Value& v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    template<typename T>
    class Stack {
        T* data_;
        int size_;
        int capacity_;

        void grow() {
            int newCap = capacity_ == 0 ? 4 : capacity_ * 2;
            T* newData = new T[newCap];
            for (int i = 0; i < size_; ++i)
                newData[i] = data_[i];
            delete[] data_;
            data_ = newData;
            capacity_ = newCap;
        }

    public:
        Stack() : data_(nullptr), size_(0), capacity_(0) {}
        ~Stack() { delete[] data_; }

        Stack(const Stack& other) : data_(nullptr), size_(other.size_), capacity_(other.capacity_) {
            if (capacity_ > 0) {
                data_ = new T[capacity_];
                for (int i = 0; i < size_; ++i)
                    data_[i] = other.data_[i];
            }
        }

        Stack(Stack&& other) noexcept : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }

        Stack& operator=(const Stack& other) {
            if (this == &other) return *this;
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            if (capacity_ > 0) {
                data_ = new T[capacity_];
                for (int i = 0; i < size_; ++i)
                    data_[i] = other.data_[i];
            } else {
                data_ = nullptr;
            }
            return *this;
        }

        Stack& operator=(Stack&& other) noexcept {
            if (this == &other) return *this;
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
            return *this;
        }

        void push(const T& val) {
            if (size_ == capacity_) grow();
            data_[size_++] = val;
        }

        void pop() { --size_; }

        T& top() { return data_[size_ - 1]; }
        const T& top() const { return data_[size_ - 1]; }
        [[nodiscard]] bool empty() const { return size_ == 0; }
    };

    Node* root;

    Node* insertNode(Node* node, const Key& key, const Value& value);
    Node* findOrInsert(Node*& node, const Key& key);
    Node* find(Node* node, const Key& key) const;

    static Node* findMin(Node* node);
    Node* removeNode(Node* node, const Key& key);
    void clearAll(Node* node);
    Node* copy(Node* node);

public:
    struct Entry {
        const Key& key;
        Value& value;
    };

    class Iterator {
        Stack<Node*> stack_;

        void pushLeft(Node* node) {
            while (node != nullptr) {
                stack_.push(node);
                node = node->left;
            }
        }

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type        = Entry;
        using difference_type   = std::ptrdiff_t;
        using pointer           = void;
        using reference         = Entry;

        Iterator() = default;

        explicit Iterator(Node* node) { pushLeft(node); }

        Entry operator*() const {
            return {stack_.top()->key, stack_.top()->value};
        }

        Iterator& operator++() {
            Node* current = stack_.top();
            stack_.pop();
            pushLeft(current->right);
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        bool operator==(const Iterator& other) const {
            if (stack_.empty() && other.stack_.empty()) return true;
            if (stack_.empty() || other.stack_.empty()) return false;
            return stack_.top() == other.stack_.top();
        }

        bool operator!=(const Iterator& other) const { return !(*this == other); }
    };

    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& other);
    BinarySearchTree(BinarySearchTree&& other) noexcept;
    BinarySearchTree& operator=(const BinarySearchTree& other);
    BinarySearchTree& operator=(BinarySearchTree&& other) noexcept;

    Iterator begin() { return Iterator(root); }
    Iterator end()   { return Iterator(); }

    Value& operator[](const Key& key);
    const Value& operator[](const Key& key) const;

    [[nodiscard]] bool empty() const { return root == nullptr; }
    void clear();
    bool insert(const Key& key, const Value& value);
    bool remove(const Key& key);
    bool contains(const Key& key) const;

    friend std::ostream& operator<<(std::ostream& os, BinarySearchTree& bst) {
        os << "{";
        bool first = true;
        for (auto entry : bst) {
            if (!first) os << ", ";
            os << entry.key << ": " << entry.value;
            first = false;
        }
        return os << "}";
    }
};

#include "BinarySearchTree.tpp"

#endif //CPPHAZIK_BINARYSEARCHTREE_H