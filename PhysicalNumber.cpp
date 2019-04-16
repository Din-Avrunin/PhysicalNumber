#include "PhysicalNumber.h"
#include "Unit.h"
#include <string>
#include <stdbool.h>
#include <stdexcept>
using namespace std;
using namespace ariel;

        
bool PhysicalNumber::isSame( Unit const & unit2) const{
    if (this->unit==unit2)
        return true;
    return false;
}

bool PhysicalNumber::isSameGroup(const Unit &otherUnit) const
{
    Unit temp = otherUnit;
            if (temp==Unit::CM || temp==Unit::KM || temp==Unit::M)
            {
                if (unit==Unit::CM || unit==Unit::KM || unit ==Unit::M) 
                return true;
            }
            else if (temp==Unit::TON || temp==Unit::G || temp == Unit::KG)
            {
                if (unit==Unit::TON || unit==Unit::G || unit ==Unit::KG) 
                return true;
            }
            else if (temp==Unit::SEC || temp ==Unit::MIN || temp==Unit::HOUR)
            {
                if (unit==Unit::SEC || unit==Unit::MIN || unit ==Unit::HOUR) 
                return true;
            }
            return false;
}
        string PhysicalNumber::unitToString() const{
             switch (this->unit){
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

        PhysicalNumber::PhysicalNumber()
        {
            number = 0;
            unit = Unit::KM;
        }
        PhysicalNumber::PhysicalNumber(double number,Unit unit) // unit is object of Unit.h class
        {

            this->number=number;
            this->unit=unit;
            
        }
        PhysicalNumber::~PhysicalNumber(){

        }
        PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& pn)
        {
          
          PhysicalNumber newPN; 
          
            if(this->isSame(pn.unit)){
                 
            newPN.number=this->number+pn.number;
            newPN.unit=this->unit;
            }
            else if(this->isSameGroup(pn.unit)) 
            {
            
                newPN=convert(pn);
                newPN.number+=number;
            }
            else
            {
                string type1= this->unitToString();
                PhysicalNumber pnUnit=pn;
                string type2=pnUnit.unitToString();
                throw invalid_argument ("Units do not match - "+type1+" cannot be converted to "+type2);

            }
            
            return newPN; // are we missing a delete once this is over?
        }


        PhysicalNumber& PhysicalNumber::operator+=(PhysicalNumber const & pn)
        {
            PhysicalNumber newPN;
           if (this->isSame(pn.unit))
           {
               number+=pn.number;
           }
           else if (this->isSameGroup(pn.unit))
           {
               newPN=convert(pn);
               number+=newPN.number;
           }
           else
           {
               throw "units are not the same dimensions in += function";
           }
           // delete (newPN) ????
           return *this;
        }   

        PhysicalNumber& PhysicalNumber::operator++()
        {
            number++;
            return *this;
        }
        const PhysicalNumber PhysicalNumber::operator++(int) 
        {
            PhysicalNumber q;
            q.number=this->number+1;
            q.unit=unit;
           
            return q;
        }
        PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& pn) const
        {
            PhysicalNumber newPN; 
            PhysicalNumber temp;
            if(this->isSame(pn.unit)){
            newPN.number=this->number-pn.number;
            newPN.unit=this->unit;
            }
            else if(this->isSameGroup(pn.unit)) 
            {
                temp=convert(pn);
                newPN.number=number-temp.number;
                newPN.unit=unit;
            }
            else
                throw "units are not the same dimensions in - function";
            
            return newPN; 
        }
        PhysicalNumber PhysicalNumber::operator+() const
        {
            return *this;
        }    
        PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& pn) 
        {
              PhysicalNumber newPN;
           if (this->isSame(pn.unit))
           {
               number-=pn.number;
           }
           else if (this->isSameGroup(pn.unit))
           {
               newPN=convert(pn);
               number-=newPN.number;
           }
           else
           {
               throw "units are not the same dimensions in -= function";
           }
           return *this;
        }
        PhysicalNumber PhysicalNumber::operator-() const
        {
            PhysicalNumber a;
            
            a.number=number*(-1);
            a.unit=unit;

           
            return a;

        }
        PhysicalNumber& PhysicalNumber::operator--()
        {
            number--;
            return *this;
        }
        const PhysicalNumber PhysicalNumber::operator--(int)
        {
            PhysicalNumber q;
            q.number=this->number-1;
            q.unit=this->unit;
            
            return q;
        }
        
        bool PhysicalNumber::operator<(const PhysicalNumber& pn) const
        {
            
            bool test=false;
            if(this->isSame(pn.unit))
            {
                if(this->number<pn.number)
                    return true;
                else
                    return false;
            }
            else if (this->isSameGroup(pn.unit))
                return number<convert(pn).number? true : false ; // need to delete?
            else 
                throw "the physical numbers are not the same dimension at function < \n";
        }
        bool  PhysicalNumber::operator>(const PhysicalNumber& pn) const
        {
              bool test=false;
            if(this->isSame(pn.unit))
            {
                if(this->number>pn.number)
                    return true;
                else
                    return false;
            }
            else if (this->isSameGroup(pn.unit))
                return number>convert(pn).number? true : false ; // need to delete?
            else 
                throw "the physical numbers are not the same dimension at function < \n";
        }   
        bool  PhysicalNumber::operator<=(const PhysicalNumber& pn) const
        {
             bool test=false;
            if(this->isSame(pn.unit))
            {
                if(this->number<=pn.number)
                    return true;
                else
                    return false;
            }
            else if (this->isSameGroup(pn.unit))
                return number<=convert(pn).number? true : false ; // need to delete?
            else 
                throw "the physical numbers are not the same dimension at function < \n";
        }
        bool  PhysicalNumber::operator>=(const PhysicalNumber& pn) const

        {
             bool test=false;
            if(this->isSame(pn.unit))
            {
                if(this->number>=pn.number)
                    return true;
                else
                    return false;
            }
            else if (this->isSameGroup(pn.unit))
                return number>=convert(pn).number? true : false ; // need to delete?
            else 
                throw "the physical numbers are not the same dimension at function < \n";
              
        }
        bool  PhysicalNumber::operator==(const PhysicalNumber& pn) const
        {
            bool test=false;
            if(this->isSame(pn.unit))
            {
                if(this->number==pn.number)
                    return true;
                else
                    return false;
            }
            else if (this->isSameGroup(pn.unit))
                return number==convert(pn).number? true : false ; // need to delete?
            else 
                throw "the physical numbers are not the same dimension at function < \n";
        }
        bool  PhysicalNumber::operator!=(const PhysicalNumber& pn) const
        {
                 bool test=false;
            if(this->isSame(pn.unit))
            {
                if(this->number!=pn.number)
                    return true;
                else
                    return false;
            }
            else if (this->isSameGroup(pn.unit))
                return number!=convert(pn).number? true : false ; // need to delete?
            else 
                throw "the physical numbers are not the same dimension at function < \n";
        }


   PhysicalNumber PhysicalNumber::convert(const PhysicalNumber &pn) const
    {
            // need to do isSame()?
        PhysicalNumber newPN;
        double pnNumber = pn.number;
        newPN.unit=unit;
        Unit temp = pn.unit;
        Unit type = unit;
        switch (type)
        {
            case Unit::SEC: if(temp == Unit::MIN) {newPN.number=pnNumber*60;} else if(temp==Unit::HOUR) {newPN.number=pnNumber*3600;} break;
            case Unit::MIN: if(temp == Unit::HOUR) {newPN.number=pnNumber*60;} else if(temp==Unit::SEC) {newPN.number=pnNumber/60;} break;
            case Unit::HOUR: if(temp == Unit::MIN) {newPN.number=pnNumber/60;} else if(temp==Unit::SEC) {newPN.number=pnNumber/3600;} break;

            case Unit::CM: if(temp == Unit::M) {newPN.number=pnNumber*100;} else if(temp==Unit::KM) {newPN.number=pnNumber*100000;} break;
            case Unit::M: if(temp == Unit::CM) {newPN.number=pnNumber/100;} else if(temp==Unit::KM) {newPN.number=pnNumber*1000;} break;
            case Unit::KM: if(temp == Unit::M) {newPN.number=pnNumber/1000;} else if(temp==Unit::CM) {newPN.number=pnNumber/100000;} break;

            case Unit::G: if(temp == Unit::KG) {newPN.number=pnNumber*1000;} else if(temp==Unit::TON) {newPN.number=pnNumber*100000;} break;
            case Unit::KG: if(temp == Unit::G) {newPN.number=pnNumber/1000;} else if(temp==Unit::TON) {newPN.number=pnNumber*1000;} break;
            case Unit::TON: if(temp == Unit::G) {newPN.number=pnNumber/100000;} else if(temp==Unit::KG) {newPN.number=pnNumber/1000;} break;

            default: throw "error in switch (at PhysicalNumber.cpp)";
        }
        return newPN;
    }
ostream& ariel::operator<<(ostream &os, const PhysicalNumber &pn){
    string sUnit=pn.unitToString();
    return os << pn.number << sUnit;
}
  istream& ariel::operator >>(istream &is, PhysicalNumber& pn){
 
	    double number;
        string str;
     
        is>>str;
        string delimiterStart = "[";
        string token = str.substr(0, str.find(delimiterStart));
        number= stod(token);
        string delimiterEnd = "]";
        int count =str.find(delimiterEnd)-str.find(delimiterStart)-1;
        string t = str.substr(str.find(delimiterStart)+1,count);

        if (t=="cm") { pn.unit=Unit::CM ; pn.number=number;}
        if (t=="m") { pn.unit=Unit::M ; pn.number=number;}
        if (t=="km") { pn.unit=Unit::KM ; pn.number=number;}
        if (t=="g") { pn.unit=Unit::G ; pn.number=number;}
        if (t=="kg") { pn.unit=Unit::KG ; pn.number=number;}
        if (t=="ton") { pn.unit=Unit::TON ; pn.number=number;}
        if (t=="sec") { pn.unit=Unit::SEC ; pn.number=number;}
        if (t=="min") { pn.unit=Unit::MIN ; pn.number=number;}
        if (t=="hour") { pn.unit=Unit::HOUR ; pn.number=number;}
        cout << endl;
        return is;

        }

