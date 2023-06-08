#include "BinaryTree.h"
#include <iostream>
#include <stack>
#include <queue>

Node::Node(std::string _v) : value(_v)
{
    nodes[0] = nodes[1] = nullptr;
}

BinaryTree::BinaryTree(std::string expression) : root(nullptr)
{
    Update(expression);
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::Print()
{
    std::cout << "PostOrder:\n";
    PostOrder([](Node* n) { std::cout << n->value << ' '; });
    std::cout << "\n\n";
}

std::string BinaryTree::POString()
{
    std::string s;
    PostOrder([&s](Node* n) { s.append(n->value); s.append(" "); });
    return s;
}

void BinaryTree::Evaluate()
{
}

Node* BinaryTree::Create(std::string expression)
{
    auto mExpression = expression.substr();
    int modify = 0;
    int changes = 0;
    for (int i = 0; i < mExpression.length(); i++)
    {
        if (mExpression[i] == ')')
            modify--;
        char c = mExpression[i];
        if (modify)
        {
            mExpression[i] = '_';
            changes++;
        }
        if (c == '(')
            modify++;
    }

    if (changes == mExpression.length() - 2 && changes != 0)
        return Create(expression.substr(1, changes));

    auto a = mExpression.find_last_of("+-");
    auto b = mExpression.find_last_of("*/");

    if (a != b)
    {
        size_t sep = (a + 1 != 0) ? a : b;
        auto root = new Node(expression.substr(sep, 1));
        root->nodes[0] = Create(expression.substr(0, sep));
        root->nodes[1] = Create(expression.substr(sep + 1));
        return root;
    }
    return new Node(expression);
}

void BinaryTree::PostOrder(std::function<void(Node*)> f)
{
    PostOrder(f, root);
}

void BinaryTree::PostOrder(std::function<void(Node*)> f, Node* x)
{
    struct nodeNstate
    {
        Node* node;
        int state;
        nodeNstate(Node* n = nullptr, int s = 0) : node(n), state(s) {}
    };

    std::stack<nodeNstate> s;
    s.push(nodeNstate(x));
    while (!s.empty())
    {
        switch (s.top().state)
        {
        case 0:
            s.top().state = 2;
            if (s.top().node->nodes[0])
                s.push(nodeNstate(s.top().node->nodes[0]));
            break;
        case 1:
            s.top().state = 3;
            f(s.top().node);
            break;
        case 2:
            s.top().state = 1;
            if (s.top().node->nodes[1])
                s.push(nodeNstate(s.top().node->nodes[1]));
            break;
        case 3:
            s.pop();

        default:
            break;
        }
    }
}

void BinaryTree::PreOrder(std::function<void(Node*)> f)
{
    PreOrder(f, root);
}

void BinaryTree::PreOrder(std::function<void(Node*)> f, Node* x)
{
    struct nodeNstate
    {
        Node* node;
        int state;
        nodeNstate(Node* n = nullptr, int s = 1) : node(n), state(s) {}
    };

    std::stack<nodeNstate> s;
    s.push(nodeNstate(x));
    while (!s.empty())
    {
        switch (s.top().state)
        {
        case 0:
            s.top().state = 2;
            if (s.top().node->nodes[0])
                s.push(nodeNstate(s.top().node->nodes[0]));
            break;
        case 1:
            s.top().state = 0;
            f(s.top().node);
            break;
        case 2:
            s.top().state = 3;
            if (s.top().node->nodes[1])
                s.push(nodeNstate(s.top().node->nodes[1]));
            break;
        case 3:
            s.pop();

        default:
            break;
        }
    }
}

void BinaryTree::ByLevel(std::function<void(Node*)> f)
{
    ByLevel(f, root);
}

void BinaryTree::ByLevel(std::function<void(Node*)> f, Node* x)
{
    std::queue<Node*> q;
    q.push(x);
    for (; !q.empty();)
    {
        f(q.front());
        if (q.front()->nodes[0])
            q.push(q.front()->nodes[0]);
        if (q.front()->nodes[1])
            q.push(q.front()->nodes[1]);
        q.pop();
    }
}

void BinaryTree::Update(std::string expression)
{
    for (auto it = expression.begin(); it < expression.end() ;it++)
        if (*it == ' ')
            expression.erase(it);
    root = Create(expression);
}
