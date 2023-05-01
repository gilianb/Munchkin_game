//
// Created by gigib on 13/06/2022.
//

#ifndef MATAMHW4_EXCEPTION_H
#define MATAMHW4_EXCEPTION_H

#include <exception>

//----------------------------------------Deck File Exceptions--------------------------------------------------//


class DeckFileNotFound : public std::runtime_error{
public:
    DeckFileNotFound() :std::runtime_error("Deck File Error: File not found"){}
};


class DeckFileFormatError : public std::runtime_error{
public:
    DeckFileFormatError(int line) :  std::runtime_error("Deck File Error: File format error in line " + std::to_string(line)) {}
};


class DeckFileInvalidSize : public std::runtime_error{
public:
    DeckFileInvalidSize() :std::runtime_error("Deck File Error: Deck size is invalid") {}
};


#endif //MATAMHW4_EXCEPTION_H