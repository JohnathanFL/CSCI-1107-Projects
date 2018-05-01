/* Rock.cpp
 * Implementation file for the Rock class and its methods and operators.
 * Johnathan Lee           CSCI 1107
 */

#include "Rock.h"

#include <sstream>

Rock::Rock() {
   name = RockName::BASALT;
}

Rock::Rock(RockName rockName) {
   // cout << "Rock Constructor\n";
   name = rockName;
}

void Rock::display(ostream& out) const {
   out << rockStrings[name];
}


ostream& operator<<(ostream& out, const Rock& rock) {
   rock.display(out);
   return out;
}

void Rock::read(istream& in) {
   string buffer;
   name = RockName::ROCK_OVERFLOW;  // Assume the user's stupid and doesn't
                                    // input correctly.

   // Get the input itself
   in >> buffer;

   // Move to a lowercase string for comparisons.
   for (char& ch : buffer)
      ch = tolower(ch);

   // Just compare against all the strings we use for output, since that has all
   // cases.
   for (int i = 0;
        i < RockName::ROCK_OVERFLOW + 1 && name == RockName::ROCK_OVERFLOW; i++)
      if (buffer == rockStrings[i])
         name = RockName(i);
}

istream& operator>>(istream& in, Rock& rock) {
   rock.read(in);
   return in;
}

string Rock::kind() const {
   switch (name) {
      case BASALT:
      case OBSIDIAN:
      case GRANITE:
         return "igneous";

      case SANDSTONE:
      case SHALE:
      case DOLOMITE:
      case GYPSUM:
      case LIMESTONE:
         return "sedimentary";
         break;

      case MARBLE:
      case QUARTZITE:
         return "metamorphic";


      case ROCK_OVERFLOW:
      default:
         return "INVALID ROCK";
   }
}

string Rock::texture() const {
   switch (name) {
      case BASALT:

      case QUARTZITE:
         return "intermediate";

      case DOLOMITE:

      case GRANITE:

      case GYPSUM:

      case LIMESTONE:

      case SANDSTONE:
         return "coarse";


      case MARBLE:

      case OBSIDIAN:
      case SHALE:
         return "fine";

      case ROCK_OVERFLOW:
      default:
         return "INVALID ROCK";
   }
}

RockName Rock::getName() const {
   return name;
}

void Rock::setName(RockName newName) {
   name = newName;
}

// PRE-fix
void Rock::operator++() {
   name = RockName(static_cast<int>(name) + 1);
}

// POST-fix
Rock Rock::operator++(int) {
   // Since we're incrementing AFTER it's evaluated, we must return something
   // other than ourselves.
   Rock unchanged;
   name = ((*this)++).getName();
   return unchanged;
}

ostream& operator<<(ostream& out, const RockName& rock) {
   switch (rock) {
      case BASALT:
         out << "basalt";
         break;
      case QUARTZITE:
         out << "quartzite";
         break;
      case DOLOMITE:
         out << "dolomite";
         break;
      case GRANITE:
         out << "granite";
         break;
      case GYPSUM:
         out << "gypsum";
         break;
      case LIMESTONE:
         out << "limestone";
         break;
      case SANDSTONE:
         out << "sandstone";
         break;
      case MARBLE:
         out << "marble";
         break;
      case OBSIDIAN:
         out << "obsidian";
         break;
      case SHALE:
         out << "shale";
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

bool operator<(const Rock& lhs, const Rock& rhs) {
   return lhs.getName() < rhs.getName();
}

bool operator==(const Rock& lhs, const Rock& rhs) {
   return lhs.getName() == rhs.getName();
}
