//The first two lines make sure that if anything in the file here has not already been defined, it will be defined here.
//The entire file is enclosed within this statement and ends with #endif
#ifndef FILELOG_H
#define FILELOG_H


#include<iostream>	//obviously
#include<string>	//Strings will be used here
#include<fstream>	//This is needed to write to an external file
#include<strstream>	//Stringstream is needed to add to existing strings

using namespace std;

class filelog {
protected:
	string filename;
	ofstream log;
public:
	filelog(string name) : filename(name) {
		filename += ".log";
		log.open(filename);
	}



	bool warning(string item) {
		if (log.fail())
			return false;

		log << "Warning: " << item << endl;

		return true;
	}


	bool error(string item) {
		if (log.fail())
			return false;

		log << "ERROR: " << item << endl;

		return true;
	}

	bool info(string item) {
		if (log.fail())
			return false;

		log << "Information: " << item << endl;

		return true;
	}

	///<summary>You may include an int variable in your log</summary>
	bool info(string item, int other) {


		if (log.fail())
			return false;

		log << "Information: " << item << other << endl;
	}

	///<summary>Checks if your log file can be opened or created. Returns true if it fails.</summary>
	bool bad() {
		if (log.fail())
			return true;

		else
			return false;
	}

	///<summary>Checks if your log file can be opened or created. Returns true if it succeeds and also writes to the log file that it successfully opened.</summary>
	bool good() {
		if (log.fail())
			return false;

		else {
			log << "Information: The log file was created and opened successfully." << endl;
			return true;
		}
	}

};



#endif


