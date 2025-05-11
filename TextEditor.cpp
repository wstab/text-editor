#include "TextEditor.h"

// TextEditor
// Creates empty Document and initializes empty file name
TextEditor::TextEditor() {
  m_fileName = "";
  Document m_editor;
}

// MainMenu
// Returns index of user choice for how to proceed
int TextEditor::MainMenu() {
  int choice = 0; // user choice

  // prompts user to make choice until valid index is input
  do {
    cout << endl;
    cout << "--- Simple Text Editor ---" << endl;
    cout << "1. Insert Line" << endl;
    cout << "2. Delete Line" << endl;
    cout << "3. Edit Line" << endl;
    cout << "4. Display Document" << endl;
    cout << "5. Search Word" << endl;
    cout << "6. Save to File" << endl;
    cout << "7. Load from File" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";

    cin >> choice;

    cout << endl;

    // clear input buffer
    if (cin.peek() == '\n')
      cin.ignore(256, '\n');
  } while (choice < 1 and choice > 8);

  return choice;
}

// GetLineNumber
// Returns index for line once user provides correct input
int TextEditor::GetLineNumber(bool isExact) {
  int lineNum; // line number

  // line must be in Document
  if (isExact) {
    do {
      m_editor.DisplayDocument();
      cout << "Enter line number:" << endl;
      cin >> lineNum;
      if (lineNum < 1 or lineNum > m_editor.GetLineCount())
        cout << "Must be between 1 and " << m_editor.GetLineCount() << endl;
    } while(lineNum < 1 or lineNum > m_editor.GetLineCount());

  } else {
  // line can be greater than number of lines by 1
    do {
      m_editor.DisplayDocument();
      cout << "Enter line number:" << endl;
      cin >> lineNum;
      if (lineNum < 1 or lineNum > m_editor.GetLineCount() + 1)
        cout << "Must be between 1 and " << m_editor.GetLineCount() + 1 << endl;
    } while(lineNum < 1 or lineNum > (m_editor.GetLineCount() + 1));
  }
  cout << endl;

  // clear input buffer
  if (cin.peek() == '\n')
      cin.ignore(256, '\n');

  return lineNum;
}

// GetFileName
// Returns file name provided by user
string TextEditor::GetFileName() {
  cout << "Enter the file name:" << endl;
  getline(cin, m_fileName);
  return m_fileName;
}

// Start
// Main loop; manages all methods
void TextEditor::Start() {
  bool quit = false;  // exit case

  do {
    switch(MainMenu()) {
    // 1. Insert Line
    case 1:
      InsertLine();
      break;
    // 2. Delete Line
    case 2:
      DeleteLine();
      break;
    // 3. Edit Line
    case 3:
      EditLine();
      break;
    // 4. Display Document
    case 4:
      m_editor.DisplayDocument();
      break;
    // 5. Search Word
    case 5:
      SearchDocument();
      break;
    // 6. Save to File
    case 6:
      SaveFile();
      break;
    // 7. Load From File
    case 7:
      LoadFile();
      break;
    // 8. Exit
    case 8:
      cout << "Thank you for using the UMBC Text Editor" << endl;
      quit = true;
      break;
    }
  } while(!quit);
}

// InsertLine
// Prompts user for text/position and inserts into Document
void TextEditor::InsertLine () {
  string text = ""; // user text input
  int lineNum;

  cout << "**Insert Line**" << endl;
  cout << "Inserts line before chosen line number" << endl;

  // prompt for line number only if Document is populated
  if (m_editor.GetLineCount()) {
  // line index doesn't have to be exact
    lineNum = GetLineNumber(false);
  } else {
    lineNum = 1;
  }

  cout << "Enter text: ";
  getline(cin, text);

  m_editor.InsertLine(text, lineNum);
}

// DeleteLine
// Deletes line at position given by user unless Document is empty
void TextEditor::DeleteLine () {
  if (m_editor.GetLineCount()) {
    cout << "**DeleteLine**" << endl;
    // line has to be exact
    m_editor.DeleteLine(GetLineNumber(true));
    return;
  }
  cout << "Document is empty" << endl;
}

// EditLine
// Prompts user for text/position and edits line in Document
void TextEditor::EditLine() {
  string text = ""; // user text input
  int lineNum;

  if (m_editor.GetLineCount()) {
    cout << "**Edit Line**" << endl;

    lineNum = GetLineNumber(true);

    cout << "Enter text: ";
    getline(cin, text);
    // line must be exact
    m_editor.EditLine(lineNum, text);
    return;
  }
  cout << "Document is empty" << endl;
}

// SearchDocument
// Prompts user for word and outputs if found in Document unless Document is empty
void TextEditor::SearchDocument() {
  string word = ""; // substring to search for
  if (m_editor.GetLineCount()) {
    cout << "**Search Document**" << endl;
    cout << "Enter word to search:" << endl;
    getline(cin, word);

    cout << endl;

    m_editor.SearchWord(word);
    return;
  }
  cout << "Document is empty" << endl;
}

// LoadFile
// Prompts user for file name and appends all contents to Document
void TextEditor::LoadFile() {
  cout << "**Load File**" << endl;
  m_editor.LoadFromFile(GetFileName());
}

// SaveFile
// Prompts user for file name and writes every line in Document to File
void TextEditor::SaveFile() {
  cout << "**Save File**" << endl;
  m_editor.SaveToFile(GetFileName());
}
