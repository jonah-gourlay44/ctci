#include <stacks_and_queues/animal_shelter.h>
#include <stdexcept>

namespace stacks_and_queues
{

int Pet::id_ = 0;

void AnimalShelter::enqueue(Pet& pet)
{
    pet.age = id++;
    if (dynamic_cast<Dog*>(&pet)) {
        dog_list_.emplace_back(dynamic_cast<Dog&>(pet));
    } else if (dynamic_cast<Cat*>(&pet)) {
        cat_list_.emplace_back(dynamic_cast<Cat&>(pet));
    }
}

Dog AnimalShelter::dequeueDog()
{
    if (dog_list_.empty()) {
        throw std::runtime_error("No dogs in the shelter.");
    }

    auto dog = dog_list_.front();
    dog_list_.pop_front();
    return dog;
}

Cat AnimalShelter::dequeueCat()
{
    if (cat_list_.empty()) {
        throw std::runtime_error("No cats in the shelter.");
    }

    auto cat = cat_list_.front();
    cat_list_.pop_front();
    return cat;
}

Pet AnimalShelter::dequeueAny()
{
    if (cat_list_.empty() && dog_list_.empty()) {
        throw std::runtime_error("No animals in the shelter.");
    }

    if (cat_list_.empty()) {
        return dequeueDog();
    } else if (dog_list_.empty()) {
        return dequeueCat();
    }

    if (cat_list_.front().age < dog_list_.front().age) {
        return dequeueCat();
    } else {
        return dequeueDog();
    }
}

bool AnimalShelter::empty()
{
    return cat_list_.empty() && dog_list_.empty();
}

} // namespace stacks_and_queues