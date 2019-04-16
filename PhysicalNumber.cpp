

#include "PhysicalNumber.h"
#include "Unit.cpp"
#include <string>
#include <stdbool.h>
#include <stdexcept>
using namespace std;
using namespace ariel;

        PhysicalNumber::PhysicalNumber()
        {
            
            number = 0;
            unit.type = Unit::KM;
        }
        PhysicalNumber::PhysicalNumber(double number,Unit::Type type) // unit is object of Unit.h class
        {
            if (number < 0) 
            throw "exception at constructor, number cant be < 0";
            this->number=number;
            this->unit.type=type;
            
        }
        PhysicalNumber::~PhysicalNumber(){

        }
        PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& pn) const
        {
          
          PhysicalNumber newPN; 
          
            if(unit.ariel::Unit::isSame(pn.unit)){
                 
            newPN.number=this->number+pn.number;
            newPN.unit=this->unit;
            }
            else if(unit.isSameGroup(pn.unit)) 
            {
            
                newPN=convert(pn);
                newPN.number+=number;
            }
            else
            {
                Unit thisUnit=this->unit;
                string type1= thisUnit.unitToString();
                Unit pnUnit=pn.unit;
                string type2=pnUnit.unitToString();
                throw invalid_argument ("Units do not match - "+type1+" cannot be converted to "+type2);

            }
            
            return newPN; // are we missing a delete once this is over?
        }

        PhysicalNumber& PhysicalNumber::operator+=(PhysicalNumber const & pn)
        {
            PhysicalNumber newPN;
           if (unit.isSame(pn.unit))
           {
               number+=pn.number;
           }
           else if (unit.isSameGroup(pn.unit))
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
        //TODO: need to complele code: and also, do i need & here?
        PhysicalNumber PhysicalNumber::operator+() const
        {
            return *this;
        }    

        PhysicalNumber& PhysicalNumber::operator++()
        {
            number++;
            return *this;
        }
        PhysicalNumber &PhysicalNumber::operator++(int) 
        {
           number++;
            return *this;
        }
        PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& pn) const
        {
            PhysicalNumber newPN; 
            PhysicalNumber temp;
            if(unit.ariel::Unit::isSame(pn.unit)){
            newPN.number=this->number-pn.number;
            newPN.unit=this->unit;
            }
            else if(unit.isSameGroup(pn.unit)) 
            {
                temp=convert(pn);
                newPN.number=number-temp.number;
                newPN.unit=unit;
            }
            else
                throw "units are not the same dimensions in - function";
            
            return newPN; 
        }
        PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& pn) 
        {
              PhysicalNumber newPN;
           if (unit.isSame(pn.unit))
           {
               number-=pn.number;
           }
           else if (unit.isSameGroup(pn.unit))
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
            this->number=this->number-1;
            return *this;
        }
        PhysicalNumber& PhysicalNumber::operator--(int)
        {
            number--;
            return *this;
        }
        
        bool PhysicalNumber::operator<(const PhysicalNumber& pn) const
        {
            
            bool test=false;
            if(unit.isSame(pn.unit))
            {
                if(this->number<pn.number)
                    return true;
                else
                    return false;
            }
            else if (unit.isSameGroup(pn.unit))
                return number<convert(pn).number? true : false ; // need to delete?
            else 
                throw "the physical numbers are not the same dimension at function < \n";
        }
        bool  PhysicalNumber::operator>(const PhysicalNumber& pn) const
        {
              bool test=false;
            if(unit.isSame(pn.unit))
            {
                if(this->number>pn.number)
                    return true;
                else
                    return false;
            }
            else if (unit.isSameGroup(pn.unit))
                return number>convert(pn).number? true : false ; // need to delete?
            else 
                throw "the physical numbers are not the same dimension at function < \n";
        }   
        bool  PhysicalNumber::operator<=(const PhysicalNumber& pn) const
        {
             bool test=false;
            if(unit.isSame(pn.unit))
            {
                if(this->number<=pn.number)
                    return true;
                else
                    return false;
            }
            else if (unit.isSameGroup(pn.unit))
                return number<=convert(pn).number? true : false ; // need to delete?
            else 
                throw "the physical numbers are not the same dimension at function < \n";
        }
        bool  PhysicalNumber::operator>=(const PhysicalNumber& pn) const

        {
             bool test=false;
            if(unit.isSame(pn.unit))
            {
                if(this->number>=pn.number)
                    return true;
                else
                    return false;
            }
            else if (unit.isSameGroup(pn.unit))
                return number>=convert(pn).number? true : false ; // need to delete?
            else 
                throw "the physical numbers are not the same dimension at function < \n";
              
        }
        bool  PhysicalNumber::operator==(const PhysicalNumber& pn) const
        {
            bool test=false;
            if(unit.isSame(pn.unit))
            {
                if(this->number==pn.number)
                    return true;
                else
                    return false;
            }
            else if (unit.isSameGroup(pn.unit))
                return number==convert(pn).number? true : false ; // need to delete?
            else 
                throw "the physical numbers are not the same dimension at function < \n";
        }
        bool  PhysicalNumber::operator!=(const PhysicalNumber& pn) const
        {
                 bool test=false;
            if(unit.isSame(pn.unit))
            {
                if(this->number!=pn.number)
                    return true;
                else
                    return false;
            }
            else if (unit.isSameGroup(pn.unit))
                return number!=convert(pn).number? true : false ; // need to delete?
            else 
                throw "the physical numbers are not the same dimension at function < \n";
        }
m

   PhysicalNumber PhysicalNumber::convert(const PhysicalNumber &pn) const
    {
            // need to do isSame()?
        PhysicalNumber newPN;
        double pnNumber = pn.number;
        newPN.unit=unit;
        Unit::Type temp = pn.unit.type;
        Unit::Type type = unit.type;
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
            switch (pn.unit.type){
                case Unit::KM: return os << pn.number << "[km]";
                case Unit::CM: return os << pn.number << "[cm]";
                case Unit::M: return os << pn.number << "[m]";
                case Unit::SEC: return os << pn.number << "[sec]";
                case Unit::MIN: return os << pn.number << "[min]";
                case Unit::HOUR: return os << pn.number << "[hour]";
                case Unit::G: return os << pn.number << "[g]";
                case Unit::KG: return os << pn.number << "[kg]";
                case Unit::TON: return os << pn.number << "[ton]";
            }
        }
  istream& ariel::operator >>(istream &is, PhysicalNumber& pn){
 
	    double number;
        string str;
     
        is>>str;
        //  cout << endl;
        //   cout << str;
        //   cout << endl;
        string delimiterStart = "[";
        string token = str.substr(0, str.find(delimiterStart));
            // cout << str.find("[");
            //  cout << "testestestestestsetestestestesatasertkasdoptkasdpotkaesptkaseopktpoaskdotaskpodrtkasopdktopask\n";
            //  cout << "this is token " <<token << endl;
        number= stod(token);
            //  cout << "testestestestestsetestestestesatasertkasdoptkasdpotkaesptkaseopktpoaskdotaskpodrtkasopdktopask";
        string delimiterEnd = "]";
            //  cout << "testestestestestsetestestestesatasertkasdoptkasdpotkaesptkaseopktpoaskdotaskpodrtkasopdktopask";
        //cout<<str.find(delimiterEnd)-1;
        int count =str.find(delimiterEnd)-str.find(delimiterStart)-1;

        string t = str.substr(str.find(delimiterStart)+1,count);

        // cout << "this is t " <<t;
        if (t=="cm") { pn.unit.type=Unit::CM ; pn.number=number;}
        if (t=="m") { pn.unit.type=Unit::M ; pn.number=number;}
        if (t=="km") { pn.unit.type=Unit::KM ; pn.number=number;}
        if (t=="g") { pn.unit.type=Unit::G ; pn.number=number;}
        if (t=="kg") { pn.unit.type=Unit::KG ; pn.number=number;}
        if (t=="ton") { pn.unit.type=Unit::TON ; pn.number=number;}
        if (t=="sec") { pn.unit.type=Unit::SEC ; pn.number=number;}
        if (t=="min") { pn.unit.type=Unit::MIN ; pn.number=number;}
        if (t=="hour") { pn.unit.type=Unit::HOUR ; pn.number=number;}
        cout << endl;
        return is;

        }

