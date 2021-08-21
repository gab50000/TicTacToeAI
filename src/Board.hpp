#pragma once

#include <vector>

enum class Field { Empty, X, O };

class Board {
  std::vector<std::vector<Field>> _board;
}