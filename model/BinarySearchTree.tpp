//
// Created by qt55eq on 2026. 04. 18..
//

#ifndef CPPHAZIK_BINARYSEARCHTREE_TPP
#define CPPHAZIK_BINARYSEARCHTREE_TPP

#include "BinarySearchTree.h"
#include "KeyNotFoundException.h"

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::Node*
BinarySearchTree<Key, Value>::insertNode(Node* node, const Key& key, const Value& value) {
    if (node == nullptr)
        return new Node(key, value);
    if (key < node->key)
        node->left = insertNode(node->left, key, value);
    else if (node->key < key)
        node->right = insertNode(node->right, key, value);
    return node;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::Node*
BinarySearchTree<Key, Value>::findOrInsert(Node*& node, const Key& key) {
    if (node == nullptr) {
        node = new Node(key, Value{});
        return node;
    }
    if (key < node->key)
        return findOrInsert(node->left, key);
    if (node->key < key)
        return findOrInsert(node->right, key);
    return node;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::Node*
BinarySearchTree<Key, Value>::find(Node* node, const Key& key) const {
    if (node == nullptr)
        return nullptr;
    if (key < node->key)
        return find(node->left, key);
    if (node->key < key)
        return find(node->right, key);
    return node;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::Node*
BinarySearchTree<Key, Value>::findMin(Node* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::Node*
BinarySearchTree<Key, Value>::removeNode(Node* node, const Key& key) {
    if (node == nullptr)
        return nullptr;
    if (key < node->key) {
        node->left = removeNode(node->left, key);
    } else if (node->key < key) {
        node->right = removeNode(node->right, key);
    } else {
        if (node->left == nullptr) {
            Node* right = node->right;
            delete node;
            return right;
        }
        if (node->right == nullptr) {
            Node* left = node->left;
            delete node;
            return left;
        }
        Node* successor = findMin(node->right);
        node->key = successor->key;
        node->value = successor->value;
        node->right = removeNode(node->right, successor->key);
    }
    return node;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clearAll(Node* node) {
    if (node == nullptr) return;
    clearAll(node->left);
    clearAll(node->right);
    delete node;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::Node*
BinarySearchTree<Key, Value>::copy(Node* node) {
    if (node == nullptr) return nullptr;
    Node* newNode = new Node(node->key, node->value);
    newNode->left = copy(node->left);
    newNode->right = copy(node->right);
    return newNode;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree() {
    clearAll(root);
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::BinarySearchTree(const BinarySearchTree& other)
    : root(copy(other.root)) {}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::BinarySearchTree(BinarySearchTree&& other) noexcept
    : root(other.root) {
    other.root = nullptr;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>&
BinarySearchTree<Key, Value>::operator=(const BinarySearchTree& other) {
    if (this == &other) return *this;
    clearAll(root);
    root = copy(other.root);
    return *this;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>&
BinarySearchTree<Key, Value>::operator=(BinarySearchTree&& other) noexcept {
    if (this == &other) return *this;
    clearAll(root);
    root = other.root;
    other.root = nullptr;
    return *this;
}

template<typename Key, typename Value>
Value& BinarySearchTree<Key, Value>::operator[](const Key& key) {
    return findOrInsert(root, key)->value;
}

template<typename Key, typename Value>
const Value& BinarySearchTree<Key, Value>::operator[](const Key& key) const {
    Node* node = find(root, key);
    if (node == nullptr)
        throw KeyNotFoundException{};
    return node->value;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear() {
    clearAll(root);
    root = nullptr;
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::insert(const Key& key, const Value& value) {
    if (contains(key)) return false;
    root = insertNode(root, key, value);
    return true;
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::remove(const Key& key) {
    if (!contains(key)) return false;
    root = removeNode(root, key);
    return true;
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::contains(const Key& key) const {
    return find(root, key) != nullptr;
}

#endif //CPPHAZIK_BINARYSEARCHTREE_TPP