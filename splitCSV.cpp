#include "splitCSV.hpp"
#define QUANTIDADE_DE_CAMPOS 3

vector<string> splitCSV(string linhaCSV, char separador) /* Foi dada */
{
    vector<string> res;
    char c;
    string campo = "";
    for (int i = 0; i < linhaCSV.size(); ++i)
    {
        c = linhaCSV.at(i);
        if (c == separador)
        {
            res.push_back(campo);
            campo = "";
        }
        else
            campo.append(1, c);
    }
    res.push_back(campo);
    return res;
}
bool populate(string nomeArquivo)
{
    ifstream f(nomeArquivo);
    if (!f.is_open())
        return false;
    string linhaCSV;
    while (getline(f, linhaCSV))
    {
        vector<string> campos = splitCSV(linhaCSV, ';');
        if (campos.size() != QUANTIDADE_DE_CAMPOS)
        {
            f.close();
            return false;
        }
        // adicionar aqui
    }
    f.close();
    return true;
}