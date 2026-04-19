#include <bits/stdc++.h>
using namespace std;

class MyClass {
    public:
        void myFunc() { cout << "MyClass\n"; }
};

class OtherClass : public MyClass {
    public:
        void myFunc() { cout << "OtherClass\n"; } // Override
};

int main() {
    MyClass object;
    OtherClass other_object;

    object.myFunc();
    other_object.myFunc();

    return 0;
}

// class Animal {
//     public:
//         void sound() {
//             cout << "Animal sound\n";
//         }
// };

// class Dog : public Animal {
//     public:
//         void sound() {
//             cout << "Dog barks\n";
//         }
// };

// int main() {
//     Animal* a;  // Declare a pointer to the base class (Animal)
//     Dog d;      // Create an object of the derived class (Dog)
//     a = &d;     // Point the base class pointer to the Dog object
//     a->sound(); // Call the sound() function using the pointer. Since sound() is not virtual, this calls Animal's version
//     return 0;
// }

class Animal {
    public:
        virtual void sound() {
            cout << "Animal sound\n";
        }
};

class Dog : public Animal {
    public:
        void sound() override {
            cout << "Dog barks\n";
        }
};

int main() {
    Animal* a;
    Dog d;
    a = &d;
    a->sound(); // Outputs: Dog barks
    return 0;
}

