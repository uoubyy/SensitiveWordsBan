//
//  WordTree.h
//  CodeSample
//
//  Created by baoyanyi on 2019/11/16.
//  Copyright © 2019 baoyanyi. All rights reserved.
//

#ifndef WordTree_h
#define WordTree_h

#include "WordNode.h"

class WordTree
{
public:
    WordTree();
    ~WordTree();
    
    WordNode* Insert(const string &keyword);
    WordNode* Find(const string &keyword, int &maxMatch);
    
private:
    WordNode* m_treeRoot;
    
    WordNode* Insert(WordNode* parent, const string &keyword);
    WordNode* CreateNewBranch(WordNode* parent, const string &keyword);
    WordNode* Find(WordNode* parent, const string &keyword, int &maxMatch);
};

#endif /* WordTree_h */
