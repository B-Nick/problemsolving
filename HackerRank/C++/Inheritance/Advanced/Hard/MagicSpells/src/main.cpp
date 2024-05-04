#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell {
private:
    string scrollName;
public:
    Spell(): scrollName("") { }
    Spell(string name): scrollName(name) { }
    virtual ~Spell() { }
    string revealScrollName() {
        return scrollName;
    }
};

class Fireball : public Spell {
private: int power;
public:
    Fireball(int power): power(power) { }
    void revealFirepower(){
        cout << "Fireball: " << power << endl;
    }
};

class Frostbite : public Spell {
private: int power;
public:
    Frostbite(int power): power(power) { }
    void revealFrostpower(){
        cout << "Frostbite: " << power << endl;
    }
};

class Thunderstorm : public Spell {
private: int power;
public:
    Thunderstorm(int power): power(power) { }
    void revealThunderpower(){
        cout << "Thunderstorm: " << power << endl;
    }
};

class Waterbolt : public Spell {
private: int power;
public:
    Waterbolt(int power): power(power) { }
    void revealWaterpower(){
        cout << "Waterbolt: " << power << endl;
    }
};

class SpellJournal {
public:
    static string journal;
    static string read() {
        return journal;
    }
};
string SpellJournal::journal = "";

int lcs(const std::string &s0, const std::string &s1, const int m, const int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (s0[m - 1] == s1[n - 1])
        return 1 + lcs(s0, s1, m - 1, n - 1);
    else
        return max(lcs(s0, s1, m, n - 1),
                   lcs(s0, s1, m - 1, n));
}


void counterspell(Spell *spell) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    if (!spell) throw std::invalid_argument("Null spell");

    Fireball *const fireball = dynamic_cast<Fireball*>(spell);
    if (fireball)
    {
        fireball -> revealFirepower();
        return;
    }
    Frostbite *const frostbite = dynamic_cast<Frostbite*>(spell);
    if (frostbite)
    {
        frostbite -> revealFrostpower();
        return;
    }
    Waterbolt *const waterbolt = dynamic_cast<Waterbolt*>(spell);
    if (waterbolt)
    {
        waterbolt -> revealWaterpower();
        return;
    }
    Thunderstorm *const thunderstorm = dynamic_cast<Thunderstorm*>(spell);
    if (thunderstorm)
    {
        thunderstorm -> revealThunderpower();
        return;
    }

    // Longest Common Subsequence (LCS) problem
    const std::string scrollName(spell -> revealScrollName());
    const std::string journalSpellName(SpellJournal::read());

    if (scrollName.empty() || scrollName.size() > 1000) throw std::invalid_argument("Invalid scroll name");
    if (journalSpellName.empty() || journalSpellName.size() > 1000) throw std::invalid_argument("Invalid journal spell name");
    const int scrollNameLength = scrollName.length();
    const int journalSpellLength = journalSpellName.length();
    std::vector<std::vector<int>> lcsMatrix(scrollNameLength + 1, std::vector<int>(journalSpellLength + 1));

    for (int i = 0; i <= scrollNameLength; ++i)
    {
        for (int j = 0; j <= journalSpellLength; ++j)
        {
            if (!i || !j)
            {
                lcsMatrix[i][j] = 0;
            }
            else if (scrollName.at(i - 1) == journalSpellName.at(j - 1))
            {
                lcsMatrix[i][j] = 1 + lcsMatrix.at(i - 1).at(j - 1);
            }
            else
            {
                lcsMatrix[i][j] = std::max(lcsMatrix.at(i).at(j - 1), lcsMatrix.at(i - 1).at(j));
            }
        }
    }
    std::cout << lcsMatrix[scrollNameLength][journalSpellLength] << std::endl;

    //const int result = lcs(scrollName, journalSpellName, scrollNameLength, journalSpellLength);
}

class Wizard {
public:
    Spell *cast() {
        Spell *spell;
        string s; cin >> s;
        int power; cin >> power;
        if(s == "fire") {
            spell = new Fireball(power);
        }
        else if(s == "frost") {
            spell = new Frostbite(power);
        }
        else if(s == "water") {
            spell = new Waterbolt(power);
        }
        else if(s == "thunder") {
            spell = new Thunderstorm(power);
        }
        else {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
