#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;


class BadLengthException final : public std::logic_error
{
public:
    explicit BadLengthException(const int n)
        : std::logic_error(std::to_string(n)) {}
    BadLengthException(const BadLengthException &other) noexcept
        : std::logic_error(other) {}
    BadLengthException(BadLengthException &&other)
        : std::logic_error(other) {}

    virtual ~BadLengthException() override final = default;

    BadLengthException &operator= (const BadLengthException &other) noexcept
    {
        if (this != &other)
        {
            std::logic_error::operator=(other);
        }
        return *this;
    }
    BadLengthException &operator= (BadLengthException &&other) noexcept
    {
        if (this != &other)
        {
            std::logic_error::operator=(other);
        }
        return *this;
    }
};

bool checkUsername(string username) {
    bool isValid = true;
    int n = username.length();
    if(n < 5) {
        throw BadLengthException(n);
    }
    for(int i = 0; i < n-1; i++) {
        if(username[i] == 'w' && username[i+1] == 'w') {
            isValid = false;
        }
    }
    return isValid;
}

int main() {
    int T; cin >> T;
    while(T--) {
        string username;
        cin >> username;
        try {
            bool isValid = checkUsername(username);
            if(isValid) {
                cout << "Valid" << '\n';
            } else {
                cout << "Invalid" << '\n';
            }
        } catch (BadLengthException e) {
            cout << "Too short: " << e.what() << '\n';
        }
    }
    return 0;
}
