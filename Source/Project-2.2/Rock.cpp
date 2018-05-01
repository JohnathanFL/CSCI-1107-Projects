/*--- Rock.cpp
 *------------------------------------------------------------------ Defines an
 *enum Rock that models rocks of various types, and defines operations for that
 *enum.
 *
 * IMPLEMENTATION.
 *
 * Johnathan Lee				CSCI 1107
 * Lab 4						Due 02/06/18
 *----------------------------------------------------------------------------*/

#include "Rock.h"

#include <iostream>

using namespace std;

Rock nextOne(Rock rockVal) {
   switch (rockVal) {
      case BASALT:
         return DOLOMITE;
      case DOLOMITE:
         return GRANITE;
      case GRANITE:
         return GYPSUM;
      case GYPSUM:
         return LIMESTONE;
      case LIMESTONE:
         return MARBLE;
      case MARBLE:
         return OBSIDIAN;
      case OBSIDIAN:
         return QUARTZITE;
      case QUARTZITE:
         return SANDSTONE;
      case SANDSTONE:
         return SHALE;
      case SHALE:
         return ROCK_OVERFLOW;
      case ROCK_OVERFLOW:
         return ROCK_OVERFLOW;
      default:
         cout << "Invalid rockVal!\n\n";
         return ROCK_OVERFLOW;
   }
}

string kind(Rock rockVal) {
   switch (rockVal) {
      case BASALT:
      case GRANITE:
      case OBSIDIAN:
         return "igneous";
      case DOLOMITE:
      case GYPSUM:
      case LIMESTONE:
      case SANDSTONE:
      case SHALE:
         return "sedimentary";
      case MARBLE:
      case QUARTZITE:
         return "metamorphic";

      case ROCK_OVERFLOW:
         cout << "Rock::ROCK_OVERFLOW has no type!\n\n";
         return "ROCK_OVERFLOW";
      default:
         cout << "Invalid Rock entered!\n\n";
         return "ROCK_OVERFLOW";
         break;
   }
}

ostream &operator<<(ostream &out, Rock rockVal) {
   switch (rockVal) {
      case BASALT:
         out << "Basalt";
         break;
      case DOLOMITE:
         out << "Dolomite";
         break;
      case GRANITE:
         out << "Granite";
         break;
      case GYPSUM:
         out << "Gypsum";
         break;
      case LIMESTONE:
         out << "Limestone";
         break;
      case MARBLE:
         out << "Marble";
         break;
      case OBSIDIAN:
         out << "Obsidian";
         break;
      case QUARTZITE:
         out << "Quartzite";
         break;
      case SANDSTONE:
         out << "Sandstone";
         break;
      case SHALE:
         out << "Shale";
         break;
      case ROCK_OVERFLOW:
         out << "ROCK_OVERFLOW";
         break;
      default:
         out << "ROCK_OVERFLOW";
         break;
   }


   return out;
}

istream &operator>>(istream &in, Rock &rockVal) {
   // Simpler than if...else if...else if...etc
   std::string nameMap[] = {
       "BASALT", "DOLOMITE", "GRANITE",   "GYPSUM",    "LIMESTONE",
       "MARBLE", "OBSIDIAN", "QUARTZITE", "SANDSTONE", "SHALE",
   };

   string buff;
   rockVal = Rock::ROCK_OVERFLOW;  // Assume we can't find it.

   in >> buff;
   // Convert the entire string to uppercase. toupper ignores already uppercase.
   for (int i = 0; i < buff.size(); i++)
      buff[i] = toupper(buff[i]);


   // If this can't find it, it's already ROCK_OVERFLOW
   for (int i = 0; i < ROCK_OVERFLOW; i++)
      if (nameMap[i] == buff)
         rockVal = Rock(i);

   return in;
}
