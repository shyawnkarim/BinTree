//
// Created by Shyawn Karim on 10/13/15.
//

#include "BinTree.h"

using namespace std;

ostream &operator<<(ostream &outStream, const BinTree &tree)
{
    tree.inorderHelper(tree.root);
    outStream << endl;
    return outStream;
}

//istream &operator>>(istream &inStream, BinTree &tree)
//{
//    return <#initializer#>;
//}

BinTree::BinTree()
{
    this->root = new Node();
    this->root->left = NULL;
    this->root->right = NULL;
}

BinTree::BinTree(const BinTree &tree)
{

}

BinTree::~BinTree()
{
    this->makeEmpty();
}

bool BinTree::isEmpty() const
{
    return false;
}

void BinTree::makeEmpty()
{
        makeEmptyHelper(root);
}

void BinTree::makeEmptyHelper(Node* current)
{
    if (current != NULL)
    {
        makeEmptyHelper(current->left);
        makeEmptyHelper(current->right);

        delete current->data;
        current->data = NULL;
        delete current;
        current = NULL;
    }
}

BinTree &BinTree::operator=(const BinTree &tree)
{
    if (*this == tree)
    {
        return *this;
    }

    this->makeEmpty();


}

bool BinTree::operator==(const BinTree &tree) const
{
    return false;
}

bool BinTree::operator!=(const BinTree &tree) const
{
    return false;
}

bool BinTree::insert(NodeData* toInsert)
{
    return insertHelper(this->root, toInsert);
}

bool BinTree::insertHelper(Node*& current, NodeData* toInsert)
{
    if (this->root == NULL)
    {
        root = new Node;
        root->data = toInsert;
        root->left = NULL;
        root->right = NULL;
    }
    else if (*toInsert < *root->data)
    {
        insertHelper(root->left, toInsert);
    }
    else if (*toInsert > *root->data)
    {
        insertHelper(root->right, toInsert);
    }
    else
    {
        return false;
    }

    return true;
}

bool BinTree::retrieve(const NodeData &, NodeData* &) const
{
    return false;
}

void BinTree::displaySideways() const
{

}

void BinTree::inorderHelper(Node* traversal) const
{
    if (traversal != NULL)
    {
        inorderHelper(traversal->left);
        cout << *traversal->data << " ";
        inorderHelper(traversal->right);
    }
}

void BinTree::sideways(Node* current, int level) const
{
    if (current != NULL) {
        level++;
        sideways(current->right, level);

        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }

        cout << *current->data << endl;        // display information of object
        sideways(current->left, level);
    }
}
