#pragma once

#include <optional>
#include <ostream>
#include <vector>

enum class Field : unsigned int { X = 1, O };

class OutOfBoundsException : public std::exception {};

class Position {
  int i;
  int j;

 public:
  Position(int i, int j);
  int get_i() const;
  int get_j() const;

  friend std::ostream& operator<<(std::ostream& os, const Position& pos);
};

class Board {
  std::vector<std::vector<std::optional<Field>>> _board;

 public:
  Board();
  void set_field(const Position& pos, Field);
  std::optional<Field> get_field(const Position& pos) const;
  std::vector<Position> get_empty_fields();
  std::optional<Field> get_winner();

  friend std::ostream& operator<<(std::ostream& os, const Board& board);
  friend bool operator==(const Board& lhs, const Board& rhs);
};

std::ostream& operator<<(std::ostream& os, std::optional<Field> field);

namespace std {
template <>
struct hash<Board> {
  std::size_t operator()(Board const& board) const noexcept;
};
};  // namespace std