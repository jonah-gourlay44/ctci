#pragma once
#include <list>
#include <string>

namespace stacks_and_queues
{

struct Pet {
    Pet() 
    {
        id_++;
    }

    virtual ~Pet() = default;
    int age;

    friend bool operator==(const Pet&, const Pet&);

private:
    static int id_;
};

struct Dog : Pet {
    Dog()
        : Pet()
    {}
};

struct Cat : Pet {
    Cat()
        : Pet()
    {}
};

inline bool operator==(const Pet& lhs, const Pet& rhs)
{
    return lhs.id_ == rhs.id_;
}

class AnimalShelter {
public:
    AnimalShelter() = default;

    void enqueue(Pet& pet);
    Dog dequeueDog();
    Cat dequeueCat();
    Pet dequeueAny();
    bool empty();

private:
    std::list<Cat> cat_list_;
    std::list<Dog> dog_list_;
    int id = 0;
};

} // namespace stacks_and_queues