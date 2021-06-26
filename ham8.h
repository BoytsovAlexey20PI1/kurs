/**
* @file ham8.h
* @author Бойцов А.В.
* @version 1.0
* @date 13.06.2021
* @copyright ИБСТ ПГУ
* @brief Заголовочный файл для модуля hamming8
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/**
* @brief Программа для кодирования-декодирования кода
Хэмминга с длиной информационного слова 8 бит
*/
class Hamming8
{
private:
    vector<int> toBin(int num); // Переводит в двоичную и дополняет до 8 символов
    int toDec(vector<int> vec); // Переводит в десятичную вектор из 8 символов
public:
    vector<int> encode(string text); // Кодирует
    string decode(vector<int> code); // Декодирует
    void print_vec(vector<int> vec); // Печатет вектор
    vector<int> stringToVec(string str); // Переводит строку в вектор
};
/**
* @brief Класс обработки ошибок error_hamming
*/
class error_hamming: public std::invalid_argument
{
public:
    explicit error_hamming (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
    explicit error_hamming (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
