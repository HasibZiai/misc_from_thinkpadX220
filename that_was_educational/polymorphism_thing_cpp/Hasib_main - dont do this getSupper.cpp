#include <iostream>
#include <string>


/*******************************************************************************
**  AVOID THIS TYPE OF DESIGN
*******************************************************************************/

/*******************************************************************************
**  Kind of person as an attribute
*******************************************************************************/
class Person
{
public:
  enum class Kind { Unnkown,
                    Wife,
                    Son, 
					Student,
					Farmer  } _kind;

  Person( const std::string & name = "Mom", Kind kind = Kind::Unnkown )
    : _kind( kind ), _name( name )
  {}

  std::string getSupper() const
  {
    return _name + transport() + pay() + food();
  }

  std::string transport() const
  {
    if     ( _kind == Kind::Wife ) return " will drive the car, ";
    else if( _kind == Kind::Son  ) return " will ride a bicycle, ";
	else if( _kind == Kind::Student ) return " will ride a skateboard, ";
	else if (_kind == Kind::Farmer) return " will ride a tractor, ";
    return "Ooops, an unknown kind of person was trying to get to the store";
  }

  std::string pay() const
  {
    if     ( _kind == Kind::Wife ) return "pay by card, ";
    else if( _kind == Kind::Son  ) return "and pay by cash.";
	else if (_kind == Kind::Student ) return "and pay by Apple Pay, ";
	else if (_kind == Kind::Farmer) return "and pay by haybale, ";
    return "Ooops, an unknown kind of person was trying to pay my bill";
  }

  std::string food() const
  {
    if     ( _kind == Kind::Wife ) return "and buy Chicken Cordon Bleu with Chardonnay.";
    else if( _kind == Kind::Son  ) return "buy pizza, ";
	else if (_kind == Kind::Student) return "and buys ramen.";
	else if (_kind == Kind::Farmer) return "and doesn't buy anything cause they're a farmer and have plenty of crops!";
    return "Ooops, an unknown kind of person was trying to buy food!";
  }

  ~Person();

private:
  std::string _name;
};
inline Person::~Person() {}




/*******************************************************************************
**  Code to the Interface
*******************************************************************************/
std::string doSomething( const Person & person )
{
  return person.getSupper();
}




/*******************************************************************************
**  Create concrete objects and process those object polymorphicly
*******************************************************************************/
int main()
{
  Person mom( "mom", Person::Kind::Wife  );
  Person son( "Bobby", Person::Kind::Son );
  Person student("Rojelio", Person::Kind::Student);
  Person farmer("Steve", Person::Kind::Farmer);

  std::cout << doSomething( son ) << '\n';
  std::cout << doSomething( mom ) << '\n';
  std::cout << doSomething( student ) << '\n';
  std::cout << doSomething(farmer) << '\n';
}