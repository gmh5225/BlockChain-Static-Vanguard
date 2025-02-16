//
// Created by Jon Stephens on 3/30/22.
//

#include "TransferSink.h"
#include "../../MemoryVal.h"
#include "llvm/Analysis/MemoryLocation.h"

using namespace vanguard;
using namespace llvm;
using namespace std;

namespace flashloan {
    bool TransferSink::isSink(const llvm::Function &fn) const {
        if(!fn.hasName()) {
            return false;
        }

        std::string fnName = fn.getName().str();
        return fnName == "call";
    }

    vector<pair<FunctionLocation, Val *>> TransferSink::sinkValues(const llvm::Function &fn) const {
        // TODO: taint analysis does not take ownership of these values, they should be deleted here.
        string fnname = fn.getName().str();
        vector<pair<FunctionLocation, Val *>> vals;
        if(fn.arg_size() < 3) {
            return vals;
        }

        Value *valueArg = fn.getArg(2);
        //return Val::functionOutputs(fn);
        if(valueArg->getType()->isPointerTy()) {
            vals.emplace_back(INPUT, new MemoryVal(MemoryLocation::getBeforeOrAfter(valueArg)));
        }

        return vals;

        /*Value *arg = fn.getArg(2);
        //return Val::functionOutputs(fn);
        auto valArg = pair<FunctionLocation, Val *>(INPUT, new RegisterVal(*arg));
        return {valArg};*/
    }
}