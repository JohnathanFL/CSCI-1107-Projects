/* Rock.h
 * Defines a Rock class and its operators.
 * Johnathan Lee           CSCI 1107
 */


#ifndef ROCK_H
#define ROCK_H
#include <iostream>
#include <string>

using namespace std;


enum RockName {
   BASALT,
   DOLOMITE,
   GRANITE,
   GYPSUM,
   LIMESTONE,
   MARBLE,
   OBSIDIAN,
   QUARTZITE,
   SANDSTONE,
   SHALE,
   ROCK_OVERFLOW
};

/// \class Rock
/// \brief Essentially a helper wrapper over RockName with more functions.
class Rock {
  public:
   /// \brief Default constructor: Initializes name to RockName::BASALT
   Rock();

   /// \brief Explicit Constructor: Initializes name to given value
   /// @param rockName The RockName to initialize name to.
   Rock(RockName rockName);

   /// \brief Outputs a string with the human readable name of the RockName enum
   /// \param out The stream to output to.
   /// \post The human readable name of 'name' has been output to out
   /// \note The output is ALL LOWERCASE
   void display(ostream& out) const;

   /// \brief Reads in a rock from in, using the human readable name for input.
   /// \param in The stream to read from.
   /// \post This object's name field now contains the RockName referenced by a
   /// human readable string.
   /// \note The string input is simply an insensitive string used in the enum's
   /// name itself. See Rock::rockStrings for exact strings.
   void read(istream& in);

   /// \brief Gives the kind of rock it is.
   /// \returns One of "igneous", "sedimentary", or "metamorphic", depending on
   /// the rock in question.
   /// \note Returns "INVALID_ROCK" if name is out of range or ROCK_OVERFLOW.
   string kind() const;

   /// \brief Gives what texture the rock has.
   /// \returns One of "intermediate", "coarse", or "fine"
   /// \note Returns "INVALID_ROCK" if name is out of range or ROCK_OVERFLOW.
   string texture() const;

   /// \brief Returns the name field directly.
   /// \returns The RockName this->name;
   RockName getName() const;

   /// \brief Sets the this->name field
   /// \post this->name == newName.
   void setName(RockName newName);

   /// \brief Increments this->name to the next RockName by prefix.
   void operator++();
   /// \brief Increments this->name to the next RockName by postfix.
   Rock operator++(int);

  private:
   // For easy conversion from numbers
   const string rockStrings[RockName::ROCK_OVERFLOW + 1] = {
       "basalt",   "dolomite",  "granite",   "gypsum", "limestone",    "marble",
       "obsidian", "quartzite", "sandstone", "shale",  "rock_overflow"};

   RockName name;
};

// Rock operators
/// \brief Sends this Rock's human readable name to an output stream.
/// \param out The stream to send the string to.
/// \param rock The rock to display
/// \post Result of rock.display() has been sent to out.
ostream& operator<<(ostream& out, const Rock& rock);

/// \brief Reads in a value for rock.
/// \param in The input stream to read from
/// \param rock The rock to change.
/// \post rock's rock.read() method has been called on in.
istream& operator>>(istream& in, Rock& rock);

/// \brief Compares 2 Rocks for inequality.
/// \param lhs the left side of the inequality.
/// \param rhs the right side of the inequality.
/// \returns Whether lhs.getName() is < rhs.getName().
bool operator<(const Rock& lhs, const Rock& rhs);

/// \brief Compares 2 Rocks for equality.
/// \param lhs the left side of the inequality.
/// \param rhs the right side of the inequality.
/// \returns Whether lhs.getName() is equal to rhs.getName().
bool operator==(const Rock& lhs, const Rock& rhs);

// RockName operators

/// \brief Outputs a RockName directly, without a Rock object.
/// \param out The stream to output to.
/// \param rock The RockName enum to output.
/// \post Human readable name of rock has been output to out.
ostream& operator<<(ostream& out, const RockName& rock);


#endif  // !ROCK_H
