#include <iostream>
#include <string>
#include <vector>



/*******************************************************************************
**  Abstract Class  (Generalization)
*******************************************************************************/
class Person
{
  public:
    virtual std::string getSupper() const = 0;

    virtual std::string transport() const = 0;
    virtual std::string pay()       const = 0;
    virtual std::string food()      const = 0;

    static std::vector<Person *> & entirePopulation()
    { return people; }

    virtual ~Person() = 0;

  protected:
    // Enable derived classes to register themselves into a collection of people
    Person( Person * person )
    { people.push_back( person ); }
    
    inline static std::vector<Person *> people;
};
inline Person::~Person() {}


/*******************************************************************************
**  Concrete Class  (Specialization)
*******************************************************************************/
class Wife : public Person
{
  public:
    Wife( const std::string & name = "Mom" )
      : Person( this ), _name( name )
    {}

    std::string getSupper() const override
    { return _name + transport() + pay() + food(); }

    std::string transport() const override
    { return " will drive the car, "; }

    std::string pay() const override
    { return "pay by card, "; }

    std::string food() const override
    { return "and buy Chicken Cordon Bleu with Chardonnay."; }

    virtual ~Wife() 
    {}

  private:
    std::string _name;
};


/*******************************************************************************
**  Concrete Class  (Specialization)
*******************************************************************************/
class TeenagedSon : public Person
{
  public:
    TeenagedSon( const std::string & name = "Bobby" )
      : Person( this ), _nickName( name )
    {}

    std::string getSupper() const override
    { return _nickName + transport() + food() + pay(); }

    std::string transport() const override
    { return " will ride a bicycle, "; }

    std::string pay() const override
    { return "and pay by cash."; }

    std::string food() const override
    { return "buy pizza, "; }

    virtual ~TeenagedSon() 
    {}

  private:
    std::string _nickName;
};

/*******************************************************************************
**  Concrete Class  (Specialization)
*******************************************************************************/
class Student : public Person
{
public:
	Student(const std::string & name = "Frank")
		: Person(this), _name(name)
	{}

	std::string getSupper() const override
	{
		return _name + transport() + pay() + food();
	}

	std::string transport() const override
	{
		return " will ride their skateboard, ";
	}

	std::string pay() const override
	{
		return "pay by Apple Pay, ";
	}

	std::string food() const override
	{
		return "and buy ramen.";
	}

	virtual ~Student()
	{}

private:
	std::string _name;
};

/*******************************************************************************
**  Concrete Class  (Specialization)
*******************************************************************************/
class Farmer : public Person
{
public:
	Farmer(const std::string & name = "Steve")
		: Person(this), _name(name)
	{}

	std::string getSupper() const override
	{
		return _name + transport() + pay() + food();
	}

	std::string transport() const override
	{
		return " will drive by tractor, ";
	}

	std::string pay() const override
	{
		return "pay by haybale, ";
	}

	std::string food() const override
	{
		return "and buy carrots and other crops!";
	}

	virtual ~Farmer()
	{}

/*******************************************************************************
**  Code to the Interface
*******************************************************************************/
// Passing by reference (vice value) is imperative!!  Pass by reference either by reference (&) or by pointer (*)
std::string doSomething( const Person & person )
{ return person.getSupper(); }




/*******************************************************************************
**  Create concrete objects and process those object polymorphicly
*******************************************************************************/
int main()
{
  Wife        mom;
  TeenagedSon son;

  std::cout << doSomething(son) << '\n';
  std::cout << doSomething(mom) << "\n\n\n";


  for( auto person : Person::entirePopulation() ) std::cout << doSomething( *person ) << '\n';
}