//
// Created by omer on 15/01/2020.
//

#ifndef ADVPROG_MILESTONE2_SEARCHER_H
#define ADVPROG_MILESTONE2_SEARCHER_H

#include "Searchable.h"
#include <queue>
#include <vector>
#include "State.h"
#include "MyPQueue.h"
template <typename T,typename S>
class Searcher {
protected:
    int numOfDevNodes = 0;
    double totalCost = 0;
    string searcherName;
    MyPQueue<T> *PQueue = new MyPQueue<T>();
public:
    virtual S search(Searchable<T> *s) = 0;
    virtual string getSearcherName() {
        return this->searcherName;
    }
    virtual int getNumOfDevNodes() {
        return this->numOfDevNodes;
    }
    virtual double getTotalCost() {
        return this->totalCost;
    }
};


#endif //ADVPROG_MILESTONE2_SEARCHER_H
