//
//  WordFilter.cpp
//  CodeSample
//
//  Created by baoyanyi on 2019/11/16.
//  Copyright © 2019 baoyanyi. All rights reserved.
//

#include "WordFilter.h"

#include <fstream>

#include <iostream>
using namespace std;

WordFilter::WordFilter()
{
    
}

WordFilter::~WordFilter()
{
    
}

void WordFilter::Load(const string &path)
{
    ifstream read_file;
    read_file.open(path, ios::binary);
    
    string key;
    while (getline(read_file, key))
    {
        //cout<<"getline "<<key<<endl;
        key = key + "*";
        m_tree.Insert(key);
    }
    
    read_file.close();
}

void WordFilter::Censor(string &source)
{
    int length = source.size();
    for(int index = 0; index < length; index++)
    {
        string subStr = source.substr(index);
        int maxMatch = 0;
        if(m_tree.Find(subStr, maxMatch) != nullptr)
        {
            source.replace(index, maxMatch, maxMatch, '*');
            index += maxMatch;
        }
    }
}
