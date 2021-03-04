#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
	void virtual make_sound() = 0
	{
		cout << "No sound\n";
	}
	//virtual ~Animal() = 0;
};

class Fish : public Animal
{
public:
	void make_sound() override
	{
		Animal::make_sound();
	}
};

class Dog : public Animal
{
public:
	void make_sound() override final
	{
		cout << "Barking!\n";
	}
};

//class Labrador : public Dog
//{
//public:
//	void make_sound() override // error: can't override final
//	{
//		cout << "Barking!\n";
//	}
//};

class AbstractDB
{
private:
	string connection;
public:
	AbstractDB(string conn)
	{
		connection = conn;
	}
	void virtual SELECT() = 0;
	void virtual INSERT() = 0;
	void virtual UPDATE() = 0;
	void virtual DELETE() = 0;
};

class MySql : public AbstractDB
{
public:
	MySql(string conn) : AbstractDB(conn) {}
	void virtual SELECT() override
	{
		cout << "MySQL SELECT\n";
	}
	void virtual INSERT() override
	{
		cout << "MySQL INSERT\n";
	}
	void virtual UPDATE() override
	{
		cout << "MySQL UPDATE\n";
	}
	void virtual DELETE() override
	{
		cout << "MySQL DELETE\n";
	}
};

class MSSql : public AbstractDB
{
public:
	MSSql(string conn) : AbstractDB(conn) {}
	void virtual SELECT() override
	{
		cout << "MSSql SELECT\n";
	}
	void virtual INSERT() override
	{
		cout << "MSSql INSERT\n";
	}
	void virtual UPDATE() override
	{
		cout << "MSSql UPDATE\n";
	}
	void virtual DELETE() override
	{
		cout << "MSSql DELETE\n";
	}
};

class Oracle : public AbstractDB
{
public:
	Oracle(string conn) : AbstractDB(conn) {}
	void virtual SELECT() override
	{
		cout << "Oracle SELECT\n";
	}
	void virtual INSERT() override
	{
		cout << "Oracle INSERT\n";
	}
	void virtual UPDATE() override
	{
		cout << "Oracle UPDATE\n";
	}
	void virtual DELETE() override
	{
		cout << "Oracle DELETE\n";
	}
};

class PostgreSql : public AbstractDB
{
public:
	PostgreSql(string conn) : AbstractDB(conn) {}
	void virtual SELECT() override
	{
		cout << "PostgreSql SELECT\n";
	}
	void virtual INSERT() override
	{
		cout << "PostgreSql INSERT\n";
	}
	void virtual UPDATE() override
	{
		cout << "PostgreSql UPDATE\n";
	}
	void virtual DELETE() override
	{
		cout << "PostgreSql DELETE\n";
	}
};

static class DB_CRUD
{
public:
	static void SELECT(AbstractDB* db)
	{
		db->SELECT();
	}
	static void INSERT(AbstractDB* db)
	{
		db->INSERT();
	}
	static void UPDATE(AbstractDB* db)
	{
		db->UPDATE();
	}
	static void DELETE(AbstractDB* db)
	{
		db->DELETE();
	}
};

int main()
{
	AbstractDB* db = new PostgreSql("conn str");
	DB_CRUD::INSERT(db);
	DB_CRUD::UPDATE(db);

	AbstractDB* db2 = new MSSql("conn str");
	DB_CRUD::SELECT(db2);
	DB_CRUD::DELETE(db2);

	AbstractDB* db3 = new MySql("conn str");
	DB_CRUD::SELECT(db3);
	DB_CRUD::INSERT(db3);




	////Animal a;
	//Dog d;
	//d.make_sound();
	return 0;
}