#pragma once
#include "Unit.h"
#include <stdexcept>
using namespace ariel;
// public:
   bool Unit::isSame(const Unit &unit) const{
     if (this->type==unit.type)

return true;
return false;
}

bool Unit::isSameGroup(const Unit &otherUnit) const
{
    Unit::Type temp = otherUnit.type;
            if (temp==Unit::CM || temp==Unit::KM || temp==Unit::M)
            {
                if (type==Unit::CM || type==Unit::KM || type ==Unit::M) 
                return true;
            }
            else if (temp==Unit::TON || temp==Unit::G || temp == Unit::KG)
            {
                if (type==Unit::TON || type==Unit::G || type ==Unit::KG) 
                return true;
            }
            else if (temp==Unit::SEC || temp ==Unit::MIN || temp==Unit::HOUR)
            {
                if (type==Unit::SEC || type==Unit::MIN || type ==Unit::HOUR) 
                return true;
            }
            return false;
}
        string Unit::unitToString(){
             switch (this->type){
                case Unit::KM: return "[km]";
                case Unit::CM: return  "[cm]";
                case Unit::M: return "[m]";
                case Unit::SEC: return  "[sec]";
                case Unit::MIN: return "[min]";
                case Unit::HOUR: return "[hour]";
                case Unit::G: return "[g]";
                case Unit::KG: return "[kg]";
                case Unit::TON: return "[ton]";
            }
        }


