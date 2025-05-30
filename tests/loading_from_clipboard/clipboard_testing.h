#ifndef CLIPBOARD_TESTING_H
#define CLIPBOARD_TESTING_H

#include "../../common/decklist.h"

#include "gtest/gtest.h"

// using std types because qt types aren't understood by gtest (without this you'll get less nice errors)
using CardRows = QVector<std::pair<std::string, int>>;

struct Result
{
    std::string name;
    std::string comments;
    CardRows mainboard;
    CardRows sideboard;

    Result(std::string _name, std::string _comments, CardRows _mainboard, CardRows _sideboard)
        : name(_name), comments(_comments), mainboard(_mainboard), sideboard(_sideboard)
    {
    }
};

void testEmpty(const QString &clipboard);

void testDeck(const QString &clipboard, const Result &result);

#endif // CLIPBOARD_TESTING_H
