/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** FunctionManager.hpp
*/

#ifndef B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_FUNCTIONMANAGER_HPP
    #define B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_FUNCTIONMANAGER_HPP

    #include <map>
    #include <list>
    #include <string>
    #include "Map.hpp"
    #include "ParseCommands.hpp"

class FunctionManager {
public:
    FunctionManager(); // Constructor initializes the map
    ~FunctionManager() = default;

    void callFunction(std::string, Map&);

    std::map<std::string, void (*)(std::list<std::string> arg, Map &myMap)> getFct() const;
    void setFct(const std::map<std::string, void (*)(std::list<std::string> arg, Map &myMap)> &fct);

    // Functions for each command
    static void msz(std::list<std::string> arg, Map &myMap);
    static void bct(std::list<std::string> arg, Map &myMap); // This functon handle the response of bct and mct
    static void tna(std::list<std::string> arg, Map &myMap);
    static void pnw(std::list<std::string> arg, Map &myMap);
    static void ppo(std::list<std::string> arg, Map &myMap);
    static void plv(std::list<std::string> arg, Map &myMap);
    static void pin(std::list<std::string> arg, Map &myMap);
    static void pex(std::list<std::string> arg, Map &myMap);
    static void pbc(std::list<std::string> arg, Map &myMap);
    static void pic(std::list<std::string> arg, Map &myMap);
    static void pie(std::list<std::string> arg, Map &myMap);
    static void pfk(std::list<std::string> arg, Map &myMap);
    static void pdr(std::list<std::string> arg, Map &myMap);
    static void pgt(std::list<std::string> arg, Map &myMap);
    static void pdi(std::list<std::string> arg, Map &myMap);
    static void enw(std::list<std::string> arg, Map &myMap);
    static void ebo(std::list<std::string> arg, Map &myMap);
    static void edi(std::list<std::string> arg, Map &myMap);
    static void sgt(std::list<std::string> arg, Map &myMap);
    static void seg(std::list<std::string> arg, Map &myMap);
    static void smg(std::list<std::string> arg, Map &myMap);
    static void suc(std::list<std::string> arg, Map &myMap);
    static void sbp(std::list<std::string> arg, Map &myMap);

private:
    std::map<std::string, void (*)(std::list<std::string> arg, Map &myMap)> _fct;
};

#endif //B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_FUNCTIONMANAGER_HPP
