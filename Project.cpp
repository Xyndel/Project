////////////////////////////////////////////////////////////////////////////////
// File Name:      Player.cpp
//
// Author:         Jing You
// CS email:       jing@cs.wisc.edu
//
// Description:    The main file for the project.
//////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "Player.cpp"
using namespace std;

/*
 * Read method to read in the database file
 */
void Read(std::ifstream &inFile) {

	string line = "";
	vector <string> text;

    //read in the file line by line
	while (getline(inFile,line)){
		text.push_back(line);
	}

    //read in each line in formatt for the player info
	vector <string>::iterator it;
	for (it = text.begin(); it != text.end(); it++) {
		string s = *it;
		string p = "";
		vector <string> info;

		for (int i = 0; i < s.length(); ++i) {
			if(s[i] != ','){
				p += s[i];
				if(i == s.length()-1){
					info.push_back(p);
					p = "";
				}
			}else{
				info.push_back(p);
				p = "";
			}

		}

        //create the player object
		Player *p1 = new Player(info[0],info[1],info[2], info[3]);
	}
}


int main(){
    
	string nameIn;
	string posIn;
	string eloIn;
	string wantedPosIn;
	Player *p;

    //print out welcome message
	cout << "Welcome to the the League of Legends game matching system!\n";
	cout << "This application helps you to find friends to play ranked game with! :D\n";

    //read in database file
	std::ifstream InputFile;
	InputFile.open("database.txt");
	Read(InputFile);

    //ask the user to type in info
	cout << "Please enter your name/nickname\n";
	std::getline (cin,nameIn);
	cout << "Hi "<< nameIn <<" ! Please enter your favorite position.\n";
	cout << "(mid/top/adc/jungle/support)\n";
	std::getline (cin,posIn);
	cout << "Please enter your current elo:\n";
	cout << "(Bronze/Silver/Gold/Platinum/Diamond/Challenger/Unranked)\n";
	std::getline (cin,eloIn);
	cout << "What position of players do you want to duo with?\n";
	cout << "(mid/top/adc/jungle/support)\n";
	std::getline (cin,wantedPosIn);

    //create Player object for the user
	p = new Player(nameIn,posIn,eloIn,wantedPosIn);

	cout<<"You might want to play with these players!\n";

    //print out the matching list
	vector<Player>::iterator it3;
	for (it3 = p->wantedList().begin(); it3 != p->wantedList().end(); ++it3 ) {
		it3->print();
		cout<<""<<endl;
	}

    //print goodbye message and refresh the data in database file
	cout<<"Thank you for using League of Legends game matching system!\n";
 	p->write();
}



