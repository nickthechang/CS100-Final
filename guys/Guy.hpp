#ifndef GUY_HPP
#define GUY_HPP

#include "../Attacks/NeutralAttack.hpp"
#include "../Attacks/TypedAttack.hpp"
#include "../Attacks/Attack.hpp"
#include "../Factory/ElectricFactory.hpp"
#include "../Factory/FireFactory.hpp"
#include "../Factory/GrassFactory.hpp"
#include "../Factory/WaterFactory.hpp"

using namespace std;

class NeutralAttack;
class TypedAttack;
class MoveFactory;
class Attack;

class Guy {
  protected:
    MoveFactory* f;
    NeutralAttack* n;
    TypedAttack* a;
    Attack* atk;
    bool isAlive;
    double Health;
    string nickname;
    string typedAtkName;
    string neutralAtkName;

  public:
    Guy() {
      f = nullptr;
      n = nullptr;
      a = nullptr;
      atk = nullptr;
      Health = 200;
      isAlive = true;
    }
    void set_moves() {
      n = f -> createNeutralMove();
      a = f -> createTypedMove();
    }
    
    void attack(Guy* opponent) {
      atk -> atk(opponent);
    }
    void set_attack(Attack* atk) {
      this -> atk = atk;
    }
    void setHealth(double health) {
      this -> Health = health;
    }
    void setAlive(bool alive) {
      this -> isAlive = alive;
    }
    bool is_alive() {
      return isAlive;
    }
    TypedAttack* getTypedAttack()  {
      return a;
    }
    NeutralAttack* getNeutralAttack() {
      return n;
    }

    double getHealth() {
      return Health;
    }

    virtual string getWeakness() = 0;
    void set_nickname(string nickname) { this->nickname = nickname;  }
    string get_nickname() { return nickname; }
    string get_neutral_atk_name() { return neutralAtkName; }
    string get_typed_atk_name() {return typedAtkName; }
};



#endif
