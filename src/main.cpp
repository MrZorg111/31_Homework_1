#include <iostream>
#include <string>
#include <memory>


class Toy {
    std::string name_toy;
public:
    Toy (std::string _name_toy) : name_toy(_name_toy){};
    Toy(){};

    std::string getNameToy() {
        return name_toy;
    }
    ~Toy() {
       std::cout << "The toy " << name_toy<< " is removed. " << std::endl;
   } 
};

class Dog {
    std::shared_ptr<Toy> toy_dog;
public:
    void getToy(std::shared_ptr<Toy> _toy) {
        if (toy_dog != _toy && (_toy.use_count() - 1) == 1) {
            if(toy_dog != nullptr) {
                std::cout <<"The dog dropped the toy: " << toy_dog->getNameToy() << std::endl;
                toy_dog.reset();
            }
            std::cout << "The dog picked up the toy: " << _toy->getNameToy() << std::endl;
            toy_dog = _toy;
        }
        else {
            std::cout << "Another dog is playing with this toy." << std::endl;
        }
    }
    void dropToy() {
        if (toy_dog != nullptr) {
            std::cout <<"The dog dropped the toy: " << toy_dog->getNameToy() << std::endl;
            toy_dog.reset();
        }
        else {
            std::cout << "Nothing to drop! " << std::endl;
        }
    }
};

int main() {
    std::shared_ptr<Toy> getBall = std::make_shared<Toy>("Ball");
    std::shared_ptr<Toy> getBone = std::make_shared<Toy>("Bone");
    std::shared_ptr<Toy> getBranch = std::make_shared<Toy>("Branch");
    
    Dog a;
    Dog b;
    Dog c;
    std::cout << "===========================================" << std::endl;
    a.getToy(getBall);
    a.getToy(getBone);
    std::cout << "===========================================" << std::endl;
    b.getToy(getBone);
    b.getToy(getBall);
    std::cout << "===========================================" << std::endl;
    c.getToy(getBranch);
    std::cout << "===========================================" << std::endl;
    a.dropToy();
    b.getToy(getBone);
    std::cout << "===========================================" << std::endl;
    a.getToy(getBall);
    std::cout << "===========================================" << std::endl;
    std::cout << "It's time for the dogs to eat, stop playing)" << std::endl;
    a.dropToy();
    b.dropToy();
    c.dropToy();
    std::cout << "===========================================" << std::endl;

    std::cout << std::endl;
    
    return 0;
}