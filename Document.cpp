#include "Document.h"

// Document
// Initializes head for Document linked list
Document::Document() {
  m_head = nullptr;
  m_lineCount = 0;
}

// ~Document
// Removes all lines from Document
Document::~Document() {
  Line *curr = m_head;   // current postion in Document

  while (curr != nullptr) {
    // deletes Document head until list is empty
    m_head = curr;
    curr = curr->GetNext();
    delete m_head;
  }

  m_head = nullptr;
  m_lineCount = 0;
}

// InsertLine
// Inserts new Line object with given text at the position in Document
void Document::InsertLine(string text, int position) {
  Line *curr = m_head;             // current position in Document
  Line *newLine = new Line(text);  // line to be inserted in Document
  int counter = 2;                 // position index in Document

  if (m_lineCount == 0) {
    // newLine becomes head if list is empty
    m_head = newLine;
    m_lineCount++;
    return;
  }

  if (position == 1) {
    // sets newLine to first element in Document/head
    newLine->SetNext(m_head);
    m_head = newLine;
    m_lineCount++;
    return;
  }

  while (curr != nullptr) {
    // inserts newLine when position is located
    if (counter == position) {
      // newLine takes current position's pointer
      newLine->SetNext(curr->GetNext());
      // current position points to newLine
      curr->SetNext(newLine);
      m_lineCount++;
      return;
    }

    curr = curr->GetNext();
    counter++;
  }
}

// DeleteLine
// Deletes element of linked list at given position
void Document::DeleteLine(int position) {
  Line *curr = m_head;  // current position in Document
  Line *prev = m_head;  // position before current in Document
  int counter = 1;      // index of current position in Document

  // deletes first line and sets new head
  if (position == 1) {
    m_head = m_head->GetNext();
    delete curr;
    m_lineCount--;
    return;
  }

  while (curr != nullptr) {
    // deletes pointer when position is location
    if (counter == position) {
      // prev points to curr's pointer
      prev->SetNext(curr->GetNext());
      delete curr;
      m_lineCount--;
      return;
    }

    prev = curr;
    curr = curr->GetNext();
    counter++;
  }
}

// EditLine
// Changes the text of an element at the given position within Document
void Document::EditLine(int position, string newText) {
  Line *curr = m_head;   // current position in Document
  int counter = 1;       // index of current position in Document

  while (curr != nullptr) {
    // changes text of pointer once position is found
    if (counter == position) {
      curr->SetText(newText);
      return;
    }

    curr = curr->GetNext();
    counter++;
  }
}

// DisplayDocument
// Outputs each Line with text in Document
void Document::DisplayDocument() {
  Line *curr = m_head;  // current position in Document
  int counter = 1;      // index of current position in Document

  while (curr != nullptr) {
    cout << counter << ": " << curr->GetText() << endl;
    curr = curr->GetNext();
    counter++;
  }
}

// SearchWord
// Outputs lines that include given string as a substring
void Document::SearchWord(string word) {
  Line *curr = m_head;     // current position in Document
  int counter = 1;         // index of current position in Document
  bool foundWord = false;  // indicates whether word is found

  while (curr != nullptr) {
    // outputs that word is found if found in line
    if (curr->GetText().find(word) != string::npos) {
      cout << "Word found in line " << counter
           << ": " << curr->GetText() << endl;
      foundWord = true;
    }

    curr = curr->GetNext();
    counter++;
  }

  // word isn't in Document if foundWord is false
  if (!foundWord)
    cout << "Word was not found in document" << endl;
}


// SaveToFile
// Writes every line in Document to given file
void Document::SaveToFile(string filename) {
  Line *curr = m_head;              // current position in Document
  ofstream outputStream(filename);  // opens up file for writing

  // writes all of Document to file
  while (curr != nullptr) {
    outputStream << curr->GetText() << endl;
    curr = curr->GetNext();
  }

  outputStream.close();
}

// LoadFromFile
// Appends every line in given file to document
void Document::LoadFromFile(string filename) {
  string line;                     // line text in file
  ifstream inputStream(filename);  // opens file for reading

  // inserts every line to end of Document
  while (getline(inputStream, line)) {
    InsertLine(line, m_lineCount + 1);
  }

  inputStream.close();
}


// GetLineCount
// Returns number of lines in Document
int Document::GetLineCount() {
  return m_lineCount;
}
