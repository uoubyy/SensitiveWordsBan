//
//  WordFilter.h
//  CodeSample
//
//  Created by baoyanyi on 2019/11/16.
//  Copyright © 2019 baoyanyi. All rights reserved.
//

#ifndef WordFilter_h
#define WordFilter_h

#include "WordTree.h"

class WordFilter
{
public:
    WordFilter();
    ~WordFilter();
    
    void Load(const string &path);
    
    void Censor(string &source);
private:
    WordTree m_tree;
};

#endif /* WordFilter_h */
