# Bank-Managment-System
This is a C++ program that simulates a simple bank management system. The program includes three classes: Person, User, and Manager.

The Person class has five private data members, including first name, last name, email, phone number, and password. This class also has a constructor and getter and setter functions for each private data member.

The User class is inherited from the Person class and has an additional private data member called balance. This class has a constructor and getter and setter functions for the balance data member. Additionally, this class has member functions to add an account, show account details, deposit, withdraw, and search for an account.

The Manager class has a vector of User objects and member functions to load data, run the program, show account details, search for an account, add an account, deposit, and withdraw.

The main function of the program displays a menu to the user with the following options: open an account, show account details, deposit, withdraw, search for an account, and exit. Based on the user's selection, the corresponding member function of the Manager class is called.
