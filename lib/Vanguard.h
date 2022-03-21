//
// Created by Jon Stephens on 3/19/22.
//

#ifndef VANGUARD_VANGUARD_H
#define VANGUARD_VANGUARD_H
#include "Analysis.h"

#include <unordered_set>

namespace vanguard {
    class Vanguard {
    protected:
        Analysis *analysis;

        bool runToFixedpoint(const Function &fn);
        vector<const BasicBlock *> *reachableBlks(const BasicBlock &blk, unordered_set<const BasicBlock *> *exclude);
        virtual void registerAnalysis(Analysis *a);
    };
}
#endif //VANGUARD_VANGUARD_H
