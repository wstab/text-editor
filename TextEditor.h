#include "Document.h"
#include <iostream>
#include <string>
using namespace std;

class TextEditor{
 public:
  // Name - TextEditor - default constructor
  // Desc - Set m_fileName to empty
  // Preconditions - None
  // Postconditions - Set m_fileName to empty. Creates document (m_editor)
  TextEditor();
  // Name - MainMenu
  // Desc - Displays options:
  //        1. Insert Line, 2. Delete Line, 3. Edit Line, 4. Display Document
  //        5. Search Word, 6. Save to File, 7. Load from File, 8. Exit
  // Preconditions - None
  // Postconditions - Returns valid choice (1-8)
  int MainMenu();
  // Name - GetLineNumber
  // Desc - Allows user to choose a specific line number from document.
  //        For functions such as DeleteLine and EditLine, the line number must be exact
  //            (between 1 and the number of lines in the document)
  //        For InsertLine, the line must be between 1 and the number of lines + 1
  // Preconditions - Document (m_editor) exists
  // Postconditions - Returns line chosen
  int GetLineNumber(bool isExact);
  // Name - GetFileName
  // Desc - Prompts user for file name. Stores in m_fileName
  // Preconditions - None
  // Postconditions - Returns file name entered
  string GetFileName();
  // Name - Start
  // Desc - Calls MainMenu. Takes menu response and uses switch statement to
  //        call corresponding function (display just calls DisplayDocument)
  //        Keeps calling until user enters 8 (quit).
  // Preconditions - None
  // Postconditions - Keeps asking user what to do until they enter 8 (quit).
  void Start();
  // Name - InsertLine
  // Desc - Inserts a new line into the document(m_editor). Asks user where to
  //        insert the new line by calling GetLineNumber. Inserts the new line before
  //        the line chosen.
  // Preconditions - None
  // Postconditions - Inserts line into document (m_editor).
  void InsertLine();
  // Name - DeleteLine
  // Desc - Checks to make sure the document(m_editor) has lines. If it does,
  //        calls GetLineNumber. Then deletes line from document.
  // Preconditions - Document has at least one line.
  // Postconditions - Removes line from document (m_editor).
  void DeleteLine();
  // Name - EditLine
  // Desc - Checks to make sure the document(m_editor) has lines. If it does,
  //        calls GetLineNumber. Updates the text in the chosen line.
  // Preconditions - Document has at least one line.
  // Postconditions - Updates line from document (m_editor).
  void EditLine();
  // Name - SearchDocument
  // Desc - Checks to make sure the document(m_editor) has lines. If it does,
  //        asks user which text to search for. Displays all lines that have
  //        the matching text.
  // Preconditions - Document has at least one line.
  // Postconditions - Displays line from document (m_editor).
  void SearchDocument();
  // Name - LoadFile
  // Desc - Asks user for the file name. Opens file. Inserts lines from file
  //        into existing document (m_editor). Appends document (m_editor).
  // Preconditions - None
  // Postconditions - Inserts text from file into document (m_editor).
  void LoadFile();
  // Name - SaveFile
  // Desc - Asks user for the file name. Opens file. Writes out all lines from
  //        document (m_editor) to the file.
  // Preconditions - None
  // Postconditions - Inserts text from document (m_editor) into file.
  void SaveFile();
private:
  Document m_editor; //Document
  string m_fileName; //Name of file
};
