////////////////////////////////////////////////////////////////////////////////
// File Name:      Player.cpp
//
// Author:         Jing You
// CS email:       jing@cs.wisc.edu
//
// Description:    The file for the project.
//////////////////////////////////////////////////////////////////////////////////

#include "Player.h"
#include <vector>
using namespace std;


vector<Player> Player::list;
vector<Player> Player::midMain;
vector<Player> Player::topMain;
vector<Player> Player::adcMain;
vector<Player> Player::supportMain;
vector<Player> Player::jungleMain;

/*
 * Constructor for the Player class
 */
Player::Player(string name,string pos,string elo,string wantedPos){
    
    //initialize the fields
	this->name = name;
	this->pos = pos;
	this->elo = elo;
	this->wantedPos = wantedPos;
	list.push_back(*this);

    //put player into vectors accroding to their position
	if (pos=="mid"){midMain.push_back(*this);}
	else if(pos == "top") {topMain.push_back(*this);}
	else if(pos == "support"){supportMain.push_back(*this);}
	else if(pos == "adc") {adcMain.push_back(*this);}
	else if(pos == "jungle") {jungleMain.push_back(*this);}

}

/*
 * Method that return the accoeding wantedList
 */
vector<Player> Player::wantedList(){
    
    //return the wantedList according to
    //player's wanted position
	if (wantedPos=="mid"){
		return midMain;
	}
	else if(wantedPos == "top") {
		return topMain;
	}
	else if(wantedPos == "support"){
		return supportMain;
	}
	else if(wantedPos == "adc") {
		return adcMain;
	}
	else{
		return jungleMain;
	}

}

/*
 * Print method for each Player object
 */
void Player::print(){
    
    //print the player's info accrodingly
	cout << "Name: "<< name<<"\n";
	cout << "Position: "<< pos<<"\n";
	cout << "Current Elo: "<< elo<< "\n";
	cout << "Wanted Position: "<< wantedPos<< "\n";
}

/*
 * Write method to output the Player's info
 */
void Player::write(){
    
    //write the player's info in formatt to database
	std::ofstream OutputFile("database.txt");
	vector<Player>::iterator it;
    
	for (it = list.begin(); it != list.end(); ++it ) {
		OutputFile<<it->name<<","<<it->pos<<","<<it->elo<<","
		<<it->wantedPos<<endl;

	}
}
