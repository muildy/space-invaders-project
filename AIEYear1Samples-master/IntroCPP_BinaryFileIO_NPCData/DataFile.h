#pragma once

#include "raylib.h"
#include <string>
#include <vector>

using namespace std;

class DataFile
{
public:
	//A container that holds all the information necessary 
	struct Record {
		Image image;
		string name;
		int age;
	};

private:
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

	int GetRecordCount() { return recordCount; };

	void Open(string filename);

	void Save(string filename);
	void Load(string filename);


private:
	void Clear();

};

