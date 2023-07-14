#include<memory>

class Player
{
private:
	int _hp{ 0 }; // ��������
	int _damage{ 0 };// ����
public:
	Player(int hp = 0, int damage = 0) : _hp{ hp }, _damage{ damage } { }

	void TakeDamage(int damage = 0) // ������� ���� Player
	{
		_hp -= damage; // ���� ��������
	}

};

// ���������
class Enemy
{

protected:
	virtual void AtackType(std::shared_ptr<Player>& player) = 0;// virtual ����������� (� ������������ �������) � ������ ������ ���������� (�� ������ )
	int hp_{ 0 }; // ��������
	int damage_{ 0 };// ����

public:
	Enemy(int hp = 0, int damage = 0 ) : hp_{hp}, damage_{damage}{ }

};

//�����
class Rat : public Enemy
{
	// player->TakeDamage ���� � player ���������� ����� �����
	// ���� �� ����� ����������� ������ ������� �� ������� ��������� (������� ���������) � shared_ptr �� ���������� �������� ->
	// ���� �� ������ ������������ ���������� ������ shared_ptr �� ���������� � ��� ����� �������� . 
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