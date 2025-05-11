#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "Line.h"
using namespace std;

class Document {
 public:
  // Name - Document() - Default constructor
  // Desc - Creates an empty Document (linked list)
  // Preconditions - None
  // Postconditions - Sets m_head to nullptr and m_lineCount = 0
  Document();
  // Name - ~Document() - Destructor
  // Desc - Removes all lines from Document (removes all nodes from linked list)
  // Preconditions - None
  // Postconditions - Removes all lines and sets m_head to nullptr
  //                  and m_lineCount = 0
  ~Document();
  // Name - InsertLine(string,int)
  // Desc - Inserts a new line (node) into the Document (linked list)
  //        Dynamically allocates new line and inserts line in position
  //        indicated. Inserts the line **before** the position.
  //        For example, if position 1 then inserts a new first line to the Document
  // Preconditions - Document exists
  // Postconditions - New line inserted into the Document
  void InsertLine(string text, int position);
  // Name - DeleteLine(int)
  // Desc - Deletes a line from the Document at a provided position
  //        Deletes the exact line chosen.
  //        Indicates the document is empty if the Document has no lines
  // Preconditions - Document exists and line exists
  // Postconditions - Line removed from Document
  void DeleteLine(int position);
  // Name - EditLine(int, string)
  // Desc - Edits the text in a specific Line at a provided position (line number).
  //        Updates the string in a specific Line. Uses the exact line number.
  //        Indicates the document is empty if the Document has no Lines
  // Preconditions - Document exists and line exists.
  // Postconditions - Line text updated at a provided position
  void EditLine(int position, string newText);
  // Name - DisplayDocument
  // Desc - Iterates through the Document and displays all data in Line
  //        Indicates the document is empty if the Document has no lines
  // Preconditions - Document exists
  // Postconditions - Displays all lines in Document
  void DisplayDocument();
  // Name - SearchWord(string)
  // Desc - Iterates through the Document and searches for provided text
  //        Indicates if string not found
  // Preconditions - Document exists
  // Postconditions - Indicates line number where found or not
  void SearchWord(string word);
  // Name - SaveToFile(string)
  // Desc - Iterates through the Document and saves all lines to
  //        provided filename
  // Preconditions - Document exists
  // Postconditions - Writes all lines in Document to file
  void SaveToFile(string filename);
  // Name - LoadFromFile(string)
  // Desc - For each line in the input file, inserts one line
  //        into the Document
  // Preconditions - Document exists
  // Postconditions - Writes all from file to Document
  void LoadFromFile(string filename);
  // Name - GetLineCount();
  // Desc - Returns m_lineCount
  // Preconditions - Document exists
  // Postconditions - Returns m_lineCount
  int GetLineCount();
 private:
  Line* m_head; //Head (first node) in Document (linked list)
  int m_lineCount; //Count of number of lines in Document
};

#endif
