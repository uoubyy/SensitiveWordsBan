//
//  WordNode.h
//  CodeSample
//
//  Created by baoyanyi on 2019/11/16.
//  Copyright © 2019 baoyanyi. All rights reserved.
//

#ifndef WordNode_h
#define WordNode_h

#include <map>
#include <string>
using namespace std;

class WordNode
{
    typedef map<char, WordNode*> TreeMap;
    typedef map<char, WordNode*>::iterator MapIterator;
public:
    
    WordNode(){};
    WordNode(char character) :m_char(character){};
    char GetChar() const { return m_char;}
    
    WordNode* FindChild(const char nextChar);
    WordNode* InsertChild(char nextChar);
    
    ~WordNode();
    
private:
    char m_char;
    TreeMap m_map;
};

#endif /* WordNode_h */
