#include<iostream>

//Inheritance is used to use the properties of one class in another class.
//To inherit a class from another class, ':' is used.

class Car { //Car is the parent class
private:
    int number;  // Private members cannot be accessed directly in the derived class
    std::string name;

public:
    int model; // Public member can be accessed in derived class if public inheritance is used

    // Constructor to initialize values in the base class
    Car(int num, std::string carName, int mod) {
        number = num;
        name = carName;
        model = mod;
    }

    // Public method to access private data
    void displayCarInfo() {
        std::cout << "Car Name: " << name << ", Number: " << number << ", Model: " << model << std::endl;
    }
};

//Here Toyota is the derived or child class and inherits all public properties of Car class
//Private properties remain inaccessible
class Toyota : public Car {
private:  // These new properties are specific to the Toyota class only, not part of Car
    std::string person;

public:
    int us;

    // Constructor for Toyota class (derived class)
    // Note: Constructor should be public to allow object creation
    // Also calling the base class constructor using initializer list
    Toyota(int num, std::string carName, int mod, std::string owner, int usage)
        : Car(num, carName, mod) {  // Calling base class constructor
        person = owner;
        us = usage;
    }

    // Public method to display Toyota information along with inherited car information
    void displayToyotaInfo() {
        displayCarInfo(); // Calling the base class method
        std::cout << "Owner: " << person << ", Usage: " << us << "%\n";
    }
};

int main() {
    // Creating an object of the derived class Toyota
    // Note: The constructor is explicitly defined in both the base and derived class
    Toyota a=Toyota(1234, "Toyota Corolla", 2023, "John Doe", 75);

    // Displaying Toyota information
    a.displayToyotaInfo();

    return 0;
}
