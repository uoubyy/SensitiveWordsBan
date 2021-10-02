//
//  WordNode.cpp
//  CodeSample
//
//  Created by baoyanyi on 2019/11/16.
//  Copyright © 2019 baoyanyi. All rights reserved.
//

#include "WordNode.h"

#include <iostream>

WordNode* WordNode::FindChild(const char nextChar)
{
    MapIterator it = m_map.find(nextChar);
    
    // TODO check Upper & Lower
    if(it != m_map.end())
        return it->second;
    
    it = m_map.find('*');
    if(it != m_map.end())
        return it->second;
    
    return nullptr;
}

WordNode* WordNode::InsertChild(char nextChar)
{
    // no need to check exist
    WordNode* newNode = new WordNode(nextChar);
    m_map.insert(pair<char, WordNode*>(nextChar, newNode));
    return newNode;
}

WordNode::~WordNode()
{
    for(MapIterator it = m_map.begin(); it != m_map.end(); it++)
    {
        // cout<<"Delete => "<<it->first<<endl;
        delete it->second;
    }
    m_map.clear();
}
