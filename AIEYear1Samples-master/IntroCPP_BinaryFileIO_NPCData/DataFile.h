#pragma once

#include "raylib.h"
#include <string>
#include <vector>

using namespace std;

class DataFile
{
public:
	//Holds all the info needed for display on screen
	struct Record {
		Image image;
		string name;
		int age;
	};

private://everything that records needs to do its job
	int recordCount;
	std::vector<Record*> records;	// delete this vector. Load only the required record 
	
	ifstream* inFile;
	int maxFileIndexRead;

	int filePointer;
	
public:
	DataFile();
	~DataFile();

	void AddRecord(string imageFilename, string name, int age);
	Record* GetRecord(int index);
	void Open(string filename);

	int GetRecordCount() { return recordCount; };

	//unused or obselete
	void Save(string filename);
	void Load(string filename);


private:
	void Clear();

};

