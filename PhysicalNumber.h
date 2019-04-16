
#include <iostream>
#include "Unit.h"

        
namespace ariel
{

    using namespace std;

    class PhysicalNumber
    {
        private:
        PhysicalNumber convert(const PhysicalNumber &pn) const;
        bool isSame(Unit const & unit ) const;        // this function check if the unit is the equal

        bool isSameGroup(const Unit &otherUnit) const;      // this function check if the unit family is the same (for example, km and m)


        public:
        string unitToString() const;

        //members (variables)
        double number; // the amount of the units
        Unit unit; // can be  seconds,minutes,hours,tons,m and so on...
        
        //constructor
        PhysicalNumber(double ,Unit);
        PhysicalNumber();
        ~PhysicalNumber();

        PhysicalNumber operator+( PhysicalNumber const & pn);
        PhysicalNumber& operator+=(const PhysicalNumber &pn);
        const PhysicalNumber operator++(int);
        PhysicalNumber& operator++();
        
        PhysicalNumber operator-(const PhysicalNumber &pn) const;
        PhysicalNumber& operator-=(const PhysicalNumber &pn);
        PhysicalNumber operator-() const;
        const PhysicalNumber operator--(int);
        PhysicalNumber& operator--();
        
    
        bool operator<(const PhysicalNumber& PhysicalNumber) const;
        bool operator>(const PhysicalNumber& PhysicalNumber) const;
        bool operator<=(const PhysicalNumber& PhysicalNumber) const;
        bool operator>=(const PhysicalNumber& PhysicalNumber) const;
        bool operator==(const PhysicalNumber& PhysicalNumber) const;
        bool operator!=(const PhysicalNumber& PhysicalNumber) const;

        };
        
        ostream& operator <<(ostream &os, PhysicalNumber const &pn);
        istream& operator >>(istream &is ,PhysicalNumber &pn);
}