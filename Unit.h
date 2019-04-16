#pragma once
#include <string>
using namespace std;

namespace ariel

{
    // class Unit{
    //   public:
    //     enum Type {KM,CM,M,SEC,MIN,HOUR,G,KG,TON};
    //     Type type=KM;
    //     bool isSame(const Unit &otherUnit) const;
    //     bool isSameGroup(const Unit &otherUnit) const;
    //     string unitToString();
         
    // }; 
   enum class Unit{ KM,CM,M,SEC,MIN,HOUR,G,KG,TON};
}