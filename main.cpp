//
//  main.cpp
//  CodeSample
//
//  Created by baoyanyi on 2019/11/16.
//  Copyright © 2019 baoyanyi. All rights reserved.
//

#include <iostream>
#include "WordFilter.h"

int main(int argc, const char * argv[]) {
    
    WordFilter* m_filter = new WordFilter();
    m_filter->Load("censor.txt");
    
    string source = "fuck your mother, fuuuuck, big dick, holy shit sht shiit, falungong falundafafafafa";
    cout<<"original => "<<source<<endl;
    m_filter->Censor(source);
    cout<<"result => "<<source<<endl;
    
    delete m_filter;
    return 0;
}
