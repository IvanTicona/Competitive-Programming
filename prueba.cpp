#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

int min_operations_to_match_strings(const string& a, const string& b) {
    unordered_map<char, int> count_a, count_b;
    
    // Contar la frecuencia de cada letra en ambas cadenas
    for (char ch : a) {
        count_a[ch]++;
    }
    for (char ch : b) {
        count_b[ch]++;
    }
    
    // Calcular la diferencia total de frecuencias
    int total_operations = 0;
    for (const auto& pair : count_a) {
        char letter = pair.first;
        total_operations += abs(pair.second - count_b[letter]);
    }
    
    return total_operations;
}

int main() {
    string a = "abcdef";
    string b = "azcedf";
    
    cout << "El número mínimo de operaciones necesarias es: " 
         << min_operations_to_match_strings(a, b) << endl;
    
    return 0;
}
