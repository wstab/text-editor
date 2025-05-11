#include "Line.h"

// Line
// Creates empty Line object
Line::Line() {
  m_text = "";
  m_next = nullptr;
}

// Line(string)
// Creates Line with string and no pointer
Line::Line(string text) {
  m_text = text;
  m_next = nullptr;
}

// GetText
// Returns text in Line object
string Line::GetText() {
  return m_text;
}

// GetNext
// Returns pointer stored in Line object
Line* Line::GetNext() {
  return m_next;
}

// SetText
// Edits text stored in Line object given string
void Line::SetText(string text) {
  m_text = text;
}


// SetNext
// Edits pointer stored in Line object given another Line object
void Line::SetNext(Line* next) {
  m_next = next;
}
