#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void letterToASCII();
void asciiToLetter();
void goBackMain();
void information();
void colored_cout(string text, int color, bool endl);
void MenuBoxes(string menu_Name);
void test_case();
int MENU();

HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main(int argc, char ** argv) {
	system("color 0f");
    MENU();
}

int MENU() {
    system("cls");
    MenuBoxes("0 - QuitScreen");
    MenuBoxes("1 - letterToASCII");
    MenuBoxes("2 - asciiToLetter");
    MenuBoxes("3 - Information");
    MenuBoxes("9 - Test Case!");
    colored_cout("Choose a lesson sequence from the menu:", 10, false);
    cout << " ";
    int choice;
    cin >> choice;
    switch(choice){
    	case 0 : return 0;
    	case 1 : letterToASCII(); break;
    	case 2 : asciiToLetter(); break;
    	case 3 : information(); break;
    	case 9 : test_case(); break;
    	default :{
    		colored_cout("Wrong Choice!!", 4, true);
			goBackMain();
			break;
		}
	}
}

void letterToASCII() {
    string letter_Text;
    int temp;
    colored_cout("If you want to multiple words in same sentence,you have to separate words with '_' !!", 11, true);
    colored_cout("Input Letter Text: ", 11, false);
    cin >> letter_Text;
    cout << endl;
    colored_cout("ASCII Numbers (I suggest copy this \\(^v^)/ ):", 224, false);
    cout << " ";
    for (int i = 0; i < letter_Text.length(); i++) {
        temp = letter_Text[i];
        cout << temp << ".";
    }
    cout << "|" << endl << endl;
    goBackMain();
}

void asciiToLetter() {
    string ascii_Numbers, ascii_Numbers_PART, purpose;
    int temp_INT;
    char temp_CHAR;
    cout << "What are you write in here? [url/text]" << endl << "Answer: ";
    cin >> purpose;
    cout << endl << "Input ASCII Numbers: ";
    cin >> ascii_Numbers;
    cout << endl << "Letter Text: ";
    for (int i = 0; i < ascii_Numbers.size(); i++) {
        if (ascii_Numbers[i] == '|') break;
        if (ascii_Numbers[i] != '.') {
            ascii_Numbers_PART += ascii_Numbers[i];
        } else {
            istringstream(ascii_Numbers_PART) >> temp_INT;
            if (temp_INT == 95) {
                if (purpose == "text" || purpose == "TEXT") {
                    cout << " ";
                } else {
                    temp_CHAR = (char) temp_INT;
                    cout << temp_CHAR;
                }
                ascii_Numbers_PART = "\0";
            } else {
                temp_CHAR = (char) temp_INT;
                cout << temp_CHAR;
                ascii_Numbers_PART = "\0";
            }
        }
    }
    cout << endl << endl;
    goBackMain();
}

void information() {
    cout << "In progress..";
    goBackMain();
}

void goBackMain() {
    string back;
    cout << endl << endl << "Are you want to go back menu? [yes/no]" << endl << "Answer: ";
    cin >> back;
    if (back == "yes" || back == "YES") {
        MENU();
    }
}

void MenuBoxes(string menu_Name) {
    cout << char(201);
    for (int i = 0; i < 21; i++) {
        cout << char(205);
    }
    cout << char(187) << endl;
    if (menu_Name == "0 - QuitScreen" || menu_Name == "9 - Test Case!") {
        cout << char(186) << "  " << menu_Name << "     " << char(186) << endl;
    } else if (menu_Name == "1 - letterToASCII" || menu_Name == "2 - asciiToLetter") {
        cout << char(186) << "  " << menu_Name << "  " << char(186) << endl;
    } else if (menu_Name == "3 - Information") {
        cout << char(186) << "  " << menu_Name << "    " << char(186) << endl;
    }
    cout << char(200);
    for (int i = 0; i < 21; i++) {
        cout << char(205);
    }
    cout << char(188) << endl;
}

void colored_cout(string text, int color, bool endline) {
    if (endline == true) {
        SetConsoleTextAttribute(hconsole, color);
        cout << text << endl;
        SetConsoleTextAttribute(hconsole, 15);
    } else {
        SetConsoleTextAttribute(hconsole, color);
        cout << text;
        SetConsoleTextAttribute(hconsole, 15);
    }
}

void test_case() {

}
