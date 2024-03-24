template <typename T>
int busquedaBinaria(vector<T>& vec, string& nombre) {
    int inicio = 0;
    int fin = vec.size() - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (vec[medio].nombre == nombre){
            return medio;}
            
        if (vec[medio].nombre > nombre){
            fin = medio - 1;}

        else{
            inicio = medio + 1;}
    }


}

int main() {
    vector<Parque> parques = {{"Parque A"}, {"Parque B"}, {"Parque C"}, {"Parque D"}, {"Parque E"}};
    sort(parques.begin(), parques.end(), compararPorNombre);

    string nombreBuscado = "Parque D";
    int indice = busquedaBinaria(parques, nombreBuscado);

   
    if (indice != -1){
        cout << "El parque "" << nombreBuscado << "" se encuentra en la posición " << indice <<endl;}
    else{
        cout << "El parque "" << nombreBuscado << "" no se encontró." <<endl;}

    return 0;
}
