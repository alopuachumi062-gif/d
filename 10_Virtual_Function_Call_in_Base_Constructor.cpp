// Question 10: Show virtual function behavior when called from a base constructor.
#include <iostream>
using namespace std;

class DatabaseConnection {
public:
    DatabaseConnection() {
        cout << "DatabaseConnection constructor: ";
        logConnectionStatus();
    }

    virtual void logConnectionStatus() {
        cout << "Base connection logged" << endl;
    }

    virtual ~DatabaseConnection() = default;
};

class SecureConnection : public DatabaseConnection {
public:
    void logConnectionStatus() override {
        cout << "Secure Logged" << endl;
    }
};

int main() {
    SecureConnection connection;
    return 0;
}

/*
Explanation:
A virtual function call made inside a base-class constructor does not dispatch
to an override in the derived class. While the base constructor is running,
the derived part of the object has not been constructed yet. Therefore, the
base-class version is called and the output is "Base connection logged".
*/
