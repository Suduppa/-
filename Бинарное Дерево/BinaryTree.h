#pragma once
#include <functional>
#include <string>

class Node
{
public:
    std::string value;
    Node* nodes[2];

    Node(std::string _v);
};

class BinaryTree
{
public:
    BinaryTree(std::string expression);
    ~BinaryTree();
    void Print();
    std::string POString();
    void Evaluate();
    void PostOrder(std::function<void(Node*)> f);
    void PostOrder(std::function<void(Node*)> f, Node* x);
    void PreOrder(std::function<void(Node*)> f);
    void PreOrder(std::function<void(Node*)> f, Node* x);
    void ByLevel(std::function<void(Node*)> f);
    void ByLevel(std::function<void(Node*)> f, Node* x);
    void Update(std::string expression);

    Node* root;

private:
    Node* Create(std::string expression);
};
