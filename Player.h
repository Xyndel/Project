////////////////////////////////////////////////////////////////////////////////
// File Name:      Player.cpp
//
// Author:         Jing You
// CS email:       jing@cs.wisc.edu
//
// Description:    The hpp file for the Player class.
//////////////////////////////////////////////////////////////////////////////////

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <vector>
using namespace std;
class Player {
private:
	string name;
	string pos;
	string elo;
	string wantedPos;


	static vector<Player> list;
	static vector<Player> midMain;
	static vector<Player> topMain;
	static vector<Player> adcMain;
	static vector<Player> supportMain;
	static vector<Player> jungleMain;


public:

	Player(string name,string pos,string elo,string wantedPos);
	vector<Player> wantedList();
	void print();
	void write();

};
#endif /* PLAYER_H_ */
