#include <iostream>

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Arbre
{
private:
    Node *root;

    Node *inserer_recursif(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->value)
        {
            node->left = inserer_recursif(node->left, value);
        }
        else if (value > node->value)
        {
            node->right = inserer_recursif(node->right, value);
        }

        return node;
    }

public:
    Arbre()
    {
        root = nullptr;
    }

    void inserer(int value)
    {
        root = inserer_recursif(root, value);
    }

    Node *rechercher_minimum(Node *node)
    {
        Node *current = node;

        while (current && current->left != nullptr)
        {
            current = current->left;
        }

        return current;
    }

    Node *supprimer_recursif(Node *node, int value)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (value < node->value)
        {
            node->left = supprimer_recursif(node->left, value);
        }
        else if (value > node->value)
        {
            node->right = supprimer_recursif(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            Node *temp = rechercher_minimum(node->right);
            node->value = temp->value;
            node->right = supprimer_recursif(node->right, temp->value);
        }

        return node;
    }

    void supprimer(int value)
    {
        root = supprimer_recursif(root, value);
    }
};

int main()
{
    Arbre arbre;

    arbre.inserer(50);
    arbre.inserer(30);
    arbre.inserer(70);
    arbre.inserer(20);
    arbre.inserer(40);
    arbre.inserer(60);
    arbre.inserer(80);
    arbre.supprimer(20);

    return 0;
}
