#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

static int a;
using namespace std;

struct Node
{
    char m_english[15];
    char m_russian[15];

    Node* m_parent;

    Node* m_left;
    Node* m_right;


    char* GetEnglish();
    char* GetRussian();
};

class Tree
{
private:

    // Корень.
    Node* m_root;

    // Количество узлов.
    unsigned int m_size;

public:

    Tree();

    ~Tree();

    // Получить корень.
    Node* GetRoot() const;

    // Вставка узла.
    void Insert(Node* node);

    // Максимальное значение от указанного узла.
    Node* Max(Node* node) const;

    // Минимальное значение от указанного узла.
    Node* Min(Node* node) const;

    // Следующий узел для указанного узла.
    Node* Next(const Node* node) const;

    // Предыдущий узел для указанного узла.
    Node* Previous(const Node* node) const;

    // Печать от указанного узла.
    void Print(const Node* node) const;

    // Удаление ветки для указанного узла.
    void Remove(Node* node);

    // Поиск от указанного узла.
    Node* Search(Node* node, const char* key) const;
};

void Insert(Tree& tree);
void Print(const Tree& tree);
void PrintMenu();
void Remove(Tree& tree);
void Search(const Tree& tree);

int main()
{
    cout << a;

    Tree tree;

    bool exit = false;

    for (;;)
    {
        PrintMenu();

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            Insert(tree);
            break;
        case 2:
            Remove(tree);
            break;
        case 3:
            Print(tree);
            break;
        case 4:
            Search(tree);
            break;
        case 5:
            exit = true;
            break;
        }

        if (exit)
        {
            break;
        }
    }

    return 0;
}

char* Node::GetEnglish()
{
    return m_english;
}

char* Node::GetRussian()
{
    return m_russian;
}

Tree::Tree() : m_root(nullptr), m_size(0U)
{
}

Tree::~Tree()
{
    while (m_root != nullptr)
    {
        Remove(m_root);
    }
}

Node* Tree::GetRoot() const
{
    return m_root;
}

void Tree::Insert(Node* newNode)
{
    // Потомков нет.
    newNode->m_left = nullptr;
    newNode->m_right = nullptr;

    Node* node = m_root;
    Node* temp = nullptr;

    // Поиск места.
    while (node != nullptr)
    {
        // Будущий родитель.
        temp = node;

        if (strcmp(newNode->m_english, node->m_english) < 0)
        {
            node = node->m_left;

        }
        else
        {
            node = node->m_right;
        }
    }

    // Заполняем родителя.
    newNode->m_parent = temp;

    // Элемент первый (единственный).
    if (temp == nullptr)
    {
        m_root = newNode;
    }
    // Опеределение большего ключа.
    else if (strcmp(newNode->m_english, temp->m_english) < 0)
    {
        temp->m_left = newNode;
    }
    else
    {
        temp->m_right = newNode;
    }

    ++m_size;
}

Node* Tree::Max(Node* node) const
{
    // Поиск самого "правого" узла.
    if (node != nullptr)
    {
        while (node->m_right != nullptr)
        {
            node = node->m_right;
        }
    }

    return node;
}

Node* Tree::Min(Node* node) const
{
    // Поиск самого "левого" узла.
    if (node != nullptr)
    {
        while (node->m_left != nullptr)
        {
            node = node->m_left;
        }
    }

    return node;
}

Node* Tree::Next(const Node* node) const
{
    Node* next = nullptr;

    if (node != nullptr)
    {
        // Если есть правый потомок.
        if (node->m_right != nullptr)
        {
            next = Min(node->m_right);
        }
        else
        {
            // Родитель узла.
            next = node->m_parent;

            // Если node не корень и node справа.
            while (next != nullptr && node == next->m_right)
            {
                // Движемся вверх.
                node = next;
                next = next->m_parent;
            }
        }
    }

    return next;
}

Node* Tree::Previous(const Node* node) const
{
    Node* previous = nullptr;

    if (node != nullptr)
    {
        // Если есть левый потомок.
        if (node->m_left != nullptr)
        {
            previous = Max(node->m_left);
        }
        else
        {
            // Родитель узла.
            previous = node->m_parent;

            // Если node не корень и node слева.
            while (previous != nullptr && node == previous->m_left)
            {
                // Движемся вверх.
                node = previous;
                previous = previous->m_parent;
            }
        }
    }

    return previous;
}

void Tree::Print(const Node* node) const
{
    if (node != nullptr)
    {
        Print(node->m_left);

        cout << node->m_english << '\t' << node->m_russian << endl;

        Print(node->m_right);
    }
}

void Tree::Remove(Node* removeNode)
{
    if (removeNode != nullptr)
    {
        Node* node = nullptr;
        Node* temp = nullptr;

        // Не 2 дочерних элемента.
        if (removeNode->m_left == nullptr || removeNode->m_right == nullptr)
        {
            temp = removeNode;
        }
        else
        {
            temp = Next(removeNode);
        }

        if (temp->m_left != nullptr)
        {
            node = temp->m_left;
        }
        else
        {
            node = temp->m_right;
        }

        if (node != nullptr)
        {
            node->m_parent = temp->m_parent;
        }

        // Удаляется корневой узел?
        if (temp->m_parent == nullptr)
        {
            m_root = node;
        }
        // Слева от родителя?
        else if (temp == temp->m_parent->m_left)
        {
            temp->m_parent->m_left = node;
        }
        // Справа от родителя?
        else
        {
            temp->m_parent->m_right = node;
        }

        if (temp != removeNode)
        {
            // Копирование данных узла.
            strcpy(removeNode->m_english, temp->m_english);
            strcpy(removeNode->m_russian, temp->m_russian);
        }

        delete temp;

        --m_size;
    }
}

Node* Tree::Search(Node* node, const char* key) const
{
    // Пока есть узлы и ключи не совпадают.
    while (node != nullptr && strcmp(key, node->m_english) != 0)
    {
        if (strcmp(key, node->m_english) < 0)
        {
            node = node->m_left;
        }
        else
        {
            node = node->m_right;
        }
    }

    return node;
}



void Insert(Tree& tree)
{
    cout << "Enter a quantity of elements to add: ";

    unsigned int count = 0U;
    cin >> count;

    for (unsigned int i = 0U; i < count; ++i)
    {
        Node* temp = new Node;

        cout << endl << "Enter an english word " << i + 1 << endl;
        cin >> temp->GetEnglish();

        cout << endl << "Enter a russian word " << i + 1 << endl;
        cin >> temp->GetRussian();

        tree.Insert(temp);
    }
}

void Print(const Tree& tree)
{
    tree.Print(tree.GetRoot());

   
}

void PrintMenu()
{
    char menu[] = "1. Insert node\n2. Remove node\n3. Print node\n4. Search node\n5. Exit\n";

    cout << menu;
}

void Remove(Tree& tree)
{
    cout << "Enter an english word to remove:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    tree.Remove(node);
}

void Search(const Tree& tree)
{

    cout << "Enter an english word to search:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    if (node != nullptr)
    {
        cout << node->GetRussian();
    }
    else
    {
        cout << "Word not found" << endl;
    }


}
