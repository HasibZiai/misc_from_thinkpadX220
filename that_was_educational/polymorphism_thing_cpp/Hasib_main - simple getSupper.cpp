#include <iostream>
#include <string>



/*******************************************************************************
**  Interface  (Generalization)
*******************************************************************************/
class Person
{
  public:
    virtual std::string getSupper() const = 0;

    virtual std::string transport() const = 0;
    virtual std::string pay()       const = 0;
    virtual std::string food()      const = 0;

    virtual ~Person() = 0;
};
inline Person::~Person() {}


/*******************************************************************************
**  Concrete Class  (Specialization)
*******************************************************************************/
class Wife : public Person
{
  public:
    Wife( const std::string & name = "Mom" )
      : _name( name )
    {}

    std::string getSupper() const override
    { return _name + transport() + pay() + food(); }

    std::string transport() const override
    { return " will drive the car, "; }

    std::string pay() const override
    { return "pay by card, ";}

    std::string food() const override
    { return "and buy Chicken Cordon Bleu with Chardonnay."; }

    virtual ~Wife() {}

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
      : _nickName( name )
    {}

    std::string getSupper() const override
    { return _nickName + transport() + food() + pay(); }

    std::string transport() const override
    { return " will ride a bicycle, "; }

    std::string pay() const override
    { return "and pay by cash."; }

    std::string food() const override
    { return "buy pizza, "; }

    virtual ~TeenagedSon() {}

  private:
    std::string _nickName;
};

//Student Concrete Class
class CollegeStudent : public Person
{
public:
	CollegeStudent(const std::string & name = "Frank")
		: _nickName(name)
	{}

	std::string getSupper() const override
	{
		return _nickName + transport() + food() + pay();
	}

	std::string transport() const override
	{
		return " will ride a skateboard, ";
	}

	std::string pay() const override
	{
		return "and pay by Apple Pay.";
	}

	std::string food() const override
	{
		return "buy ramen, ";
	}

	virtual ~CollegeStudent() {}

private:
	std::string _nickName;
};

//Farmer Concrete Class
class Farmer : public Person
{
public:
	Farmer(const std::string & name = "Steve")
		: _nickName(name)
	{}

	std::string getSupper() const override
	{
		return _nickName + transport() + food() + pay();
	}

	std::string transport() const override
	{
		return " will ride a tractor, ";
	}

	std::string pay() const override
	{
		return "and pay by hay bale.";
	}

	std::string food() const override
	{
		return "buy carrots, ";
	}

	virtual ~Farmer() {}

private:
	std::string _nickName;
};

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
  CollegeStudent student;
  Farmer farmer;

  std::cout << doSomething(son) << '\n';
  std::cout << doSomething(mom) << '\n';
  std::cout << doSomething(student) << '\n';
  std::cout << doSomething(farmer) << '\n';
}