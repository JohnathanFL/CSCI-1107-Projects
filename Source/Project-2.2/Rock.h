/*--- Rock.h ------------------------------------------------------------------
 * Defines an enum Rock that models rocks of various types, and defines
 * operations for that enum.
 *
 * Johnathan Lee				CSCI 1107
 * Lab 4						Due 02/06/18
 *----------------------------------------------------------------------------*/
#ifndef ROCK_H
#define ROCK_H

#include <string>

using namespace std;

enum Rock {
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

/// \brief Increments a rock value to the next rock in order.
/// \param rockVal The Rock to increment.
/// \returns The next Rock in the chain (Basalt->Dolomite, etc)
/// \note Incrementing Rock::ROCK_OVERFLOW returns Rock::ROCK_OVERFLOW.
Rock nextOne(Rock rockVal);


/// \brief Gives the kind (igneous, metamorphic, or sedimentary) of the rock
/// input. \param rockVal The rock whose type should be returned \returns A
/// string containing one of "igneous", "metamorphic", "sedimentary", or
/// "ROCK_OVERFLOW". \note "ROCK_OVERFLOW" is returned for an input of
/// Rock::ROCK_OVERFLOW or an invalid
///   rock type.
string kind(Rock rockVal);


/// \brief Overloads the << operator for Rock on output streams.
/// \param out The ostream we write to.
/// \param rockVal The rock whose name should be printed.
/// \post The user-friendly name of the rock has been written to out
/// \returns A reference back to the ostream for chaining.
/// \note Writes "ROCK_OVERFLOW" to out if rockVal is invalid.
ostream& operator<<(ostream& out, Rock rockVal);


/// \brief Overloads the >> operator for Rock on input streams.
/// \param in The istream to read from
/// \param rockVal the rock to store the value in.
/// \returns A reference to the in stream for chaining.
/// \note Sets rockVal to Rock::ROCK_OVERFLOW if invalid input.
istream& operator>>(istream& in, Rock& rockVal);
#endif
