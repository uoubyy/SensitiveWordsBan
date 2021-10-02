//
//  WordTree.cpp
//  CodeSample
//
//  Created by baoyanyi on 2019/11/16.
//  Copyright © 2019 baoyanyi. All rights reserved.
//

#include "WordTree.h"

#include <iostream>
using namespace std;

WordTree::WordTree()
{
    m_treeRoot = new WordNode();
}

WordTree::~WordTree()
{
    delete m_treeRoot;
}

WordNode* WordTree::Insert(const string &keyword)
{
    return Insert(m_treeRoot, keyword);
}

WordNode* WordTree::Find(const string &keyword, int &maxMatch)
{
    return Find(m_treeRoot, keyword, maxMatch);
}

WordNode* WordTree::Insert(WordNode* parent, const string &keyword)
{
    WordNode* firstNode = parent->FindChild(keyword[0]);
    
    if(firstNode == nullptr || firstNode->GetChar() == '*')
    {
        return CreateNewBranch(parent, keyword);
    }
    
    if(keyword.size() > 1)
    {
        string subStr = keyword.substr(1);
        return Insert(firstNode, subStr);
    }
    
    return nullptr;
}

WordNode* WordTree::CreateNewBranch(WordNode* parent, const string &keyword)
{
    // cout<<"CreateNewBranch "<<keyword<<endl;
    WordNode* firstNode = parent->InsertChild(keyword[0]);
    
    if(firstNode != nullptr)
    {
         if(keyword.size() > 1)
         {
             string subStr = keyword.substr(1);
             return CreateNewBranch(firstNode, subStr);
         }
    }
    
    return nullptr;
}

WordNode* WordTree::Find(WordNode* parent, const string &keyword, int &maxMatch)
{
    WordNode* firstNode = parent->FindChild(keyword[0]);
    
    if(firstNode == nullptr)
        return nullptr;
    
    if(firstNode->GetChar() == '*')
        return firstNode;
    
    maxMatch++;
    
    if(keyword.size() > 1)
    {
        string subStr = keyword.substr(1);
        return Find(firstNode, subStr, maxMatch);
    }
    
    return nullptr;
}
