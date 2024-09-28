/*#include "wordFrequency.h"

BinaryTree::BinaryTree()
{
    this->root = NULL;
    this->numElements = 0;

}
BinaryTree::~BinaryTree()
{

    this->deleteEverything(this->root);

}

BinarySearchNode* BinaryTree::insert(string insertWord)
{
    /*
    BST property for our way through the tree 
    find where node belongs and hook into tree after building the node
    function returns the pointer to the newly constructed node
    if value is already in the tree, that pointer is returned instead
    */
   /*
   
   if(this->root == NULL)
   {
       //insert into empty tree
       this->root = new BinarySearchNode(insertWord);
       return this->root;
   }
   else
   {
       //node that walks the tree
       BinarySearchNode* walk = this->root;
       bool keepWalking = true;

       while(keepWalking)
       {
           keepWalking = false;

           if(insertWord == walk->getWord())
           {
               //duplicate!
               return walk;
           }
           else if(insertWord < walk->getWord())
           {
               //smaller goes left
               if(walk->getLeft() != NULL)
               {
                   walk = walk->getLeft();
                   keepWalking = true;
               }
               else
               {
                   //found place, build and hook in new node
                   walk->setLeft(new BinarySearchNode(insertWord));
                   this->numElements++;
                   return walk->getLeft();
               }
           }
           else
           {
               if(walk->getRight() != NULL)
               {
                   walk = walk->getRight();
                   keepWalking = true;
               }
               else
               {
                   //found place in right node
                   walk->setRight(new BinarySearchNode(insertWord));
                   this->numElements++;
                   return walk->getRight();
               }
           }
       }
   }

    return NULL;
} //insert function ends here

BinarySearchNode* BinaryTree::find(string word)
{
    return this->findHelper(word, this->root);

}

void BinaryTree::remove(string removeWord)
{
    delete this->findHelper(removeWord, this->root);

}

bool BinaryTree::exists(string doesExist)
{
    BinarySearchNode* result = this->findHelper(doesExist, this->root);
    if(result == NULL)
    {
        return false;
    }else
    {
        return true;
    }
    

}

string* BinaryTree::toArray(string wordToArray)
{

}

void BinaryTree::deleteEverything(BinarySearchNode* deleting)
{
    //use post order traversal to delete
    if(deleting!=NULL)
    {
        deleteEverything(deleting->getLeft());
        deleteEverything(deleting->getRight());
        delete deleting;
    }
    
    this->numElements = 0;
}

int BinaryTree::howManyElements()
{
    return this->numElements;
}

BinarySearchNode* BinaryTree::findHelper(string findWord, BinarySearchNode* temp)
{
    /*
        compare element to root of tree, if found return 
        pointer, if not then check if less than root (left subtree)
        if not, then check right sub tree 
        repeat using RECURSION to travese through the entire
        tree 
        if not found return null
        
    */
    /*
   
    if(root->getWord() == findWord)
    {
        return root;
    }
    else if(findWord < root->getWord())
    {
        return findHelper(findWord, root->getLeft());
    }
    else if(findWord > root->getWord())
    {
        return findHelper(findWord, root->getRight());
    }
    else if(root == NULL)
    {
        return root;
    }
    else
    {
        return NULL;
    }


}


void BinaryTree::deleteCaseOneChild(BinarySearchNode* parent, BinarySearchNode* remove)
{
    //outer if-else statement to determine where the one child is
    if(remove->getRight() != NULL) //remove hasa right child only
    {
        //shuffle the pointers
        if(parent->getRight() == remove)
        {
            parent->setRight(remove->getRight());
        }
        else
        {
            parent->setLeft(remove->getRight());
        }

        remove->setRight(NULL);
    }
    else //remove has a left child only, no right child (remove->getRight() is NULL)
    {
        //shuffle the pointers
        if(parent->getRight() == remove)
        {
            parent->setRight(remove->getLeft());
        }
        else
        {
            parent->setLeft(remove->getLeft());
        }

        remove->setLeft(NULL);

    }

}

void BinaryTree::deleteCaseTwoChild(BinarySearchNode* parent, BinarySearchNode* remove)
{
    //there are two children so we need nearest successor/predeccesor
    //swap and then delete 

    BinarySearchNode* predecessor = remove->getLeft();
    BinarySearchNode* predecessorParent;

    //read from left to right

    while(predecessor->getRight() != NULL)
    {
        predecessorParent = predecessor;
        predecessor = predecessor->getRight();
    }
    
    //variable predecessor becomes the predeccessor 

    string temporary = remove->getWord();
    remove->setWord(predecessor->getWord());
    predecessor->setWord(temporary);

    if((predecessor->getRight() != NULL) && (predecessor->getLeft() == NULL))
    {
        //case 0
        if(predecessorParent->getRight() == predecessor)
        {
            predecessorParent->setRight(NULL);
            delete predecessor;
        }
        else
        {
            //case 1 child, so call deleteCaseOneChild
            this->deleteCaseOneChild(predecessorParent, predecessor);
            delete predecessor;
        }
    }

}

*/