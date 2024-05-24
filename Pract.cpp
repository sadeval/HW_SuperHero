#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Базовый абстрактный класс Способность
class Ability {
public:
    virtual ~Ability() {}
    virtual string GetName() const = 0;
};

// Конкретные способности
class Flight : public Ability {
public:
    string GetName() const override { return "Flight"; }
};

class SuperStrength : public Ability {
public:
    string GetName() const override { return "Super Strength"; }
};

class SuperSpeed : public Ability {
public:
    string GetName() const override { return "Super Speed"; }
};

// Определение персонажей
class Alignment {
public:
    virtual ~Alignment() {};
    virtual string GetAlignment() const = 0;
};

class Good : public Alignment {
public:
    string GetAlignment() const override { return "Good"; }
};

class Bad : public Alignment {
public:
    string GetAlignment() const override { return "Bad"; }
};

// Раса персонажей
class Race {
public:
    virtual ~Race() {};
    virtual string GetRace() const = 0;
};

class Human : public Race {
public:
    string GetRace() const override { return "Human"; }
};

class Animal : public Race {
public:
    string GetRace() const override { return "Animal"; }
};

class Deity : public Race {
public:
    string GetRace() const override { return "Deity"; }
};

// Базовый класс Супергерой
class Superhero {
protected:
    string name;
    Race* race;
    Alignment* alignment;
    vector<Ability*> abilities;

public:
    Superhero() {
        SetRace(nullptr);
        SetAlignment(nullptr);
    }

    virtual ~Superhero() {
        for (Ability* ability : abilities) {
            delete ability;
        }
        delete race;
        delete alignment;
    }

    void SetName(const string& name) {
        this->name = name;
    }

    void SetRace(Race* race) {
        if (this->race) delete this->race;
        this->race = race;
    }

    void SetAlignment(Alignment* alignment) {
        if (this->alignment) delete this->alignment;
        this->alignment = alignment;
    }

    void AddAbility(Ability* ability) {
        abilities.push_back(ability);
    }

    string GetName() const {
        return name;
    }

    string GetRace() const {
        return race->GetRace();
    }

    string GetAlignment() const {
        return alignment->GetAlignment();
    }

    vector<Ability*> GetAbilities() const {
        return abilities;
    }

    virtual void Display() const = 0;
};

// Конкретные супергерои
class Wolverine : public Superhero {
public:
    Wolverine() {
        SetName("Wolverine");
        SetRace(new Human());
        SetAlignment(new Good());
        AddAbility(new SuperStrength());
    }

    void Display() const override {
        cout << "Superhero: " << name << ", Race: " << GetRace() << ", Alignment: " << GetAlignment() << "\n";
    }
};

class IronMan : public Superhero {
public:
    IronMan() {
        SetName("Iron Man");
        SetRace(new Human());
        SetAlignment(new Good());
        AddAbility(new Flight());
    }

    void Display() const override {
        cout << "Superhero: " << name << ", Race: " << GetRace() << ", Alignment: " << GetAlignment() << "\n";
    }
};

class Thor : public Superhero {
public:
    Thor() {
        SetName("Thor");
        SetRace(new Deity());
        SetAlignment(new Good());
        AddAbility(new Flight());
        AddAbility(new SuperStrength());
    }

    void Display() const override {
        cout << "Superhero: " << name << ", Race: " << GetRace() << ", Alignment: " << GetAlignment() << "\n";
    }
};

class Hulk : public Superhero {
public:
    Hulk() {
        SetName("Hulk");
        SetRace(new Human());
        SetAlignment(new Good());
        AddAbility(new SuperStrength());
    }

    void Display() const override {
        cout << "Superhero: " << name << ", Race: " << GetRace() << ", Alignment: " << GetAlignment() << "\n";
    }
};

class CaptainAmerica : public Superhero {
public:
    CaptainAmerica() {
        SetName("Captain America");
        SetRace(new Human());
        SetAlignment(new Good());
        AddAbility(new SuperStrength());
    }

    void Display() const override {
        cout << "Superhero: " << name << ", Race: " << GetRace() << ", Alignment: " << GetAlignment() << "\n";
    }
};

class Groot : public Superhero {
public:
    Groot() {
        SetName("Groot");
        SetRace(new Deity());
        SetAlignment(new Good());
        AddAbility(new SuperStrength());
    }

    void Display() const override {
        cout << "Superhero: " << name << ", Race: " << GetRace() << ", Alignment: " << GetAlignment() << "\n";
    }
};

class Mystique : public Superhero {
public:
    Mystique() {
        SetName("Mystique");
        SetRace(new Human());
        SetAlignment(new Bad());
        AddAbility(new SuperSpeed());
    }

    void Display() const override {
        cout << "Superhero: " << name << ", Race: " << GetRace() << ", Alignment: " << GetAlignment() << "\n";
    }
};

// Класс для управления супергероями
class SuperheroManager {
private:
    vector<Superhero*> superheroes;

public:
    ~SuperheroManager() {
        for (Superhero* hero : superheroes) {
            delete hero;
        }
    }

    void AddSuperhero(Superhero* hero) {
        superheroes.push_back(hero);
    }

    void DisplayAll() const {
        cout << "All Superheroes:\n";
        for (const Superhero* hero : superheroes) {
            hero->Display();
        }
    }

    void DisplayFlyers() const {
        cout << "\nSuperheroes who can fly:\n";
        for (const Superhero* hero : superheroes) {
            for (const Ability* ability : hero->GetAbilities()) {
                if (ability->GetName() == "Flight") {
                    hero->Display();
                    break;
                }
            }
        }
    }
};

int main() {

    SuperheroManager manager;

    // Создание супергероев
    manager.AddSuperhero(new Wolverine());
    manager.AddSuperhero(new IronMan());
    manager.AddSuperhero(new Thor());
    manager.AddSuperhero(new Hulk());
    manager.AddSuperhero(new CaptainAmerica());
    manager.AddSuperhero(new Groot());
    manager.AddSuperhero(new Mystique());

    // Показ всех супергероев
    manager.DisplayAll();

    // Показ супергероев, которые умеют летать
    manager.DisplayFlyers();

}

