# College Clubs Management System

## Description
The College Clubs Management System is a platform designed to streamline and improve the administration of college or university clubs. It helps track individual club performance and provides a comparative overview across clubs.

## Implementation Overview
The system manages two main types of clubs:
- **Cultural Club (Cult)**
- **Technical Club (Tech)**
  - General Technical Club (General)
  - Competitive Technical Club (Competitive)

## Key Concepts Applied
1. **Data Abstraction**: Protects data members, allowing modification only through public member functions.

2. **Data Encapsulation**: Groups relevant data and functions into classes.
3. **Operator Overloading**: Overloads operators like `+=` and `-=` to manage competitions and projects.

4. **Inheritance**: Implements multi-level inheritance with a `Club` base class and derived classes `Cult`, `Tech`, `Competitive`, and `General`.

5. **Polymorphism**: Uses a pure virtual `print()` function with different implementations across classes.

6. **Exception Handling**: Ensures input correctness using `try` and `catch`.

7. **File Handling**: Supports saving and loading club details.

8. **Class Templates**: Implements a template `ClubManager` class to manage objects dynamically.

## Features
- Create, modify, and delete clubs
- Track achievements
- List top clubs
- Manage club members, projects, and competitions
- Save and load club data to/from files

## Example Code Snippets
```cpp
// Adding achievements to a club
void add_achievements(string achievement) {
    achievements.push_back(achievement);
}

// Overloading input operator
istream &operator>>(istream &in, Club &c) {
    in >> c.name >> c.achievements;
    return in;
}

// Top clubs function
void top_clubs(int n) {
    // Logic to display top n clubs based on achievements
}
```

## Example Outputs
1. **Cultural Club Output**:
   - Created clubs, added achievements, and managed coordinators.
   - Displayed top clubs and saved data to a file.
2. **Technical General Club Output**:
   - Managed projects and listed club members.
3. **Technical Competitive Club Output**:
   - Added competitions and displayed top clubs.

## How to Run
1. Compile the code:
   ```sh
   g++ main.cpp club.cpp comp.cpp cult.cpp gen.cpp newclub.h tech.cpp -o club_manager
   ```
2. Run the executable:
   ```sh
   ./club_manager
   ```

## Acknowledgments
This project applies Object-Oriented Programming concepts to build an organized system for managing college clubs.
