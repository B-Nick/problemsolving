#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;

        /* Enter your code here */

        std::ios initState(nullptr);
        initState.copyfmt(std::cout);

        std::cout << std::hex << std::nouppercase << std::showbase << std::left
                  << static_cast<long>(A)  << std::endl;

        std::cout.copyfmt(initState);

        std::cout << std::fixed << std::setprecision(2) << std::right << std::setfill('_')
                  << std::showpos << B << std::endl;

        std::cout.copyfmt(initState);

        std::cout << std::scientific << std::setprecision(9) << std::uppercase
                  << C << std::endl;

        std::cout.copyfmt(initState);


    }
    return 0;

}
