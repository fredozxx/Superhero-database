#include <iostream>
#include <string>
#include <algorithm> // For sorting
#include <cctype> // For toupper/tolower

using namespace std;

// Declare arrays to store superhero data
string names[10] = {"Squirrel Girl", "Arm-Fall-Off-Boy", "The Tick", "Booster Gold", "The Question", 
                     "Matter-Eater Lad", "The Condiment King", "Polka-Dot Man", "Kite Man", "Tarantula"};
string superpowers[10] = {"Control Squirrels", "Detachable Limbs", "Super Strength", "Time Manipulation", "Invisibility",
                           "Eating Anything", "Condiments", "Polka Dots", "Flying", "Wall Climbing"};
string weaknesses[10] = {"Time Limits", "Heavy Objects", "Poor Judgment", "His Ego", "Claustrophobia",
                          "Being Too Full", "Mayo", "Polka Dots", "His Costume", "His Shoes"};
int yearIntroduced[10] = {1992, 1989, 1986, 1986, 1987, 1962, 1992, 1997, 1986, 1995};
string comicUniverse[10] = {"Marvel", "DC", "Other", "DC", "DC", "DC", "DC", "DC", "DC", "Marvel"};

// Function to search for superhero by name (case-insensitive)
void searchByName(const string& superheroName) {
    bool found = false;
    for (int i = 0; i < 10; i++) {
        if (names[i].find(superheroName) != string::npos) {
            cout << "Found " << names[i] << " - Power: " << superpowers[i] 
                 << ", Weakness: " << weaknesses[i] << ", Year: " << yearIntroduced[i]
                 << ", Universe: " << comicUniverse[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No superhero found with the name: " << superheroName << endl;
    }
}

// Function to sort superheroes alphabetically by name
void sortSuperheroes() {
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (names[i] > names[j]) {
                swap(names[i], names[j]);
                swap(superpowers[i], superpowers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(yearIntroduced[i], yearIntroduced[j]);
                swap(comicUniverse[i], comicUniverse[j]);
            }
        }
    }
    cout << "Superheroes sorted alphabetically by name." << endl;
}

// Function to display superheroes in uppercase or lowercase
void displayHeroes(bool toUppercase) {
    for (int i = 0; i < 10; i++) {
        string name = names[i];
        string power = superpowers[i];
        string weakness = weaknesses[i];

        // Convert to uppercase or lowercase based on user choice
        if (toUppercase) {
            transform(name.begin(), name.end(), name.begin(), ::toupper);
            transform(power.begin(), power.end(), power.begin(), ::toupper);
            transform(weakness.begin(), weakness.end(), weakness.begin(), ::toupper);
        } else {
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            transform(power.begin(), power.end(), power.begin(), ::tolower);
            transform(weakness.begin(), weakness.end(), weakness.begin(), ::tolower);
        }

        cout << "Name: " << name << ", Power: " << power << ", Weakness: " << weakness << endl;
    }
}

int main() {
    int choice;
    string superheroName;
    bool toUppercase = true;

    do {
        // Display menu to the user
        cout << "\n==== Superhero Database ====" << endl;
        cout << "1. Search for a superhero by name" << endl;
        cout << "2. Sort superheroes by name" << endl;
        cout << "3. Display all superheroes (uppercase)" << endl;
        cout << "4. Display all superheroes (lowercase)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                // Search by name
                cout << "Enter superhero name to search: ";
                cin.ignore(); // to ignore the leftover newline character
                getline(cin, superheroName);
                searchByName(superheroName);
                break;

            case 2:
                // Sort superheroes
                sortSuperheroes();
                break;

            case 3:
                // Display superheroes in uppercase
                displayHeroes(true);
                break;

            case 4:
                // Display superheroes in lowercase
                displayHeroes(false);
                break;

            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 5);

    return 0;
}
