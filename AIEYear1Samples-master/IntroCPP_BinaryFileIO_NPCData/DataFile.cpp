#include "DataFile.h"
#include <fstream>
using namespace std;

DataFile::DataFile()
{
	recordCount = 0;
}

DataFile::~DataFile()
{
	Clear();
}
//creates and adds a record to the records vector
void DataFile::AddRecord(string imageFilename, string name, int age)
{
	Image i = LoadImage(imageFilename.c_str());

	Record* r = new Record;
	r->image = i;
	r->name = name;
	r->age = age;
	
	records.push_back(r);
	recordCount++;
}

/// <summary>
/// reads the file based on the index and places it onto the end of the vector records[], then passes the item inside of the vector 
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
DataFile::Record* DataFile::GetRecord(int index)
{
	//ensures that only a file that hasnt been read yet gets read and then placed
	if (maxFileIndexRead < index ) {
		inFile->seekg(filePointer, inFile->beg);//sets the reading position within the file to the filepointer
		maxFileIndexRead++;
		
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		inFile->read((char*)&width, sizeof(int));
		inFile->read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		inFile->read((char*)&nameSize, sizeof(int));
		inFile->read((char*)&ageSize, sizeof(int));

		char* imgdata = new char[imageSize];
		inFile->read(imgdata, imageSize);

		Image img = LoadImageEx((Color*)imgdata, width, height);
		char* name = new char[nameSize+1];
		name[nameSize] = 0;

		int age = 0;

		inFile->read((char*)name, nameSize);
		inFile->read((char*)&age, ageSize);

		//creates a new record and places it onto the end of the vector
		Record* r = new Record();
		r->image = img;
		r->name = string(name);
		r->age = age;
		records.push_back(r);

		filePointer = inFile->tellg();//sets filePointer to the current position of the 

		delete[] imgdata;
		delete[] name;
		return records[index];
	}
	//if the file already appears in the vector based on the index, then it just returns it
	return records[index];
}

/// <summary>
/// opens the given datafile, reads the first int and sets the file pointer to the current position in file
/// </summary>
/// <param name="filename"></param>
void DataFile::Open(string filename) {

	inFile = new ifstream(filename, ios::binary);//reads entire file, then saves it to the infile

	recordCount = 0;
	inFile->read((char*)&recordCount, sizeof(int));//reads up to the first int

	maxFileIndexRead = -1;

	filePointer = inFile->tellg(); //Returns the position of the current character in the input stream.
}


#ifdef DEBUG//i guess this makes it so that this doesnt go to compiler

//unused
void DataFile::Save(string filename)
{
	ofstream outfile(filename, ios::binary);

	int recordCount = records.size();
	outfile.write((char*)&recordCount, sizeof(int));

	for (int i = 0; i < recordCount; i++)
	{		
		Color* imgdata = GetImageData(records[i]->image);
				
		int imageSize = sizeof(Color) * records[i]->image.width * records[i]->image.height;
		int nameSize = records[i]->name.length();
		int ageSize = sizeof(int);

		outfile.write((char*)&records[i]->image.width, sizeof(int));
		outfile.write((char*)&records[i]->image.height, sizeof(int));
		
		outfile.write((char*)&nameSize, sizeof(int));
		outfile.write((char*)&ageSize, sizeof(int));

		outfile.write((char*)imgdata, imageSize);
		outfile.write((char*)records[i]->name.c_str(), nameSize);
		outfile.write((char*)&records[i]->age, ageSize);
	}

	outfile.close();
}

//obselete
void DataFile::Load(string filename)
{
	Clear();

	ifstream infile(filename, ios::binary);

	recordCount = 0;
	infile.read((char*)&recordCount, sizeof(int));

	for (int i = 0; i < recordCount; i++)
	{		
		int nameSize = 0;
		int ageSize = 0;
		int width = 0, height = 0, format = 0, imageSize = 0;

		infile.read((char*)&width, sizeof(int));
		infile.read((char*)&height, sizeof(int));

		imageSize = sizeof(Color) * width * height;

		infile.read((char*)&nameSize, sizeof(int));
		infile.read((char*)&ageSize, sizeof(int));

		char* imgdata = new char[imageSize];
		infile.read(imgdata, imageSize);

		Image img = LoadImageEx((Color*)imgdata, width, height);
		char* name = new char[nameSize];
		int age = 0;
				
		infile.read((char*)name, nameSize);
		infile.read((char*)&age, ageSize);

		Record* r = new Record();
		r->image = img;
		r->name = string(name);
		r->age = age;
		records.push_back(r);

		delete [] imgdata;
		delete [] name;
	}

	infile.close();
}

#endif // DEBUG
void DataFile::Clear()
{
	for (int i = 0; i < records.size(); i++)
	{
		delete records[i];
	}
	records.clear();
	recordCount = 0;
}

