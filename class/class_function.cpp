#include <iostream>
#include <cstring>

using namespace std;

class String {
public:
    String() : m_str(nullptr) {}
    
    // Constructor that takes a const char* - assumed implemented as per comments
    String(const char* s) {
        if (s) {
            size_t len = std::strlen(s) + 1;
            m_str = new char[len];
            std::strcpy(m_str, s);
        } else {
            m_str = nullptr;
        }
    }
    
    // Destructor - uses delete[] to match new[] allocation
    ~String() {
        delete[] m_str;  // Must use delete[] because memory was allocated with new[]
    }
    
    // Copy assignment operator implementation
    String& operator=(const String &other) {
        // Self-assignment check
        if (this == &other) {
            return *this;
        }
        
        // Free existing memory using delete[] (not free())
        delete[] m_str;
        
        // Deep copy the new string
        if (other.m_str) {
            size_t len = std::strlen(other.m_str) + 1;
            m_str = new char[len];
            std::strcpy(m_str, other.m_str);
        } else {
            m_str = nullptr;
        }
        
        return *this;  // Return reference for chain assignment
    }
    
    // Friend function for output operator
    friend ostream& operator<<(ostream& os, const String& str);
    
private:
    char *m_str;
};

// Output operator implementation
ostream& operator<<(ostream& os, const String& str) {
    if (str.m_str) {
        os << str.m_str;
    } else {
        os << "";
    }
    return os;
}

int main() {
    String A("123");
    String B;
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;

    A = B = "456";
    // Test output operator
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;


    B = B;
    // Test output operator
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
}
