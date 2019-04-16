
#include <iostream>
#include "Unit.h"

        
namespace ariel
{

    using namespace std;
        // ostream& operator <<(ostream &, PhysicalNumber const &);
    class PhysicalNumber
    {
        private:
        PhysicalNumber convert(const PhysicalNumber &pn) const;
        // string PhysicalNumber::getUnitName(enum ariel::Unit::Type type) const;

        public:
        
        //members (variables)
        double number; // the amount of the units
        Unit unit; // can be  seconds,minutes,hours,tons,m and so on...
        
        //constructor
        PhysicalNumber(double ,Unit::Type);
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
        /*
        friend bool operator<(const PhysicalNumber& PhysicalNumber);
        friend bool operator>(const PhysicalNumber& PhysicalNumber);
        friend bool operator<=(const PhysicalNumber& PhysicalNumber);
        friend bool operator>=(const PhysicalNumber& PhysicalNumber);
        friend bool operator==(const PhysicalNumber& PhysicalNumber);
        friend bool operator!=(const PhysicalNumber& PhysicalNumber);
        */

        // this function check if the unit family is the same (for example, km and m)
        //  istream& operator >>(istream &is ,PhysicalNumber &pn);
        };
        
        ostream& operator <<(ostream &os, PhysicalNumber const &pn);
        istream& operator >>(istream &is ,PhysicalNumber &pn);
}