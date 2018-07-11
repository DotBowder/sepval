/************************************************************************
Author:         Daniel Bowder
Date:           July 10, 2018
Description:    Program saves or loads a CSV or TSV file.

      Data read from a file is held in the fileData object.
      This object is of type vector<vector<string>>, which is to
      say that this object is a vector, that contains vectors. The
      format is fileData[row][col]. The data returned is a string
      cut from the csv/tsv file.

      Data that is to be saved must be in the format:
      vector<vector<string>> in order to be saved.
      This can be accomplished by a column and a row nested
      for loops pushing strings onto the vector<string>

      eg:
          vector<vector<string>> fileData;
          for (row in file) {
            vector<string> RowVector;
            for (colum in row) {
              RowVector.push_back(colum);
            }
          fileData.push_bach(RowVector);
          }
          SaveFile("MyOutputFile.csv", ",", fileData);

***********************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <vector>
using std::vector;
#include <sstream>
using std::stringstream;

#include <cstring>


void SaveFile(string fileName, char delimiter, vector<vector<string>> fileData) {
  ofstream outputFileStream;
  outputFileStream.open(fileName);
  for (int i=0; i < fileData.size(); i++) {
    for (int ii=0; ii < fileData[i].size(); ii++) {
      outputFileStream << fileData[i][ii] << delimiter;
    }
    outputFileStream << endl;
  }
}

vector<vector<string>> OpenFile(string fileName, char delimiter) {
  vector<vector<string>> fileData;
  ifstream file(fileName);
  if (file) {
    cout << "Openning file..." << endl;
    int lineNumber = 0;
    string stringBuffer;
    while (getline(file, stringBuffer,'\n')) {
      if (!file) {
        file.close();
      } else {
        vector<string> lineArray; // Stores current line in vector<string> format;
        stringstream lineStream; // We declare a stringstream object so that we can preform getline(,,delimiter), the 3rd input for this function defines a delimiter to split the stringstream object by.
        lineStream.str(stringBuffer); // We feed the current line, stringBuffer into the stringstream object.
        string lineElement; // Line element is a temporary string to hold each element in our current line.
        while (getline(lineStream, lineElement, delimiter)) {
          lineArray.push_back(lineElement); // Save each element of this lie to the lineArray structure.
        }
        fileData.push_back(lineArray); // once we've gathered all the elements in this line, we can push this lineArray up to our fileData structure.
        lineNumber++;
      }
    }
    // cout << "FileData.size():\t" << fileData.size() << endl;
    // cout << "FileData[0].size():\t" << fileData[0].size() << endl;
    return fileData;
  } else {
    cout << "Failed to open file..." << endl;
    return fileData;
  }
  return fileData;

}

vector<vector<string>> GenRandomFileData(int rowMax, int colMax) {
    vector<vector<string>> fileData;
    for (int row=0; row < rowMax; row++) {
      vector<string> RowVector;
      for (int col=0; col < colMax; col++) {
        RowVector.push_back("A");
      }
    fileData.push_back(RowVector);
    }
    return fileData;
}

int main(int argc, char* argv[]) {

  //////////////////////
  // Parse User Input //
  //////////////////////
  if ( argc < 2 ) {
    cout << "Please enter an input filename and delimiter parameters when launching the program...\neg:\treader myfile.tsv \\\\t " << endl;
    return 1;
  }
  if ( argc < 3 ) {
    cout << "Please enter an input filename and delimiter parameters when launching the program...\neg:\treader myfile.tsv \\\\t " << endl;
    return 1;
  }

  string fileName = argv[1];
  string fileDelim = argv[2];
  char fileDelimChar;
  if ("\\t" == fileDelim) {
    fileDelimChar = '\t';
  } else if ("," == fileDelim) {
    fileDelimChar = ',';
  }



  ///////////////
  // Open FIle //
  ///////////////
  // vector<vector<string>> fileData = OpenFile(fileName, fileDelimChar);
  // cout << "FileData.size():\t" << fileData.size() << endl;
  // if (0 < fileData.size()) {
  // cout << "FileData[0].size():\t" << fileData[0].size() << endl;}


  //////////////////
  // Process Data //
  //////////////////
  vector<vector<string>> fileData = GenRandomFileData(100,100);

  cout << sizeof(fileData);

  return 0;
}









//
