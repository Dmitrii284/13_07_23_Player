#include<memory>

class Player
{
private:
	int _hp{ 0 }; // Здоровье
	int _damage{ 0 };// Урон
public:
	Player(int hp = 0, int damage = 0) : _hp{ hp }, _damage{ damage } { }

	void TakeDamage(int damage = 0) // Наносит урон Player
	{
		_hp -= damage; // Урон здоровью
	}

};

// Противник
class Enemy
{

protected:
	virtual void AtackType(std::shared_ptr<Player>& player) = 0;// virtual реализуется (В обязательном порядке) в каждом классе наследнике (По своему )
	int hp_{ 0 }; // Здоровье
	int damage_{ 0 };// Урон

public:
	Enemy(int hp = 0, int damage = 0 ) : hp_{hp}, damage_{damage}{ }

};

//Крыса
class Rat : public Enemy
{
	// player->TakeDamage если к player Обратиться мерез точку
	// Если мы хотим использоваь методы объекта на который указывает (который храниться) в shared_ptr то используем оператор ->
	// Если мы хотисм использовать встроенные методы shared_ptr то обращаемся к ним через оператор . 
	Rat(int hp = 0, int damage = 0) : Enemy(hp, damage) {}

	void AtackType(std::shared_ptr<Player>& player) override
	{
		player->TakeDamage(damage_ * 2);
	}
};

void Fight()
{
	std::shared_ptr<Rat> enemy = std::make_shared<Rat>();
	std::shared_ptr<Player> player = std::make_shared<Player>();
}