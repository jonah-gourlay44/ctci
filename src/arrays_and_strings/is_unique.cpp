#include <string>
#include "utils/quick_sort.h"
#include "arrays_and_strings.h"
#include <iostream>

bool isUnique_standard(const std::string& str)
{
    bool found[128] = { false };

    for (int i = 0; i < str.length(); i++)
    {
        if (found[str[i]])
            return false;
        
        found[str[i]] = true;
    }

    return true;
}

bool isUnique_inPlace(const std::string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i+1; j < str.length(); j++)
        {
            if (str[i] == str[j])
                return false;
        }
    }

    return true;
}

bool isUnique_inPlaceSort(std::string& str)
{
    quickSort(&str[0], 0, str.length()-1);

    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == str[i-1]) 
            return false;
    }

    return true;
}

bool isUnique(const std::string& str, const std::string& method)
{
    

    if (method == "standard")
        return isUnique_standard(str);
    else if (method == "in_place")
        return isUnique_inPlace(str);
    else if (method == "in_place_sort")
    {
        std::string str_ref = str;
        return isUnique_inPlaceSort(str_ref);
    }
}