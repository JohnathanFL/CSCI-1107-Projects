/// \file Project-7-2-Part2.cpp
/// \brief Testing operations on CircularQ, as well as a student class.
/// \author Johnathan Lee for CSCI 1107, Project 7.2
/// \date 04/10/18
///
/// \note Code is organized as follows:
/// INCLUDES
/// NAMESPACES
/// CLASS DECS (This part has the docs)
/// FUNCTION PROTOS (This part has the docs)
/// MAIN DRIVER
/// FUNCTION DEFS
/// CLASS DEFS

#include <iostream>
#include <sstream>
#include <string>

#include "circq.h"

using namespace std;


/// \class Student
/// \brief A class to contain student information.
class Student {
  public:
   /// \brief Default and explicit constructor
   /// \param theID The student's ID number
   /// \param theName The student's name, first and last.
   Student(int theID = 0, string theName = "");

   /// \brief Getter for this->id.
   /// \post No special post conditions
   int getID() const;

   /// \brief Setter for this->id
   /// \post No special post conditions beyond setting id.
   void setID(int theID);

   /// \brief Getter for this->name.
   /// \post No special post conditions
   string getName() const;
   /// \brief Setter for this->name
   /// \post No special post conditions beyond setting name
   void setName(string theName);


   /// \brief Display this student as a string
   /// \param out The stream to write to.
   /// \post *this is written to out in the format #<this->id> (<this->name>)
   void display(ostream& out) const;

   /// \brief Set this student's values to those contained in a stream.
   /// \param in The stream to read from
   /// \post *this contains values from in that were in the format ID FIRST_NAME
   /// LAST_NAME
   /// \note Takes in 2 words for the name, in format FIRST LAST
   void parse(istream& in);

  private:
   int    id;    ///>! The student ID, typically > 0
   string name;  ///>! The student's first and last name.
};

/// \brief Input a student
/// \param in Stream to read from
/// \param student Student to parse into
/// \post Consumed characters from in; Student contains information found in in.
istream& operator>>(istream& in, Student& student);

/// \brief Output a student
/// \param out Stream to write to
/// \param student Student to output
/// \post Student info has been output. See Student::display for more info.
ostream& operator<<(ostream& out, const Student& student);


/// \brief Join 2 circular queues.
/// \tparam T the type shared by both CircularQ's
/// \param first The first queue
/// \param second The second queue
/// \returns A queue containing all elements of first followed by all of second.
template <typename T>
CircularQ<T> join(CircularQ<T> first, CircularQ<T> second);

int main() {
   // Note: I have put comments denoting each section in the lab manual.

   // 1.a
   CircularQ<double> qdub1, qdub2, qdub;
   CircularQ<string> qstr;
   qstr.enqueue("a few strings of your choosing");
   qstr.enqueue("a string not of your choosing.");
   qstr.enqueue("COBOL is the bane of all.");
   qstr.enqueue("And Java isn't much better");


   for (int i = 0; i < 10; i++)
      qdub1.enqueue(i * 1.1);


   cout << "Please enter 5 double values for qdub2, space delimited: ";
   for (int i = 0; i < 5; i++) {
      double qEl;
      cin >> qEl;
      qdub2.enqueue(qEl);
   }

   // 1.b
   cout << "qdub1: " << qdub1 << endl << "qdub2: " << qdub2 << endl;

   // 2
   qdub = join(qdub1, qdub2);
   cout << qdub;

   // 3
   CircularQ<Student> studentQueue;

   int numStudents = 0;
   cout << "\nHow many students do you want to enter? ";
   cin >> numStudents;
   cout << "Alright, enter them in the form 'ID FIRST_NAME LAST_NAME':\n";
   for (int i = 0; i < numStudents; i++) {
      Student newStudent;
      cin >> newStudent;
      studentQueue.enqueue(newStudent);
   }

   cout << "StudentQueue: " << studentQueue;

   // 4
   CircularQ<Student*> qptr;
   CircularQ<Student>  studentCopy = studentQueue;
   while (!studentCopy.empty()) {
      qptr.enqueue(new Student(studentCopy.front()));
      studentCopy.dequeue();
   }
   cout << "\nqptr pointers: " << qptr;
   cout << "\nqptr contents: ";
   while (!qptr.empty()) {
      cout << *qptr.front();
      qptr.dequeue();
   }

   // 5
   CircularQ<CircularQ<double>> qq;
   qq.enqueue(qdub1);
   qq.enqueue(qdub2);
   qq.enqueue(qdub);

   cout << "\nContents of qq: " << qq << endl;
}

template <typename T>
CircularQ<T> join(CircularQ<T> first, CircularQ<T> second) {
   // DEBUG: cout << endl << "joining " << first << " with " << second << endl;
   while (!second.empty()) {
      first.enqueue(second.front());
      second.dequeue();
   }

   return first;
}

// Student methods and helper funcs:
ostream& operator<<(ostream& out, const Student& student) {
   student.display(out);
}

istream& operator>>(istream& in, Student& student) {
   student.parse(in);
}

Student::Student(int theID, string theName) {
   id   = theID;
   name = theName;
}

int Student::getID() const {
   return id;
}

void Student::setID(int theID) {
   id = theID;
}

string Student::getName() const {
   return name;
}

void Student::setName(string theName) {
   name = theName;
}

void Student::display(ostream& out) const {
   // I.E "Student #12345 (Johnathan Lee)"
   out << "Student #" << id << " (" << name << ") ";
}

void Student::parse(istream& in) {
   string lastName;
   in >> id >> name >> lastName;
   name = name + " " + lastName;
}
