#include <iostream>
#include <string>

using namespace std;


class Car
{
	string name;
	string body;
	string engine;
	string wheels;
	string kpp;
public:
	void SetName(string name)
	{
		this->name = name;
	}
	string GetName()
	{
		return this->name;
	}
	void SetBody(string body)
	{
		this->body = body;
	}
	string GetBody()
	{
		return this->body;
	}
	void SetEngine(string engine)
	{
		this->engine = engine;
	}
	string GetEngine()
	{
		return this->engine;
	}
	void SetWheels(string wheels)
	{
		this->wheels = wheels;
	}
	string GetWheels()
	{
		return this->wheels;
	}
	void SetKPP(string kpp)
	{
		this->kpp = kpp;
	}
	string GetKPP()
	{
		return this->kpp;
	}
	void ShowCar()
	{
		cout << "Car " + name + ":\nBody: " + body + "\nEngine: " + engine + "\nWheels: " + wheels + "\nKPP: " + kpp << endl;
		cout << "--------------------" << endl << endl;
	}
};

class CarBuilder abstract
{
protected:
	Car car;
public:
	Car GetCar()
	{
		return car;
	}
	virtual void BuildName() abstract;
	virtual void BuildBody() abstract;
	virtual void BuildEngine() abstract;
	virtual void BuildWheels() abstract;
	virtual void BuildKPP() abstract;
};


class DaewooLanosCarBuilder : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("Daewoo Lanos");
	}
	void BuildBody() override
	{
		car.SetBody("Седан");
	}
	void BuildEngine() override
	{
		car.SetEngine("98 л.с");
	}
	void BuildWheels() override
	{
		car.SetWheels("13 r");
	}
	void BuildKPP() override
	{
		car.SetKPP("5 Manual");
	}
};
class FordProbeCarBuilder : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("Ford Probe");
	}
	void BuildBody() override
	{
		car.SetBody("Купе");
	}
	void BuildEngine() override
	{
		car.SetEngine("160 л.с");
	}
	void BuildWheels() override
	{
		car.SetWheels("14 r");
	}
	void BuildKPP() override
	{
		car.SetKPP("4 Auto");
	}
};
class UAZPatriotCarBuilder : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("UAZ Patriot");
	}
	void BuildBody() override
	{
		car.SetBody("Универсал");
	}
	void BuildEngine() override
	{
		car.SetEngine("120 л.с");
	}
	void BuildWheels() override
	{
		car.SetWheels("16 r");
	}
	void BuildKPP() override
	{
		car.SetKPP("4 Manual");
	}
};
class HyundaiGetzCarBuilder : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("Hyundai Getz");
	}
	void BuildBody() override
	{
		car.SetBody("Хетчбэк");
	}
	void BuildEngine() override
	{
		car.SetEngine("66 л.с");
	}
	void BuildWheels() override
	{
		car.SetWheels("13 r");
	}
	void BuildKPP() override
	{
		car.SetKPP("4 auto");
	}
};

class Shop
{
	CarBuilder* carBuilder;
public:
	void SetCarBuilder(CarBuilder* cb)
	{
		carBuilder = cb;
	}
	Car GetCar()
	{
		return carBuilder->GetCar();
	}
	void ConstructCar()
	{
		carBuilder->BuildName();
		carBuilder->BuildBody();
		carBuilder->BuildEngine();
		carBuilder->BuildWheels();
		carBuilder->BuildKPP();
	}
};

void client(CarBuilder* builder)
{
	Shop shop;
	shop.SetCarBuilder(builder);
	shop.ConstructCar();
	Car car = shop.GetCar();
	car.ShowCar();
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	CarBuilder* builder = new DaewooLanosCarBuilder();
	client(builder);
	delete builder;

	builder = new FordProbeCarBuilder();
	client(builder);
	delete builder;

	builder = new UAZPatriotCarBuilder();
	client(builder);
	delete builder;

	builder = new HyundaiGetzCarBuilder();
	client(builder);
	delete builder;

	system("pause");
}