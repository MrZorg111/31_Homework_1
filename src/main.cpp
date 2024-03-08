#include <iostream>
#include <string>
#include <memory>


class Toy {
    std::string name_toy;
public:
    Toy (std::string _name_toy) : name_toy(_name_toy){};
    Toy(){};

    void getNameToy() {
        std::cout << name_toy << std::endl;
    }
    ~Toy() {
       std::cout << "\n\nToy " << name_toy<< " was dropped " << std::endl;
   }
};
class dogToy {
    Toy* obj;
public:
    dogToy() {
        obj = new Toy("Somename");
    }
    dogToy(std::string name) {
        obj = new Toy(name);
    }
    dogToy(const dogToy& other) {
        obj = new Toy(*other.obj);
    }
    dogToy& operator=(const dogToy& other) {
        if(this == &other) {
            return *this;
        }
        if(this != nullptr) {
            delete obj;
        }
        obj = new Toy(*other.obj);
        return *this;
    }

    ~dogToy() {
        delete obj;
    }
};

class Dog {
    std::shared_ptr<Toy> toy_dog;
public:
    Dog(std::shared_ptr<Toy> _toy_dog) : toy_dog(_toy_dog) {};
    Dog(){};

    void getToy(std::shared_ptr<Toy> take_toy) {
        if (toy_dog != nullptr) {
            std::cout << "I already have this toy." << std::endl;
        }
        else if (take_toy.use_count() > 2) {
            std::cout << "Another dog is playing with this toy." << std::endl;
        }
        else if (take_toy.use_count() == 2) {
            toy_dog = take_toy;
            std::cout << "The dog picked up the toy." << std::endl;
        }        
    }

    void dropToy() {
        if(toy_dog != nullptr) {
            toy_dog = nullptr;
            std::cout << "The dog dropped the toy." << std::endl;
        }
        else {
            std::cout << "Nothing to drop." << std::endl;
        }
    }

};

int main() {
    std::shared_ptr<Toy> d_t = std::make_shared<Toy>("Ball");
    Dog a;
    Dog b;
    Dog c;

    a.getToy(d_t);
    b.getToy(d_t);
    b.dropToy();
    c.getToy(d_t);
    c.dropToy();
    a.getToy(d_t);
    a.dropToy();
    b.getToy(d_t);
    
 
 return 0;

}