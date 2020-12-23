#ifndef INPUT_H
#define INPUT_H

#include "Action.h"
#include <string>

/// \brief Contains all informations related to user Input.

/// \class Input Input.h <Input.h>
class Input {
 public:
  /// \brief Class constructor
  Input();

  /// \brief gets Input from the user and checks if it's valid then
  /// returns the valid string.
  std::string getInput();

  /// \brief checks Input from the user returns true/false for validity
  /// \param[in] in string
  bool checkValid(std::string in);

  /// \brief prints help for user inputs
  void help();
};
#endif
