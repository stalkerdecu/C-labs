#include <iostream>
#include <string>

class Character {
private:
    std::string name;  // Приватное поле: имя персонажа
    int health;        // Приватное поле: уровень здоровья
    int attack;        // Приватное поле: уровень атаки
    int defense;       // Приватное поле: уровень защиты

public:
    // Конструктор для инициализации данных
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {}

    // Метод для получения уровня здоровья
    int getHealth() const {
        return health;
    }

    // Метод для вывода информации о персонаже
    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }

    // Метод для атаки другого персонажа
    void attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.health -= damage;
            std::cout << name << " attacks " << enemy.name << " for " << damage << " damage!" << std::endl;
        }
        else {
            std::cout << name << " attacks " << enemy.name << ", but it has no effect!" << std::endl;
        }
    }

    // метод захила
    void heal(int amount) {
        int hp = health + amount;
        if (hp >= 100){
            hp = 100;
        }
        std::cout << name << "Found a bottle of regen. His health is: " << hp << std::endl;
        health = hp;
    }

    // метод получения урона
    void takeDamage(int amount) {
        int hp = health - amount;
        if (hp <= 0) {
            std::cout << name << " is dead" << std::endl;
        }
        else {
            std::cout << name << "Take damage. His health is: " << hp << std::endl;
        }
    }
};

int main() {
    // Создаем объекты персонажей
    Character hero("Hero", 15, 20, 10);
    Character monster("Goblin", 50, 15, 5);

    // Выводим информацию о персонажах
    hero.displayInfo();
    monster.displayInfo();

    // Герой атакует монстра
    hero.attackEnemy(monster);
    monster.displayInfo();

    hero.heal(50);

    hero.takeDamage(10);

    return 0;
}
