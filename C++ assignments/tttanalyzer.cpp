// Copyright 2021 Pingcheng Dong pingchen@bu.edu
// Copyright 2021 Zhaowen Zhou zzwzhou@bu.edu
// Copyright 2021 Shuyi Fan shuyifan@bu.edu

#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "movedef.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

char tttresult(string tttboard) {
  if (tttboard.length() != 9) return'e';
  for (int i = 0; i < 9; i++) {
    if ((tttboard.at(i) != 'x') && (tttboard.at(i) != 'o')\
        && (tttboard.at(i) != '#')) return 'e';
  }
  int countwin = 0, countwinx = 0, countwino = 0;
  for (int i = 0; i < 7; i = i + 3) {
    if (tttboard.at(i) == tttboard.at(i + 1)\
        && tttboard.at(i) == tttboard.at(i + 2)) {
      if (tttboard.at(i) != '#') countwin++;
      if (tttboard.at(i) == 'x') countwinx++;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (tttboard.at(i) == tttboard.at(i + 3)\
        && tttboard.at(i + 3) == tttboard.at(i + 6)) {
      if (tttboard.at(i) != '#') countwin++;
      if (tttboard.at(i) == 'x') countwinx++;
    }
  }
  if (tttboard.at(0) == tttboard.at(4)\
      && tttboard.at(4) == tttboard.at(8)) {
    if (tttboard.at(0) != '#') countwin++;
    if (tttboard.at(0) == 'x') countwinx++;
  }
  if (tttboard.at(2) == tttboard.at(4)\
      && tttboard.at(4) == tttboard.at(6)) {
    if (tttboard.at(2) != '#') countwin++;
    if (tttboard.at(2) == 'x') countwinx++;
  }
  countwino = countwin - countwinx;
  int indexx = 0, countx = 0, indexo  = 0, counto = 0;
  while ((indexx = tttboard.find("x", indexx)) < tttboard.length()) {
    countx++;
    indexx++;
  }
  while ( (indexo = tttboard.find("o", indexo)) < tttboard.length() ) {
    counto++;
    indexo++;
  }
  if (countx - counto > 1 || counto - countx > 0) return 'i';
  if (countwin > 1) {
    if ((countwinx == 2 && countx == 5) ||
        (countwino == 2 && counto == 5)) {} else {
      return'i';
    }
  }
  if (countwinx > 0) {
    if (countx > counto) return'x';
    return'i';
  }
  if (countwino > 0) {
    if (countx > counto) return'i';
    return'o';
  }
  string::size_type position;
  position = tttboard.find("#");
  if (position == tttboard.npos) return't';
  return'c';
}


char tttresult(vector<Move> board) {
  string s = "#########";
  char former_player = '#';
  for (int i = 0; i < board.size(); i++) {
    if (board.at(i).r > 3 ||
        board.at(i).c > 3 ||
        (board.at(i).player != 'x' &&
         board.at(i).player != 'o')) return 'e';
    if (board.at(0).player == 'o') return 'i';
    if (former_player == board.at(i).player) return 'i';
    s.at(board.at(i).r * 3 + board.at(i).c) = board.at(i).player;
    former_player = board.at(i).player;
  }
  return tttresult(s);
}

vector<string> get_all_boards() {
  vector<string> boards;
  for (int i = 0; i < 19683; ++i) {
    string temp = "#########";
    int j = 0, c = i;
    while (c > 0) {
      switch (c % 3) {
      case 0:
        break;
      case 1:
        temp.at(j) = 'x';
        break;
      case 2:
        temp.at(j) = 'o';
        break;
      }
      j++;
      c /= 3;
    }
    boards.push_back(temp);
  }
  return boards;
}

void ttt_tally() {
  string keys = "toxic";
  std::map <char, int> tally;
  for (auto i = keys.begin(); i != keys.end(); ++i)\
    tally.insert(std::pair<char, int>(*i, 0));
  vector<string> all_boards = get_all_boards();
  for (auto i = all_boards.begin(); i != all_boards.end(); ++i) {
    char result = tttresult(*i);
    tally.at(result) += 1;
  }
  for (auto i = tally.begin(); i != tally.end(); ++i)\
    cout << i->first << " " << i->second << "\n";
}

// MAIN
