#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include<string>
#include "newclub.h"
using namespace std;

void top_clubs(int n, map<string, map<string, Club*>>& clubs) {
    int ch, flag = 0;
    vector<Club*> club_list;

    while (1) {
        cout << "Enter\n1.Cultural Club\n2.Competitive Tech Club\n3.General Tech Club\n" << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                for (auto it = clubs["cult"].begin(); it != clubs["cult"].end(); it++) {
                    club_list.push_back(it->second);
                }
                break;
            case 2:
                for (auto it = clubs["comp"].begin(); it != clubs["comp"].end(); it++) {
                    club_list.push_back(it->second);
                }
                break;
            case 3:
                for (auto it = clubs["gen"].begin(); it != clubs["gen"].end(); it++) {
                    club_list.push_back(it->second);
                }
                break;
            default:
                cout << "Enter a valid option!!!" << endl;
                flag = 1;
        }
        if (!flag) {
            cout << "Do you want to change your option? 1 for yes and 0 for no" << endl;
            cin >> ch;
            if (ch == 0) break;
        } else {
            continue;
        }
    }

    sort(club_list.begin(), club_list.end(), [](Club* a, Club* b) {
        return a->achievements.size() > b->achievements.size();
    });

    cout << "Top " << n << " clubs:\n";
    for (int i = 0; i < min(n, static_cast<int>(club_list.size())); ++i) {
        cout << club_list[i]->name << endl;
    }
}

void view_club(map<string, map<string, Club*>>& clubs) {
    int ch;
    string cname;
    cout << "Enter\n1.Cultural Club\n2.Competitive Tech Club\n3.General Tech Club\n" << endl;
    cin >> ch;
    cin.ignore(); // To avoid issues with getline
    cout << "Enter the name of the club:";
    getline(cin, cname);

    switch (ch) {
        case 1: {
            if (clubs["cult"].find(cname) != clubs["cult"].end()) {
                Cult* cc = dynamic_cast<Cult*>(clubs["cult"][cname]);
                cout << *cc;
            } else {
                cout << "Club not found" << endl;
            }
            break;
        }
        case 2: {
            if (clubs["comp"].find(cname) != clubs["comp"].end()) {
                cout << *clubs["comp"][cname];
            } else {
                cout << "Club not found" << endl;
            }
            break;
        }
        case 3: {
            if (clubs["gen"].find(cname) != clubs["gen"].end()) {
                cout << *clubs["gen"][cname];
            } else {
                cout << "Club not found" << endl;
            }
            break;
        }
        default:
            cout << "Invalid option!!!" << endl;
            break;
    }
}

void modify_club(map<string, map<string, Club*>>& clubs) {
    int ch, val, flag = 1;
    string new_val, cname;
    cout << "Enter\n1.Cultural Club\n2.Competitive Tech Club\n3.General Tech Club;" << endl;
    cin >> ch;
    switch(ch) {
        case 1: {
            cout << "Enter the club name" << endl;
            cin >> cname;
            if (clubs["cult"].find(cname) != clubs["cult"].end()) {
                while (flag == 1) {
                    cout << "Enter 1.Name\n2.Head\n3.PIC\n4.Club size\n5.Expenses\n6.Coordinators\n7.Achievements\nOther option to exit\n" << endl;
                    cout << "Enter your option: ";
                    cin >> ch;
                    cin.ignore();
                    switch(ch) {
                        case 1: {
                            cout << "Enter the new value: ";
                            getline(cin, new_val);
                            clubs["cult"][cname]->name = new_val;
                            clubs["cult"][new_val] = clubs["cult"][cname];
                            clubs["cult"].erase(cname);
                            break;
                        }
                        case 2: {
                            cout << "Enter the new value: ";
                            getline(cin, new_val);
                            clubs["cult"][cname]->head = new_val;
                            break;
                        }
                        case 3: {
                            cout << "Enter the new value: ";
                            getline(cin, new_val);
                            clubs["cult"][cname]->pic = new_val;
                            break;
                        }
                        case 4: {
                            cout << "Enter the new value: ";
                            cin >> val;
                            clubs["cult"][cname]->c_size = val;
                            break;
                        }
                        case 5: {
                            cout << "Enter the new value: ";
                            cin >> val;
                            clubs["cult"][cname]->expenses = val;
                            break;
                        }
                        case 6: {
                            Cult* cc = dynamic_cast<Cult*>(clubs["cult"][cname]);
                            cc->modify_coords();
                            break;
                        }
                        case 7: {
                            string ach;
                            cout << "Enter the achievement: ";
                            cin.ignore();
                            getline(cin, ach);
                            clubs["cult"][cname]->add_achievements(ach);
                            break;
                        }
                        default:
                            break;
                    }
                    cout << "Do you want to continue to modify? 1 for yes and 0 for no" << endl;
                    cin >> flag;
                }
            } else {
                cout << "Club not found" << endl;
            }
            break;
        }
case 2: {
    cout << "Enter the club name" << endl;
    cin >> cname;
    if (clubs["comp"].find(cname) != clubs["comp"].end()) {
        while (flag == 1) {
            cout << "Enter 1.Name\n2.Head\n3.PIC\n4.Club size\n5.Expenses\n6.Competitions\n7.Achievements\n8.Interns\nOther option to exit\n" << endl;
            cout << "Enter your option: ";
            cin >> ch;
            cin.ignore();
            switch(ch) {
                case 1: {
                    cout << "Enter the new value: ";
                    getline(cin, new_val);
                    clubs["comp"][cname]->name = new_val;
                    clubs["comp"][new_val] = clubs["comp"][cname];
                    clubs["comp"].erase(cname);
                    break;
                }
                case 2: {
                    cout << "Enter the new value: ";
                    getline(cin, new_val);
                    clubs["comp"][cname]->head = new_val;
                    break;
                }
                case 3: {
                    cout << "Enter the new value: ";
                    getline(cin, new_val);
                    clubs["comp"][cname]->pic = new_val;
                    break;
                }
                case 4: {
                    cout << "Enter the new value: ";
                    cin >> val;
                    clubs["comp"][cname]->c_size = val;
                    break;
                }
                case 5: {
                    cout << "Enter the new value: ";
                    cin >> val;
                    clubs["comp"][cname]->expenses = val;
                    break;
                }
                case 6: {
                    Competitive* cc = dynamic_cast<Competitive*>(clubs["comp"][cname]);
                    cc->modify_competitions();
                    break;
                }
                case 7: {
                    string ach;
                    cout << "Enter the achievement: ";
                    cin.ignore();
                    getline(cin, ach);
                    clubs["comp"][cname]->add_achievements(ach);
                    break;
                }
                case 8: {
                    Competitive* cc = dynamic_cast<Competitive*>(clubs["comp"][cname]);
                    cc->modify_interns();
                    break;
                }
                default:
                    break;
            }
            cout << "Do you want to continue to modify? 1 for yes and 0 for no" << endl;
            cin >> flag;
        }
    } else {
        cout << "Club not found" << endl;
    }
    break;
}

        case 3: {
            cout << "Enter the club name" << endl;
            cin >> cname;
            if (clubs["gen"].find(cname) != clubs["gen"].end()) {
                while (flag == 1) {
                    cout << "Enter 1.Name\n2.Head\n3.PIC\n4.Club size\n5.Expenses\n6.Projects\n7.Achievements\n8.Members\nOther option to exit\n" << endl;
                    cout << "Enter your option: ";
                    cin >> ch;
                    cin.ignore();
                    switch(ch) {
                        case 1: {
                            cout << "Enter the new value: ";
                            getline(cin, new_val);
                            clubs["gen"][cname]->name = new_val;
                            clubs["gen"][new_val] = clubs["gen"][cname];
                            clubs["gen"].erase(cname);
                            break;
                        }
                        case 2: {
                            cout << "Enter the new value: ";
                            getline(cin, new_val);
                            clubs["gen"][cname]->head = new_val;
                            break;
                        }
                        case 3: {
                            cout << "Enter the new value: ";
                            getline(cin, new_val);
                            clubs["gen"][cname]->pic = new_val;
                            break;
                        }
                        case 4: {
                            cout << "Enter the new value: ";
                            cin >> val;
                            clubs["gen"][cname]->c_size = val;
                            break;
                        }
                        case 5: {
                            cout << "Enter the new value: ";
                            cin >> val;
                            clubs["gen"][cname]->expenses = val;
                            break;
                        }
                        case 6: {
                            General* cc = dynamic_cast<General*>(clubs["gen"][cname]);
                            cc->modify_projects();
                            break;
                        }
                        case 7: {
                            string ach;
                            cout << "Enter the achievement: ";
                            cin.ignore();
                            getline(cin, ach);
                            clubs["gen"][cname]->add_achievements(ach);
                            break;
                        }
                        case 8: {
                            General* cc = dynamic_cast<General*>(clubs["gen"][cname]);
                            cc->modify_members();
                            break;
                        }
                        default:
                            break;
                    }
                    cout << "Do you want to continue to modify? 1 for yes and 0 for no" << endl;
                    cin >> flag;
                }
            } else {
                cout << "Club not found" << endl;
            }
            break;
        }
        default:
            cout << "Invalid option!!!" << endl;
            break;
    }
}


void create_club(map<string, map<string, Club*>>& clubs) {
    int ch;
    cout << "Enter\n1.Cultural Club\n2.Competitive Tech Club\n3.General Tech Club\n" << endl;
    cin >> ch;
    switch (ch) {
        case 1: {
            Cult* c1 = new Cult();
            cin >> *c1;
            clubs["cult"][c1->name] = c1;
            break;
        }
        case 2: {
            Competitive* c2 = new Competitive();  // Corrected the typo here
            cin >> *c2;
            clubs["comp"][c2->name] = c2;
            break;
        }
        case 3: {
            General* c3 = new General();
            cin >> *c3;
            clubs["gen"][c3->name] = c3;
            break;
        }
    }
}

void delete_club(map<string, map<string, Club*>>& clubs) {
    int ch;
    string club_name;

    cout << "Enter\n1. Cultural Club\n2. Competitive Tech Club\n3. General Tech Club\n";
    cin >> ch;

    cout << "Enter the name of the club you want to delete: ";
    cin >> club_name;

    string category;
    switch (ch) {
        case 1: category = "cult"; break;
        case 2: category = "comp"; break;
        case 3: category = "gen"; break;
        default:
            cout << "Invalid category!" << endl;
            return;  // Removed break as it's redundant here
    }

    auto it = clubs[category].find(club_name);
    if (it != clubs[category].end()) {
        delete it->second;
        clubs[category].erase(it);
        cout << "Club deleted successfully!" << endl;
    } else {
        cout << "Club not found!" << endl;
    }
}

void view_all(map<string, map<string, Club*>>& clubs) {
    int flag = 1, ch;
    map<string, Club*> it;
    cout << "Enter\n1.Cultural Club\n2.Competitive Tech Club\n3.General Tech Club" << endl;
    cin >> ch;
    while (flag == 1) {
        switch (ch) {
            case 1:
                cout << "Cultural ";
                it = clubs["cult"];
                flag = 0;
                break;
            case 2:
                cout << "Technical Competitive ";
                it = clubs["comp"];
                flag = 0;
                break;
            case 3:
                cout << "Technical General ";
                it = clubs["gen"];
                flag = 0;
                break;
            default:
                cout << "Enter a valid option!!!" << endl;
                cin >> ch;
                break;
        }
    }
    cout << "Clubs: " << endl;
    for (auto rt = it.begin(); rt != it.end(); rt++) {
        cout << rt->first << endl;
    }
}

int main() {
    int ch, n;
    map<string, map<string, Club*>> clubs;
    clubs["gen"] = {};
    clubs["cult"] = {};
    clubs["comp"] = {};

    while (1) {
        cout << "Enter\n1.Add club\n2.Modify club\n3.View club\n4.Delete club\n5.Top n clubs\n6.View all Clubs" << endl;
        cout << "Enter your choice:";
        cin >> ch;

        switch (ch) {
            case 1: create_club(clubs); break;
            case 2: modify_club(clubs); break;
            case 3: view_club(clubs); break;
            case 4: delete_club(clubs); break;
            case 5:
                cout << "Enter the number of clubs to be displayed:";
                cin >> n;
                cout << "If number is greater than number of clubs present, only the available clubs will be displayed." << endl;
                top_clubs(n, clubs);
                break;
            case 6: view_all(clubs); break;
        }

        cout << "Do you want to continue?1 for yes and 0 for no" << endl;
        cin >> ch;
        if (ch == 0) break;
    }

    for (auto& c : clubs) {
        for (auto& club : c.second) {
            delete club.second;
        }
    }

    return 0;
}
